class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==1)return 2;
            return 1;
        }

        int n=nums.size();
        
        for(int i=0;i<nums.size();++i){
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        for(int j=0;j<nums.size();j++){
            if(nums[j]!= (j+1))return j+1;
        }
        
        return ++n;
    }
};