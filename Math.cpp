#include <algorithm>
#include <string>

#include "Math.hpp"

namespace dev
{

//-----------------------------------------------------------------------------
Math::Math()
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
Math::~Math()
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
bool Math::sum(std::string& result, const std::string a, const std::string b) const
//-----------------------------------------------------------------------------
{
    // do we need here strings?
    //  As for me, now whese methods are responsible for parsing and calulations.
    //  I believe, it is not quite obvious...
    // redundant checks?
    const bool isFirstNumber = isInteger(a) || isNegativeInteger(a);
    const bool isSecondNumber = isInteger(b) || isNegativeInteger(b);

    //create bool variable to return;
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) + std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

//-----------------------------------------------------------------------------
bool Math::diff(std::string& result, const std::string a, const std::string b) const
//-----------------------------------------------------------------------------
{
    const bool isFirstNumber = isInteger(a) || isNegativeInteger(a);
    const bool isSecondNumber = isInteger(b) || isNegativeInteger(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) - std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

//-----------------------------------------------------------------------------
bool Math::multiplication(std::string& result, const std::string a, const std::string b) const
//-----------------------------------------------------------------------------
{
    const bool isFirstNumber = isInteger(a) || isNegativeInteger(a);
    const bool isSecondNumber = isInteger(b) || isNegativeInteger(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) * std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

//-----------------------------------------------------------------------------
bool Math::division(std::string& result, const std::string a, const std::string b) const
//-----------------------------------------------------------------------------
{
    const bool isFirstNumber = isInteger(a) || isNegativeInteger(a);
    const bool isSecondNumber = isInteger(b) || isNegativeInteger(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) / std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

//-----------------------------------------------------------------------------
bool Math::isInteger(const std::string& str) const
//-----------------------------------------------------------------------------
{
    // not obvious. How about lambda?
    return ( !str.empty() )
           && ( str.end() == std::find_if(str.begin(), str.end(), [](char c)
                             {
                                return !std::isdigit(c);
                             }));
}

//-----------------------------------------------------------------------------
bool Math::isDouble(const std::string& str) const
//-----------------------------------------------------------------------------
{
    return ( !str.empty() )
           && ( str.end() == std::find_if(str.begin(), str.end(), [](char c)
                             {
                                return !std::isdigit(c);
                             }));
}

//-----------------------------------------------------------------------------
bool Math::isNegativeInteger(const std::string& str) const
//-----------------------------------------------------------------------------
{
    return !str.empty() && ('-' == str[0]) && (1 < str.size()) && isInteger(str.substr(1, str.size()));
}

} //namespace dev
