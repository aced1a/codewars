#include <string>

std::vector<std::string> getTimes(int seconds);

std::string format_duration(int seconds) 
{
    if(seconds == 0) return "now";
  
    std::string result = "", separator = "";
    auto times = getTimes(seconds);
  
    for(unsigned long i = 0;i<times.size();i++)
    {
        result += separator + times[i];
        separator = (i == times.size() - 2 ? " and " : ", ");
    } 
  
    return result;
}

std::vector<std::string> getTimes(int seconds) 
{
    int time[] = { 31536000, 86400, 3600, 60, 1 };
    std::string names[] = {" year", " day", " hour", " minute", " second"};
    std::vector<std::string> res;
  
    for(int i=0,n=0; i<5; i++) {
        n = seconds / time[i];
        if(n) 
          res.push_back(std::to_string(n) + names[i] + (n > 1 ? "s" : ""));
        seconds %= time[i];
    }
    return res;
}