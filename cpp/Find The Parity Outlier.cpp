bool isOddArray(std::vector<int> arr)
{
  int odd = 0, even = 0;
  for(auto& item: arr)
    if(item & 1) { odd++; }
    else { even++; }
  
  return odd > even;
}

int FindOutlier(std::vector<int> arr)
{
    auto f = isOddArray(std::vector(arr.begin(), arr.begin()+3))
      ? [](int a) { return (a & 1) == 0; }
      : [](int a) { return (a & 1) == 1; };
  
    return *std::find_if(arr.begin(), arr.end(), f);
}