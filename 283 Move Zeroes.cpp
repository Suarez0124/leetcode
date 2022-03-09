#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief 给定一个数组 nums，
 * 编写一个函数将所有 0 移动到数组的末尾，
 * 同时保持非零元素的相对顺序。
 * @brief (1)双指针 ，current指针，和左指针（跟随着0）
 *        (2)碰到非零的数，两个指针都向右移
 *        (3)碰到零的数，左指针不动，跟着他，current指针向右移
 *        (4)current指针碰到非零的数，意味着要向左指针交换，那么就可以保持顺序性
 *        (5)直到current = size 停止
 * 
 */
class Solution{
public:
    void moveZeros(vector<int> &nums){
        int size = nums.size();
        for(int current=0, left =0; current<size; current++){
            if (nums[current]!=0)
            {
                swap(nums[left],nums[current]);
                left++;
            }           
        }
    }
};



int main()
{

    vector<int> obj;
    obj.push_back(0);
    obj.push_back(2);
    obj.push_back(0);
    obj.push_back(3);
    obj.push_back(12);
    obj.push_back(5);

    Solution app;
    app.moveZeros(obj);
    for (int i = 0; i < obj.size(); i++)
    {
        cout<< obj[i] <<endl;
    }
    

    return 0;
}