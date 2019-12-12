#pragma once

namespace dev
{

class stack;
class string;


class Parser
{
public:
    Parser();
    ~Parser();

    void parseStringToStringStack(const std::string str, std::stack<std::string>& stack) const;

private:

};

} //namespace dev
