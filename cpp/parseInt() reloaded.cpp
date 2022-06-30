#include <string>
#include <unordered_map>
#include <sstream>

#define VALUE 0
#define MULTIPLIER 1
  

std::unordered_map<std::string, int> values = {
  {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
  {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
  {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, 
  {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
  {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
  {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}
};

std::unordered_map<std::string, int> multipliers = {
  {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
};


struct Token 
{
    int type;
    long value;
};

Token getToken(std::string str)
{
    auto n = str.find('-');
    if(n != std::string::npos) {
      return {
        VALUE, 
        getToken(str.substr(0, n)).value + getToken(str.substr(n+1)).value
      };
    }
    
    if(values.find(str) != values.end()) return {VALUE, values[str]};
    if(multipliers.find(str) != multipliers.end()) return {MULTIPLIER, multipliers[str]};
  
    return {VALUE, 0};
}

long parse_int(std::string number) 
{
    std::istringstream ist(number);
    std::string next;
    long value = 0, last = 0;
    
    while(ist >> next)
    {
        auto token = getToken(next);
        if(token.type == MULTIPLIER) {
          if(token.value > value)
            value = (value + last) * token.value;
          else
            value += last * token.value;
          last = 0;
        }
        else {
          last = token.value;
        }
    }
  
    return value + last;
}