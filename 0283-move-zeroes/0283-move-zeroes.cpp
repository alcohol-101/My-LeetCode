class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)return;
        int i=0,j=0;
        for(j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};