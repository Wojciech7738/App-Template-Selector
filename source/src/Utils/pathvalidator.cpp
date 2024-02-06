#include "Utils/pathvalidator.h"
#include "Utils/globals.h"

void pathValidator::display_error_message(std::string message_string) {
    QApplication a(Argc, Argv);
    QWidget w;
    QString error_message = QString::fromStdString(message_string);
    QMessageBox::critical(&w, "Error", error_message);
    a.exit(0);
}

bool pathValidator::validate_prog_lang_dir(std::string directory) {
    QFileInfo fileInfo(QString::fromStdString(directory));
    if (!fileInfo.exists()) {
        display_error_message(ERR_DIR_NOT_EXISTS(directory));
        return false;
    }
    return true;
}

bool pathValidator::validate_prog_lang_dir_contents(std::string directory, std::vector<std::string> langs) {
    for (const auto& filename : langs) {
        std::string path = directory + PATH_SEP + filename;
        if (fs::exists(path) && fs::is_regular_file(path)) {
            display_error_message(ERR_DIR_CONTAINS_FILES(directory));
            return false;
        }
    }
    return true;
}

// Checks if filepath for .json configuration file exists.
bool pathValidator::configuration_file_exists() {
    return fs::exists(CONFIG_PATH + ".json") && fs::exists(CONFIG_PATH + "_only.json");
}
