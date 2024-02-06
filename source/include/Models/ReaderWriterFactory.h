#ifndef READERWRITERFACTORY_H
#define READERWRITERFACTORY_H

#pragma once

#include <memory>
#include "IJsonReaderWriter.h"
#include "Models/ProgLangScanner.h"
#include "Models/TemplateScanner.h"


class ReaderWriterFactory
{
public:
    static std::unique_ptr<IJsonReaderWriter<std::string, std::string>> createJsonReaderWriter(const std::string& file_name);
    static std::unique_ptr<IJsonReaderWriter<std::tuple<std::string, std::vector<std::string>>, std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>>> createTemplateScanner(const std::string& file_name);
};

#endif
