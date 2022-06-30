#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) {
    std::vector<std::string> res;
    int n = 2*nFloors - 1;

    for(unsigned i=1, o=(n-1)/2; i <= n; i+=2, --o) 
    {
        std::string offset = std::string(o, ' ');
        res.push_back(offset + std::string(i, '*') + offset);
    }

    return res;
}