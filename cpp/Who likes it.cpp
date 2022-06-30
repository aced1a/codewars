#include <fmt/core.h>
#include <numeric>

template<typename T>
std::string join(T begin, T end) {
    if(begin == end) return *begin;
  
    return std::accumulate(
      std::next(begin), 
      end, 
      *begin, 
      [](std::string a, std::string b) {
          return a + ", " + b;
      }
    );
}

std::string likes(const std::vector<std::string> &names)
{
    if(names.size() == 0) return "no one likes this";
    if(names.size() == 1) return names[0] + " likes this";
  
    int r = names.size() > 3 ? (names.size() - 2) : 1;  
  
    std::string result = join(names.begin(), names.end() - r);
  
    if(r > 1) result += (" and " + std::to_string(r) + " others");
    else result += " and " + names.back();
  
     return result + " like this";
}