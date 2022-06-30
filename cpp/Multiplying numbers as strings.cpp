#include <numeric>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> toVectorOfInt(string str)
{
    vector<int> res;
    for(auto it = str.rbegin(); it != str.rend(); it++)
        res.push_back(*it - '0');
    return res;
}

vector<int>::reverse_iterator findFirstDigit(vector<int>& v) 
{
    auto it = find_if(v.rbegin(), v.rend(), [](int a) { return a != 0; });
    return it == v.rend() ? it - 1 : it;
}

string toString(vector<int>& v)
{  
    return accumulate(
        findFirstDigit(v),
        v.rend(), 
        ""s, 
        [](string a, int b) { return a + to_string(b);}
    );
}

string multiply(string a, string b) {
    auto first = toVectorOfInt(a), second = toVectorOfInt(b);
    vector<int> result(a.size() + b.size());
    int remainder = 0;

    for(auto i = 0ul; i < second.size(); i++)
    {
        for(auto j = 0ul; j < first.size(); j++)
        {
            int val = result[j+i] + first[j] * second[i] + remainder;
            result[j + i] = val % 10;
            remainder = val / 10;
        }
        if(remainder > 0) 
            result[i + first.size()] = remainder;

        remainder = 0;
    }

    return toString(result);
}