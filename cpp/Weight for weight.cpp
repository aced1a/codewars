class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng);
private:
    static std::vector<std::string> split(const std::string& strng);
    static long sum(const std::string& strng);
    static bool pairSort(std::pair<std::string, long> a, std::pair<std::string, long> b);
    static std::string concat(std::vector<std::pair<std::string, long>> v); 
};

std::string WeightSort::orderWeight(const std::string& strng) 
{
    std::vector<std::pair<std::string, long>> result;

    for(auto& item: split(strng)) {
        result.push_back(std::make_pair(item, sum(item)));
    }

    std::sort(result.begin(), result.end(), pairSort);

    return concat(result);
}

std::vector<std::string> WeightSort::split(const std::string& strng)
{
    std::istringstream ist(strng);

    return std::vector<std::string>(
        std::istream_iterator<std::string>{ist},
        std::istream_iterator<std::string>()
    );
}

long WeightSort::sum(const std::string& strng) 
{  
    long value = std::stol(strng), sum = 0;

    while(value > 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

bool WeightSort::pairSort(std::pair<std::string, long> a, std::pair<std::string, long> b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

std::string WeightSort::concat(std::vector<std::pair<std::string, long>> v) {
    std::string result = "";

    for(auto& item: v)
        result += item.first + " " ;

    if(result != "") result.pop_back();

    return result;
}