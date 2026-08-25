class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size())k=k%nums.size();
        vector<int>tmp1(nums.begin(),nums.end()-k);
        vector<int>tmp2(nums.end()-k,nums.end());
        nums={};
        nums.insert(nums.end(),tmp2.begin(),tmp2.end());
        nums.insert(nums.end(),tmp1.begin(),tmp1.end());
    }
};