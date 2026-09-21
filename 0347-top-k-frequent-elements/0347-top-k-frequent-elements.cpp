class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>ans1;
        multimap<int,int,greater<int>>ans2;
        for(auto i:nums){
            ans1[i]++;
        }
        int count=0;
        for(auto &[k,v]:ans1){
            ans2.insert({v,k});
        }
        for(auto &[key,val]:ans2){
            if(count<k){
                ans.push_back(val);
                count++;
            }
            else break;
        }
        return ans;
    }
};