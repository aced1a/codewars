std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result(signature.begin(), signature.begin() + std::min(3, n));
    
    for(int i=3;i<n;i++) {
        result.push_back(result[i-1] + result[i-2] + result[i-3]);
    }
  
    return result;
}