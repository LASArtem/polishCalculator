#pragma once

namespace dev
{
namespace StringRecognizer
{
    class string;

    bool isInteger(const std::string& str);
    bool isDouble(const std::string& str);
    bool isNegativeInteger(const std::string& str);

} //namespace StringRecognizer
} //namespace dev
