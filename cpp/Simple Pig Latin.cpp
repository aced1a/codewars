#include <numeric>
#include <locale>

std::vector<std::string> split(std::string str)
{
    std::istringstream ist(str);

    return std::vector<std::string>(
        std::istream_iterator<std::string>{ist},
        std::istream_iterator<std::string>()
    );
}

std::string join(std::vector<std::string> v, char ch)
{
    return std::accumulate(
        std::next(v.begin()),
        v.end(),
        v[0],
        [ch] (std::string a, std::string b) { return a + ch + b; }
    );
}

std::string pig_it(std::string str)
{
    auto v = split(str);
    for(auto& item: v) {
        if(std::isalpha(item[0]))
            item = item.substr(1) + item[0] + "ay";
    }
    return join(v, ' ');
}