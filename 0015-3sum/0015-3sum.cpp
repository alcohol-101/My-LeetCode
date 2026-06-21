class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>re;
        
        //vector<vector<int>>result;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int num=nums[i]+nums[l]+nums[r];
                if(num==0){
                    re.insert({nums[i],nums[l],nums[r]});
                    
                    l++;
                    r--;
                }
                else if(num<0)l++;
                else r--;
            }
        }



        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size()-1;j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(i != j&&i != k&&j != k&&nums[i] + nums[j] + nums[k] == 0)
        //                 result.push_back({nums[i], nums[j], nums[k]});
        //         }
        //     }
        // }
        return vector<vector<int>>(re.begin(), re.end());
    }
};