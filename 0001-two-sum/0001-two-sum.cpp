class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>s;
        for(int i=0;i<nums.size();i++){
            int n=target-nums[i];
            if(s.find(n)!=s.end()){
                return {s[n],i};
            }
            s[nums[i]]=i;
        }

        return {};
    }
};