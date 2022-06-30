#include <cmath>

int square_digits(int num) {
  int result = 0, digit = 0, i = 0;
  
  while(num > 0) {
    digit = num % 10;
    result += pow(digit, 2) * pow(10, i);
    
    i += 1 + (digit > 3);
    num /= 10;
  }
  
  return result;
}