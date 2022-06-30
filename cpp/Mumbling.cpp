class Accumul
{
public:
    static std::string accum(const std::string &s) 
    {
        std::string result = "";
        char symbol = ' ';

        for(auto i=0;i<s.size();i++) {
            symbol = tolower(s.at(i));

            result += (char)std::toupper(symbol) + std::string(i, symbol);
            result += i == s.size()-1 ? "" : "-";
        }

return result;
}
};