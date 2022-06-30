#include <vector>

int score(const std::vector<int>& dice) {
  int count[7] = {0};
  int sum = 0;
  
  for(auto& roll: dice) count[roll]++; 
  for(int i=1;i<=6;i++) {
    sum += (count[i]/3) * i * (i == 1 ? 1000 : 100);
    if(i == 1 || i == 5)
      sum += (count[i]%3) * i * (i == 1 ? 100 : 10);
  } 
  
  return sum;
}