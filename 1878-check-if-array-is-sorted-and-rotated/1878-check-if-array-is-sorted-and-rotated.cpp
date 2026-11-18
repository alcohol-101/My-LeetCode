class Solution {
public:
    bool check(vector<int>& nums) {
        bool use=false;int n=nums.size();int cur_max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=nums[(i+1)%n]){
                if(use){
                    if(nums[i]>cur_max)return false;
                    else continue;
                }
                else continue;
            }
            else{
                if(!use){
                    use=true;
                    cur_max=nums[0];
                }
                else return false;
            }
        }
        return true;
    }
    
};