#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            //如果count到一个key 就可以判断 并且删除栈顶
            if (pairs.count(ch)) {
                //为了防止第一个就是右括号 或者 栈顶不等于 pairs的值
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                //放的是unordered_map 的值
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};


int main()
{
    Solution app;
    string s = "()[]{[]}";
    cout << app.isValid(s) << endl;
    

    return 0;
}
