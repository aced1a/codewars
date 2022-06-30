#include <cmath>

class Decomp
{
  public:
    static std::vector<long long> decompose(long long n);
    static std::vector<long long> recurseDecompose(long long n, long long s);
};

std::vector<long long> Decomp::decompose(long long n)
{
    for(auto i=n-1; i > 0; i--)
    { 
        auto v = recurseDecompose(i, n*n);
        if(v.size() > 0) return v;
    }
    return {};
}

std::vector<long long> Decomp::recurseDecompose(long long n, long long s)
{
    for(auto i = n; i > 0; i--)
    {
        long long k = s - (i*i);
        long long l = std::truncl(std::sqrt(k));
      
        if(k < 0) return {};
        if(k == 0) return {i};
      
        auto v = recurseDecompose(std::min(i-1, (l == i ? l - 1 : l)), k);
        if(v.size() > 0) {
          v.push_back(i);
          return v;
        }
    }
    
    return {};
}