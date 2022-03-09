#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string prefix = strs[0];
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) {
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            ++index;
        }
        return str1.substr(0, index);
    }
};

int main()
{
    vector<string> st;
    st.push_back("sabd");
    st.push_back("sabe");
    st.push_back("sabgr");
    Solution app;
    string result = app.longestCommonPrefix(st);
    cout << result <<endl;
    

    return 0;
}