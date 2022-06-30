#include <utility>
#include <vector>
#include <cmath>

class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n)
    {
      std::vector<std::pair<long long, long long>> res;
      
        for(auto i=m; i<n; i++) {
            auto sum = sumOfSquaredDivisors(i);
            auto sq = std::sqrt(sum);
            if(std::trunc(sq) == sq)
            res.push_back(std::make_pair(i, sum));
        }
        
        return res;
    }
private:
    static long long sumOfSquaredDivisors(long long n) {
      long long sum = std::pow(n,2);
      
        for(int i=2; i < std::sqrt(n); i++)
        if(n % i == 0) {
            sum += std::pow(i, 2);
            sum += std::pow(n/i, 2);
        }
      
        return sum + (n > 1 ? 1 : 0);
    }
};