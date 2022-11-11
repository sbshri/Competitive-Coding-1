// Find Missing Number in a sorted array
// Time Complexity : O(log n)
// Space Complexity : O(1)


#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int missingNumber(vector<int>& nums){
        if(nums.size() == 0)
            return -1;
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low<high){
            int mid = low + (high-low)/2;
            //break condition
            //we have reduced our problem to size 2 and we just need the average of the numbers to get the missing number
            if(low+1 == high)
                return (nums[low]+nums[high])/2;

            //if the difference between number and index between low and mid is the same, the number lies in the right half
            if(nums[low] - low == nums[mid] - mid)
                low = mid;
            else
                high = mid;
        }
    }
};

int main(){
    vector<int> nums ({1, 2, 3, 4, 5, 6, 8, 9});
    Solution s;
    int result = s.missingNumber(nums);
    if(result == 7)
        cout<<"Correct!";
    else
        cout<<"Wrong solution";
    return 1;
}
