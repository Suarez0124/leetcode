#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0){
            return 0;
        }
        if(nums[size -1] < target){
            return size;
        }

        int left = 0 , right = size-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] < target){
                left = mid +1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};


int main()
{
    vector<int> obj;
    for (int i = 0; i < 10; i++)
    {
        obj.push_back(i);
        //cout << obj[i] << endl;
    }

    Solution app;
    int position = app.searchInsert(obj , 11);
    cout << position <<endl;


    return 0;
}