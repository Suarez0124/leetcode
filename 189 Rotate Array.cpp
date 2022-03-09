#include<iostream>
#include<vector>
using namespace std;
//notes:创建新vector 
//vector 的assign 函数将区间[first,last)的元素赋值到当前的vector容器中，
//或者赋n个值为x的元素到vector容器中，这个容器会清除掉vector容器中以前的内容。
// (i+k) % size 取余数

class Solution{
public:
    void rotate(vector<int> &nums , int k){
        int size = nums.size();
        vector<int> newNums(size);
        for(int i =0; i<size; i++){
            newNums[(i+k) % size] = nums[i];
        }
        nums.assign(newNums.begin(),newNums.end());
    }
};



int main()
{
    vector<int> obj;
    obj.push_back(-4);
    obj.push_back(-3);
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(5);

    int trans = 2;
    Solution app;
    app.rotate(obj,trans);
    for(int i=0 ; i<obj.size(); i++){
        cout << obj[i] << endl;
    }

    return 0;
}