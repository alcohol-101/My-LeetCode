class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>pres;
       pres[0]=1;
       int count=0;
       int pre=0;
       for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            count+=pres[pre-k];
            
            pres[pre]++;
       }
       return count;
    }
};