#include<iostream>
using namespace std;

//二分查找
//计算 中值 mid 
// 如果mid的版本是正确的 ，说明错误版本在mid的后面 
// 所以，将左边界拉到 mid+1
// 再计算中值，不断的判断。
// 直到 有边界等于左边界

bool isBadVersion(int version){
    if (version > 3)
    {
        return true;
    }
    else{
        return false;
    }    
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) { // 循环直至区间左右端点相同
            int mid = left + (right - left) / 2; // 防止计算时溢出
            if (isBadVersion(mid)) {
                right = mid; // 答案在区间 [left, mid] 中
            } else {
                left = mid + 1; // 答案在区间 [mid+1, right] 中
            }
        }
        // 此时有 left == right，区间缩为一个点，即为答案
        return left;
    }
};



int main()
{
    Solution app;
    cout << app.firstBadVersion(5) << endl;

    //cout << isBadVersion(3) << endl;
    return 0;
}