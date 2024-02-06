#ifndef TEMPLATESCANNER_H
#define TEMPLATESCANNER_H

#pragma once

#include <filesystem>
#include <tuple>
#include "json.hpp"
#include "Utils/pathvalidator.h"
#include "Utils/errormacros.h"
#include "IJsonReaderWriter.h"

namespace fs = std::filesystem;
using json=nlohmann::json;

/* A class for scanning the app templates of given programming language */
class TemplateScanner : public IJsonReaderWriter<std::tuple<std::string, std::vector<std::string>>,
                                                 std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>>
{
private:
    fs::path m_config_file_path;
    fs::path m_templates_path;
public:
    TemplateScanner(const std::string& directory_name);
    std::vector<std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>> read_json_file() const override;
    void write_to_json_file(const std::vector<std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>>& data) const override;
    std::vector<std::tuple<std::string, std::vector<std::string>>> scan_directory(const std::string& directory) const override;
    bool create_json_file() const override;
};

#endif // TEMPLATESCANNER_H
