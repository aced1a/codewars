#include <string>
#include <vector>

using namespace std;

class RomanHelper{
public:
    static string to_roman(int value);
    static int from_roman(string value);
private:
    static unordered_map<char, int> romanToInt;
    static vector<int> roman;
    static vector<char> roman_;
} RomanNumerals;

unordered_map<char, int> RomanHelper::romanToInt = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}, {'0', 0}};
vector<int> RomanHelper::roman = {1000, 500, 100, 50, 10, 5, 1};
vector<char> RomanHelper::roman_ = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

string RomanHelper::to_roman(int value)
{
    string res = "";
    int last = 0;
   
    for(unsigned long i=0; i < roman.size(); i++)
    {
        int n = value / roman[i];

        if(n == 4)
            if(last - value < 2 * roman[i]) res = res + roman_[i] + roman_[i-1];
            else {
                res.pop_back();
                res = res + roman_[i] + roman_[i-2];
            }
        else
            res += string(n, roman_[i]);
        
        last = value;
        value %= roman[i];
    }
    return res;
}

int RomanHelper::from_roman(string value) 
{
    int sum = 0;
    unsigned long i = 0;

    for(i = 0; i < value.length()-1; i++)
    {
        int val = romanToInt[value[i]], next = romanToInt[value[i+1]];
        if(val >= next)
            sum += val;
        else {
            sum += (next - val);
            i++;
        }
    }

    return sum + (i < value.length() ? romanToInt[value[i]] : 0);
}