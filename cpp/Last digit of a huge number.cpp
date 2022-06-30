#include <list>
#include <iostream>
#include <cmath>

using namespace std;


int last_digit(list<int> array) 
{
  long long exp = 1, base = 1;
  for(auto it = array.rbegin(); it != array.rend(); it++)
  { 
      base = *it;
    
      if(exp > 4) exp = exp % 4 + 4;
      if(base > 20) base = base % 20 + 20;
    
      exp = std::pow(base, exp);
  }
  
  return exp % 10;
}