class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>dp;
        for(auto& i:nums){
            if(dp.contains(i))return i;
            else dp.insert(i);
        }
            return nums[0];
    }
};