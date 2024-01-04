#ifndef PATHVALIDATOR_H
#define PATHVALIDATOR_H

#include <vector>
#include <string>
#include <QFileInfo>
#include <QMessageBox>
#include <filesystem>
#include "Utils/errormacros.h"
#include "Utils/macros.h"

namespace fs = std::filesystem;

// TODO: refactor to match Observer pattern

class PathValidator
{
public:
    void display_error_message(std::string path);
    bool validate_prog_lang_dir(std::string directory);
    bool validate_prog_lang_dir_contents(std::string directory, std::vector<std::string> langs);
};

#endif // PATHVALIDATOR_H
