size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
    std::unordered_map<char, int> map;
    size_t count = 0;
    const char* c = in;
  
    while(*c != '\0') { 
        map[std::tolower(*c)]++; 
        c++; 
    }
    
    for(auto& item: map) 
        if(item.second > 1) count++;
  
    return count;
}