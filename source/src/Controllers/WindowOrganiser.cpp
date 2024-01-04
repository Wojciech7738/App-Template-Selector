#include "Controllers/WindowOrganiser.h"

WindowOrganiser::WindowOrganiser()
{

}

WindowOrganiser::~WindowOrganiser()
{

}

void WindowOrganiser::run(int argc, char** argv) {
    QApplication app(argc, argv); // TODO: hide it
    std::string selected_language;
    // Read directory and create JSON file
    std::unique_ptr<IJsonReaderWriter<std::string>> json_reader_writer = ReaderWriterFactory::createJsonReaderWriter("languages");
    std::vector<std::string> languages = json_reader_writer->scan_directory("Templates");
    app.exit();
    if (languages.empty())
        return;

    // Display the programming language selection window
    selected_language = show_lang_select_window("prog_lang_select_window", "Choose a programming language", languages, argc, argv);
    if (selected_language != "") {
        // Scan directory of given programming language and return vector of tuples indicating the templates and their subdirectories/files
        std::unique_ptr<IJsonReaderWriter<std::tuple<std::string, std::vector<std::string>>>> lang_path_scanner = ReaderWriterFactory::createTemplateScanner(selected_language + "_contents");
        auto dir_contents = lang_path_scanner->scan_directory(selected_language);
        // Show main window
        show_main_window("main_window", "Select template", argc, argv, selected_language + " templates", dir_contents);
    }
}

std::string WindowOrganiser::show_lang_select_window(const std::string& window_name, const std::string& window_title, std::vector<std::string> languages, int argc, char** argv)
{
    QApplication a(argc, argv);
    Widget w;
    QVBoxLayout* l = w.create_buttons_from_vector(languages);
    w.setLayout(l);
    w.show();
    a.exec();
    return w.selected_language;
}

void WindowOrganiser::show_main_window(const std::string& window_name, const std::string& window_title, int argc, char** argv, std::string selected_language,
                                       std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.write_data(dir_contents);
    w.show();
    a.exec();
}
