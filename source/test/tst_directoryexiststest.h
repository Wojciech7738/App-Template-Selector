
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "Models/IJsonReaderWriter.h"
#include "Models/ReaderWriterFactory.h"

using namespace testing;

TEST(FileDirectoryExistenceTest, DirectoryExistsTest)
{
    std::unique_ptr<IJsonReaderWriter<std::string>> json_reader_writer = ReaderWriterFactory::createJsonReaderWriter("languages");
    std::vector<std::string> languages = json_reader_writer->scan_directory("Templates");
    EXPECT_FALSE(languages.empty());
}

TEST(FileDirectoryExistenceTest, DirectoryNotExistsTest)
{
    std::unique_ptr<IJsonReaderWriter<std::string>> json_reader_writer = ReaderWriterFactory::createJsonReaderWriter("languages");
    std::vector<std::string> languages = json_reader_writer->scan_directory("te");
    EXPECT_TRUE(languages.empty());
}
