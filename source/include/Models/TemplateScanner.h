#ifndef TEMPLATESCANNER_H
#define TEMPLATESCANNER_H

#pragma once

#include <filesystem>
#include <tuple>
#include "../../libs/nlohmann_json/json.hpp"
#include "IJsonReaderWriter.h"

namespace fs = std::filesystem;

/* A class for scanning the app templates of given programming language */
class TemplateScanner : public IJsonReaderWriter<std::tuple<std::string, std::vector<std::string>>>
{
private:
    std::string m_file_name;
    fs::path m_templates_path;
public:
    TemplateScanner(const std::string& directory_name);
    std::vector<std::string> read_json_file() const override;
    void write_to_json_file(const std::vector<std::string>& data) const override;
    std::vector<std::tuple<std::string, std::vector<std::string>>> scan_directory(const std::string& directory) const override;
};

#endif // TEMPLATESCANNER_H
