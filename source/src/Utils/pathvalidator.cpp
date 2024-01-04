#include "Utils/pathvalidator.h"

void PathValidator::display_error_message(std::string message_string) {
    QString error_message = QString::fromStdString(message_string);
    QMessageBox::critical(nullptr, "Error", error_message);
}

bool PathValidator::validate_prog_lang_dir(std::string directory) {
    QFileInfo fileInfo(QString::fromStdString(directory));
    if (!fileInfo.exists()) {
        display_error_message(ERR_DIR_NOT_EXISTS(directory));
        return false;
    }
    return true;
}

bool PathValidator::validate_prog_lang_dir_contents(std::string directory, std::vector<std::string> langs) {
    for (const auto& filename : langs) {
        std::string path = directory + PATH_SEP + filename;
        if (fs::exists(path) && fs::is_regular_file(path)) {
            display_error_message(ERR_DIR_CONTAINS_FILES(directory));
            return false;
        }
    }
    return true;
}
