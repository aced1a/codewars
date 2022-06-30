#include <cstdint>
#include <string>

std::string add_binary(uint64_t a, uint64_t b) {
    auto sum = a + b;
    std::string res = "";

    do {
        res.insert(0, 1, (sum & 1) ? '1' : '0');
        sum >>= 1;
    } while(sum > 0);

    return res;
}