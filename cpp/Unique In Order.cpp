#include <string>
#include <vector>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  std::vector<T> result;
  for(T item: iterable) {
    if(result.empty() || result.back() != item)
      result.push_back(item);
  }
  return result;
}
std::vector<char> uniqueInOrder(const std::string& iterable){
  return uniqueInOrder(std::vector<char>(iterable.begin(), iterable.end()));
}