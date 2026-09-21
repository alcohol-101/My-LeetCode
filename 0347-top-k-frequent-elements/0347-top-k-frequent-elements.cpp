class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        ans.reserve(k);
        unordered_map<int,int>ans1;
        for(auto i:nums){
            ans1[i]++;
        }

        int n=nums.size();
        vector<vector<int>>tong(n+1);
        for(auto &[k,v]:ans1){
            tong[v].push_back(k);
        }
        for(int i=n;i>=1&&ans.size()<k;i--){
            for(auto val:tong[i]){
                ans.push_back(val);
                if(ans.size()==k)break;
            }
        }

        return ans;
    }
};