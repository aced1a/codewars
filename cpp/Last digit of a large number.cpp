#include <string>
#include <cmath>

int mod(const std::string a, int val)
{
    int m = 0;
    for(auto ch: a)
    {
        m = (ch - '0') + m * 10;
        m %= val;
    }
    return m == 0 ? val : m;
}

int last_digit(const std::string &a, const std::string &b) 
{
    if(b.size() == 1 && b.back() == '0') return 1;

    return (int) std::pow(a.back()-'0', mod(b, 4)) % 10;
}