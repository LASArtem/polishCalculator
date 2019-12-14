#include <algorithm>
#include <string>
#include "StringRecognizer.hpp"

namespace dev
{
namespace StringRecognizer
{
//-----------------------------------------------------------------------------
bool isInteger(const std::string& str)
//-----------------------------------------------------------------------------
{
    return ( !str.empty() )
               && ( str.end() == std::find_if(str.begin(), str.end(), [](char c)
                                 {
                                    return !std::isdigit(c);
                                 }));
}

//-----------------------------------------------------------------------------
bool isDouble(const std::string& str)
//-----------------------------------------------------------------------------
{
return ( !str.empty() )
               && ( str.end() == std::find_if(str.begin(), str.end(), [](char c)
                                 {
                                    return !std::isdigit(c);
                                 }));
}

//-----------------------------------------------------------------------------
bool isNegativeInteger(const std::string& str)
//-----------------------------------------------------------------------------
{
    return !str.empty() && ('-' == str[0]) && (1 < str.size()) && isInteger(str.substr(1, str.size()));
}

} // namespace StringRecognizer
} //namespace dev
