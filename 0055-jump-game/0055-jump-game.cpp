class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(0+nums[0]>=nums.size()-1)return true;
        int now=0;
        while(now<nums.size()-1){
            
            bool has_td=false;
            for(int i=1;i<=nums[now];i++){
                if(nums[now]-i<nums[now+i]){
                    now=now+i;
                    if(now+nums[now]>=nums.size()-1)return true;
                    has_td=true;
                    break;
                }
            }  
            if(!has_td){
                if(now+nums[now]>=nums.size()-1)return true;
                else return false;
            }
        }
        return true;
    }
};