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
    const bool isFirstNumber = isNumber(a);
    const bool isSecondNumber = isNumber(b);
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
    const bool isFirstNumber = isNumber(a);
    const bool isSecondNumber = isNumber(b);
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
    const bool isFirstNumber = isNumber(a);
    const bool isSecondNumber = isNumber(b);
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
    const bool isFirstNumber = isNumber(a);
    const bool isSecondNumber = isNumber(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) / std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

//-----------------------------------------------------------------------------
bool Math::isNumber(const std::string& str) const
//-----------------------------------------------------------------------------
{
    return ( !str.empty() )
           && ( str.end() == std::find_if(str.begin(), str.end(), [](char c)
                             {
                                return !std::isdigit(c);
                             }));
}

} //namespace dev
