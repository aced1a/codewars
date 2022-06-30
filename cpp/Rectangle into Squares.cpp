#include <vector>

class SqInRect
{
  public:
    static std::vector<int> sqInRect(int lng, int wdth)
    {
        if(lng == wdth) return {};
      
        return solve(lng, wdth); 
    }
  
  private:
    static std::vector<int> solve(int lng, int wdth)
    {
        if(lng == wdth) return {lng};
        
        int min = std::min(lng, wdth);
        int max = std::max(lng, wdth);
      
        auto v = solve(max - min, min);
      
        v.insert(v.begin(), min);
      
        return v;
    }
};