class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pair<int,int>>e;
        for(int i=0;i<n;i++){
            e.push_back({endTime[i],i});
        }
        sort(e.begin(),e.end());

        vector<int>dp(n);
        dp[0]=profit[e[0].second];
        int maxpro=dp[0];
        for(int i=1;i<n;i++){
            int cur_start=startTime[e[i].second];//当前任务的开始时间
            auto it_p=std::upper_bound(e.begin(),e.begin()+i,make_pair(cur_start,INT_MAX));
            int p=it_p-e.begin()-1;
            dp[i]=max(dp[i-1],profit[e[i].second]+(p>=0?dp[p]:0));
        }
        return dp[n-1];
    }
};