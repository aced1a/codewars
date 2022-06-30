#include <string>
#include <algorithm>
#include <iterator>

std::string duplicate_encoder(const std::string& word){
    std::unordered_map<char, int> count;
    std::string res;

    std::transform(word.begin(), word.end(), std::inserter(res, std::end(res)), ::tolower);
    
    for(auto& item: res) 
        count[item]++;

    std::transform(
        res.begin(), res.end(), res.begin(), [&count](char& c) { return count[c] > 1 ? ')' : '(';}
    );

    return res;
}