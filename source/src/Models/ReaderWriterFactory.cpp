#include "Models/ReaderWriterFactory.h"

std::unique_ptr<IJsonReaderWriter<std::string, std::string>> ReaderWriterFactory::createJsonReaderWriter(const std::string& file_name)
{
    return std::make_unique<ProgLangScanner>(file_name);
}

std::unique_ptr<IJsonReaderWriter<std::tuple<std::string, std::vector<std::string>>, std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>>> ReaderWriterFactory::createTemplateScanner(const std::string& file_name)
{
    return std::make_unique<TemplateScanner>(file_name);
}
