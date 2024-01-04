#ifndef JSONREADERWRITER_H
#define JSONREADERWRITER_H

#pragma once

#include <filesystem>
#include "json.hpp"
#include "IJsonReaderWriter.h"

namespace fs = std::filesystem;

/* A class for scanning a directory with programming languages (without subdirectories) and saving their names into .json file */
class ProgLangScanner : public IJsonReaderWriter<std::string>
{
private:
    std::string m_file_name;
    fs::path m_project_path;
public:
    ProgLangScanner(const std::string& file_name);
    std::vector<std::string> read_json_file() const override;
    void write_to_json_file(const std::vector<std::string>& data) const override;
    std::vector<std::string> scan_directory(const std::string& directory) const override;
    // bool ProgLangScanner::is_direcotry_valid(const std::string& directory);
};

#endif
