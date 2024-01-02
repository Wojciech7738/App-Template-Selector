#include "../../include/Models/TemplateScanner.h"

TemplateScanner::TemplateScanner(const std::string& file_name)
    : m_file_name(file_name + ".json")
{
    // Get the path to the parent directory (the main direcotry of the project)
    m_templates_path = fs::current_path().parent_path() / "Templates";
}

std::vector<std::string> TemplateScanner::read_json_file() const
{
    // TODO: Implement this method.
    std::vector<std::string> data;
    return data;
}

void TemplateScanner::write_to_json_file(const std::vector<std::string>& data) const
{
    // TODO: Implement this method.

}

std::vector<std::tuple<std::string, std::vector<std::string>>> TemplateScanner::scan_directory(const std::string& directory) const
{
    // TODO: improve directory scanning for more complicated examples
    fs::path lang_path = m_templates_path / directory;
    // vector containing elements with the following structure: <directory_name, vector_of_files>
    std::vector<std::tuple<std::string, std::vector<std::string>>> templates_files;
    std::string dir_name;
    std::vector<std::string> files;

    for (const auto& entry : fs::directory_iterator(lang_path))
    {
        dir_name = "";
        files.clear();
        dir_name = entry.path().filename().string();
        for (const auto& file_entry : fs::recursive_directory_iterator(entry.path())) {
            files.push_back(file_entry.path().filename().string());
        }
        templates_files.push_back(std::make_tuple(dir_name, files));
    }
    return templates_files;
}
