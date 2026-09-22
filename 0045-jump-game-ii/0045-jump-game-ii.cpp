class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int n=nums.size();
        int steps=0;
        int maxReach=0;
        int now_end=0;

        for(int i=0;i<n-1;i++){
            maxReach=max(maxReach,i+nums[i]);
            if(now_end==i){
                steps++;
                now_end=maxReach;
            }
            if(now_end==n-1)break;
        }
        return steps;
    }
};