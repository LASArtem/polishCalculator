#include <string>

#include "StringRecognizer.hpp"

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
    const bool isFirstNumber = StringRecognizer::isInteger(a) || StringRecognizer::isNegativeInteger(a);
    const bool isSecondNumber = StringRecognizer::isInteger(b) || StringRecognizer::isNegativeInteger(b);
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
    const bool isFirstNumber = StringRecognizer::isInteger(a) || StringRecognizer::isNegativeInteger(a);
    const bool isSecondNumber = StringRecognizer::isInteger(b) || StringRecognizer::isNegativeInteger(b);
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
    const bool isFirstNumber = StringRecognizer::isInteger(a) || StringRecognizer::isNegativeInteger(a);
    const bool isSecondNumber = StringRecognizer::isInteger(b) || StringRecognizer::isNegativeInteger(b);
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
    const bool isFirstNumber = StringRecognizer::isInteger(a) || StringRecognizer::isNegativeInteger(a);
    const bool isSecondNumber = StringRecognizer::isInteger(b) || StringRecognizer::isNegativeInteger(b);
    if (isFirstNumber && isSecondNumber)
    {
        result = std::to_string(std::stoi(a) / std::stoi(b));
    }
    return isFirstNumber && isSecondNumber;
}

} //namespace dev
