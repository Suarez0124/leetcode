#include<iostream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string ret;
        int length = s.length();
        int i = 0;
        while (i < length)
        {
            int start = i;
            while (i < length && s[i] != ' ')
            {
                i++;
            }
            for( int p = start; p < i; p++)
            {
                ret.push_back(s[start + i -1 - p]);
            }
            while (i < length && s[i] == ' ')
            {
                i++;
                ret.push_back(' ');
            }  
        }
        return ret;  
    }

};

int main()
{
    string words = "Let's take LeetCode contest";
    Solution app;
    cout << app.reverseWords(words) << endl;
    
    return 0;
}