class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=nums[0],minSum=nums[0],totalSum=0;
        for(auto & i:nums)totalSum+=i;

        int curmax=0,curmin=0;

        for(int i=0;i<nums.size();i++){
            curmax=max(curmax+nums[i],nums[i]);
            maxSum=max(curmax,maxSum);

            curmin=min(curmin+nums[i],nums[i]);
            minSum=min(minSum,curmin);
        }

        if(maxSum<0)return maxSum;

        return max(maxSum,totalSum-minSum);
    }
};