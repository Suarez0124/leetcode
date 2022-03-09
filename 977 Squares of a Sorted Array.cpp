#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> sortedSquares(vector<int> &nums){
        vector<int> res(nums.size());
        int left = 0 , right = nums.size()-1;
        for(int i = nums.size()-1 ; i >=0 ; i--){
            if(abs(nums[left]) < abs(nums[right]) ){
                res[i] = nums[right] * nums[right];
                right--;
            }
            else{
                res[i] = nums[left] * nums[left];
                left++;
            }
        }
        return res;
    }
};

void PrintSortedSquares(const vector<int> &A)
{
    for(int i=0; i< A.size(); i++){
        cout << A[i] <<endl;
    }
}


int main()
{
    vector<int> obj;
    obj.push_back(-4);
    obj.push_back(-3);
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(5);

    Solution app;
    PrintSortedSquares(app.sortedSquares(obj));

    return 0;
}