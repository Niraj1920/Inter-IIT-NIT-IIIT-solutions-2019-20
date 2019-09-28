/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements 
of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity 
analysis.)
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    /*
    //Solution taking extra space of O(2N)...
    int n=nums.size();
    vector<int> fromBegin(n);
    fromBegin[0]=1;
    vector<int> fromLast(n);
    fromLast[0]=1;
    
    for(int i=1;i<n;i++){
        fromBegin[i]=fromBegin[i-1]*nums[i-1];
        fromLast[i]=fromLast[i-1]*nums[n-i];
    }
    //for(int i=0;i<n;i++)    cout<<fromBegin[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++)    cout<<fromLast[i]<<" ";cout<<endl;
    
    vector<int> res(n);
    for(int i=0;i<n;i++){
        res[i]=fromBegin[i]*fromLast[n-1-i];
    }
    return res;
    */
    
    int n=nums.size();
    int fromBegin=1;
    int fromLast=1;
    vector<int> res(n,1);

    for(int i=0;i<n;i++){
        res[i]*=fromBegin;
        fromBegin*=nums[i];
        res[n-1-i]*=fromLast;
        fromLast*=nums[n-1-i];
    }
    return res;
}

int main()
{
    vector<int> nums{1,2,3,4};
    
    nums = productExceptSelf(nums);
    for(int i=0;i<nums.size();i++)    cout<<nums[i]<<" ";cout<<endl;

    return 0;
}
