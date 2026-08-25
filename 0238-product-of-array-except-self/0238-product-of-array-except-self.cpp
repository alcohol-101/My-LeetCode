class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==2){
            reverse(nums.begin(),nums.end());
            vector<int>r(nums.begin(),nums.end());
            return r;
        }
        vector<int>p(nums.size()),s(nums.size());
        p[0]=1;
        p[1]=nums[0];
        s[nums.size()-1]=1;
        s[nums.size()-2]=nums[nums.size()-1];
        for(int i=2;i<nums.size();i++){
            p[i]=p[i-1]*nums[i-1];
        }
        for(int j=nums.size()-3;j>=0;j--){
            s[j]=s[j+1]*nums[j+1];
        }
        vector<int>r(nums.size());
        for(int i=0;i<nums.size();i++){
            r[i]=p[i]*s[i];
        }
        return r;
    }
};