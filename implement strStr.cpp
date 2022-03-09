#include<iostream>
#include<string>
#include<vector>
using namespace std;
// 实现 strStr() 函数。
// 给你两个字符串 haystack 和 needle ，
//请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
//如果不存在，则返回  -1 。

// 说明：
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。
//这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。



//暴力法
//从haystack 第一个字符开始与needl所有的字符比较。如果有不等的就fasle掉。
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n==0){
            return 0;
        }
        for(int i=0; i<m; i++){
            bool flag = true;
            for(int j=0; j<n; j++){
                //从当前i的字符开始与need所有的字符一一比较
                //haystack[i+j] 表示为：
                // haystack[1+0]  needle[0]
                // haystack[1+1]  needle[1]
                if(haystack[i+j]!=needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1; 
    }
};

class KMP {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};



int main()
{
    Solution app;
    KMP app2;
    string haystack = "abbcaa";
    string needle = "bca";
    cout <<"暴力法："<< app.strStr(haystack,needle) <<endl;
    cout <<"KMP："<< app2.strStr(haystack,needle) <<endl;
    return 0;

}