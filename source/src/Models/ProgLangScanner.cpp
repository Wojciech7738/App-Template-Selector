#include "Models/ProgLangScanner.h"

ProgLangScanner::ProgLangScanner(const std::string& file_name)
{
    m_config_file_path = ((fs::path)(CONFIG_PATH)).parent_path() / (file_name + ".json");
    // Get the path to the parent directory (the main direcotry of the project)
    m_project_path = fs::current_path().parent_path();
}

std::vector<std::string> ProgLangScanner::read_json_file() const
{
    std::vector<std::string> data;
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

void ProgLangScanner::write_to_json_file(const std::vector<std::string>& data) const
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

bool ProgLangScanner::create_json_file() const {
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

std::vector<std::string> ProgLangScanner::scan_directory(const std::string& directory) const
{
    fs::path lang_path = m_project_path / directory;
    std::vector<std::string> languages;

    if (!pathValidator::validate_prog_lang_dir(lang_path.string()))
    {
        return languages;
    }
    
    for (const auto& entry : fs::directory_iterator(lang_path))
    {
        languages.push_back(entry.path().filename().string());
    }
    // Given directory must contain subdirectories only
    if (!pathValidator::validate_prog_lang_dir_contents(lang_path, languages)) {
        languages.clear();
    }
    return languages;
}
