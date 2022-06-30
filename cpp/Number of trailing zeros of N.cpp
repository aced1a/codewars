long zeros(long n) {
  long sum = 0, i = 5;
  
  while((n / i) > 0) {
    sum += n / i;
    i *= 5;
  }
  
  return sum;
}