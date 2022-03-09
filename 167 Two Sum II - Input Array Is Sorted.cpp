#include<iostream>
#include<vector>

using namespace std;

/**
 * @brief 给定一个已按照 非递减顺序排列  的整数数组 numbers ，
 * 请你从数组中找出两个数满足相加之和等于目标数 target 。
   函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。
   numbers 的下标 从 1 开始计数 ，
   所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
   你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
 * 
 */


class Solution{
public:
/**
 * @brief 
 * 
 * @param nums 
 * @param target 
 * @return vector<int> 
 */
    vector<int> twoSum(vector<int> &nums, int target){
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int low = i+1;
            int high = n-1;
            while (low <= high)
            {
                int mid = low +(high - low)/2;
                if (nums[mid] == target - nums[i]){
                    return {i+1 , mid+1};
                }
                else if(nums[mid] > target - nums[i]){
                    //中值 大于 寻找的数 说明 在中值左边的区间
                    high = mid-1;
                }
                else{
                    //中值 小于 寻找的数 说明 在中值右边的区间
                    low = mid+1;
                }                    
            }   
        }
        return {-1,-1};
    }
};

int main()
{
    vector<int> obj;
    obj.push_back(2);
    obj.push_back(7);
    obj.push_back(11);
    obj.push_back(15);

    Solution app;
    app.twoSum(obj,9);
    for (int i = 0; i < app.twoSum(obj,9).size(); i++)
    {
        cout << app.twoSum(obj,9)[i] <<endl;
    }
    

    return 0;
}