#include <string>
#include <vector>

std::unordered_map<char, std::vector<std::string>> borders = {
    {'1', {"1", "2", "4"}}, {'2', {"2", "1", "3", "5"}}, {'3', {"2", "3", "6"}},
    {'4', {"1", "4", "5", "7"}}, {'5', {"2", "4", "5", "6", "8"}}, {'6', {"3", "5", "6", "9"}},
    {'7', {"4", "7", "8"}}, {'8', {"5", "7", "8", "9", "0"}}, {'9', {"6", "8", "9"}},
    {'0', {"0", "8"}}
};

std::vector<std::string> get_pins(std::string observed) {
    if(observed.length() == 1) return borders[observed[0]];

    std::vector<std::string> res;
    auto v = get_pins(observed.substr(1));

    for(auto& item: v) {
        for(auto& ch: borders[observed[0]]) {
            res.push_back(ch + item);
        }
    }

    return res;
}