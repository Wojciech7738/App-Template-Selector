#include "../../include/Models/ProgLangScanner.h"

ProgLangScanner::ProgLangScanner(const std::string& file_name)
    : m_file_name(file_name + ".json")
{
    // Get the path to the parent directory (the main direcotry of the project)
    m_project_path = fs::current_path().parent_path();
}

std::vector<std::string> ProgLangScanner::read_json_file() const
{
    // TODO: Implement this method.
    std::vector<std::string> data;
    return data;
}

void ProgLangScanner::write_to_json_file(const std::vector<std::string>& data) const
{
    // TODO: Implement this method.

}

// bool ProgLangScanner::is_direcotry_valid(const std::string& directory)
// {
//     // TODO: Implement this method.
//     return false;
// }


std::vector<std::string> ProgLangScanner::scan_directory(const std::string& directory) const
{
    fs::path lang_path = m_project_path / directory;
    std::vector<std::string> languages;
    // if (JsonReaderWriter::is_direcotry_valid(directory))
    // {
    //     // TODO: throw an exception
    //     return languages;
    // }
    
    for (const auto& entry : fs::directory_iterator(lang_path))
    {
        languages.push_back(entry.path().filename().string());
    }
    return languages;
}
