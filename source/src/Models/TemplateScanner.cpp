#include "Models/TemplateScanner.h"

TemplateScanner::TemplateScanner(const std::string& file_name)
{
    m_config_file_path = ((fs::path)(CONFIG_PATH)).parent_path() / (file_name + ".json");
    // Get the path to the parent directory (the main direcotry of the project)
    m_templates_path = fs::current_path().parent_path() / "Templates";
}

std::vector<std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>> TemplateScanner::read_json_file() const
{
    std::vector<std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>> data;
    json records_array;
    std::ifstream file(m_config_file_path);
    // Check if the file is open
    if (!file.is_open()) {
        pathValidator::display_error_message(ERR_OPENING_FILE((std::string)m_config_file_path));
        return data;
    }
    file >> records_array;
    file.close();
    for (const auto& record : records_array) {
        data.push_back(record);
    }
    return data;
}

void TemplateScanner::write_to_json_file(const std::vector<std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>>& data) const
{
    json records_array;
    for (const auto& record : data) {
        records_array.push_back(record);
    }
    std::ofstream file(m_config_file_path);
    // Check if the file is open
    if (!file.is_open()) {
        pathValidator::display_error_message(ERR_OPENING_FILE((std::string)m_config_file_path));
        return;
    }
    file << std::setw(4) << records_array << "\n";
    file.close();
}

bool TemplateScanner::create_json_file() const {
    fs::path path = m_config_file_path.parent_path();
    // Create directory
    if (!fs::create_directory(path) && !fs::exists(path)) {
        pathValidator::display_error_message(ERR_CREATING_DIR(path));
        return false;
    }
    // Create file
    std::ofstream ofs(path);
    ofs << "";
    ofs.close();
    return true;
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
            files.push_back(file_entry.path().string());
        }
        templates_files.push_back(std::make_tuple(dir_name, files));
    }
    return templates_files;
}
