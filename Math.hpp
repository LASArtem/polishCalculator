#pragma once

namespace dev
{

class string;

class Math
{
public:
    Math();
    ~Math();

    bool sum(std::string& result, const std::string a, const std::string b) const;
    bool diff(std::string& result, const std::string a, const std::string b) const;
    bool multiplication(std::string& result, const std::string a, const std::string b) const;
    bool division(std::string& result, const std::string a, const std::string b) const;

private:
    inline bool isNumber(const std::string& str) const;
};

} //namespace dev
