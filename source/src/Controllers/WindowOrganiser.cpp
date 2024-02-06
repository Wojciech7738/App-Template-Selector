#include "Controllers/WindowOrganiser.h"

WindowOrganiser::WindowOrganiser()
{

}

WindowOrganiser::~WindowOrganiser()
{

}

int WindowOrganiser::scan_for_templates() {
    std::unique_ptr<IJsonReaderWriter<std::string, std::string>> json_reader_writer = ReaderWriterFactory::createJsonReaderWriter(PURE_CONFIG_FILE_NAME);
    std::unique_ptr<IJsonReaderWriter<std::tuple<std::string, std::vector<std::string>>,
            std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>>> lang_path_scanner = ReaderWriterFactory::createTemplateScanner(CONFIG_FILE_NAME);
    if (!pathValidator::configuration_file_exists()){
        if (!json_reader_writer->create_json_file())
            // If there is no way to create configuration file - exit
            return 1;
        languages = json_reader_writer->scan_directory("Templates");
        if (languages.empty())
            return 1;
        json_reader_writer->write_to_json_file(languages);
        // For each language write a contents of every language directory
        for (const std::string& selected_language : languages) {
            // Scan directory of given programming language and return vector of tuples indicating the templates and their subdirectories/files
            auto dir_contents = lang_path_scanner->scan_directory(selected_language);
            languages_tree.push_back(std::make_tuple(selected_language, dir_contents));
        }
        lang_path_scanner->write_to_json_file(languages_tree);
    }
    else {
        languages = json_reader_writer->read_json_file();
        languages_tree = lang_path_scanner->read_json_file();
        if (languages.empty() || languages_tree.empty())
            return 1;
    }
    return 0;
}

void WindowOrganiser::show_Gui() {
    // Display the programming language selection window
    std::string selected_language = show_lang_select_window("prog_lang_select_window", "Choose a programming language", languages);
    if (selected_language.compare("")) {
        auto dir_contents = get_dir_contents(selected_language);
        if (dir_contents.empty()) {
            pathValidator::display_error_message(ERR_TEMPLATES_NOT_FOUND(selected_language));
            return;
        }
        // Show main window
        show_main_window("main_window", "Select template", selected_language + " templates", dir_contents);
    }
}

std::vector<std::tuple<std::string, std::vector<std::string>>> WindowOrganiser::get_dir_contents(const std::string& lang) {
    std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents;
    for (const auto& language_entry : languages_tree) {
        if (std::get<0>(language_entry) == lang) {
            // Return directory contents
            dir_contents = std::get<1>(language_entry);
            break;
        }
    }
    return dir_contents;
}

std::string WindowOrganiser::show_lang_select_window(const std::string& window_name, const std::string& window_title, std::vector<std::string> languages)
{
    QApplication a(Argc, Argv);
    Widget w;
    QVBoxLayout* l = w.create_buttons_from_vector(languages);
    w.setLayout(l);
    w.show();
    a.exec();
    return w.selected_language;
}

void WindowOrganiser::show_main_window(const std::string& window_name, const std::string& window_title, std::string selected_language,
                                       std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents)
{
    QApplication a(Argc, Argv);
    MainWindow w;
    w.write_data(dir_contents);
    w.show();
    a.exec();
}
