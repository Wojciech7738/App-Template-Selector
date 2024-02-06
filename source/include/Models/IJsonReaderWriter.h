#ifndef IJSONREADERWRITER_H
#define IJSONREADERWRITER_H

#pragma once

#include <string>
#include <vector>

template<typename VecType, typename SecondVecType>
class IJsonReaderWriter
{
public:
    virtual std::vector<SecondVecType> read_json_file() const = 0;
    virtual void write_to_json_file(const std::vector<SecondVecType>& data) const = 0;
    virtual std::vector<VecType> scan_directory(const std::string& directory) const = 0;
    virtual bool create_json_file() const = 0;
    virtual ~IJsonReaderWriter() = default;

};

#endif
