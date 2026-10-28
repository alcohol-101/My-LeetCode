class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=-1;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        dp[0][0]=matrix[0][0]=='1'?1:0;
        maxi=dp[0][0]==0?0:1;
        for(int i=1;i<n;i++){
            if(matrix[i][0]=='1'){dp[i][0]=1;maxi=1;}
        }
        for(int j=1;j<m;j++){
            if(matrix[0][j]=='1'){dp[0][j]=1;maxi=1;}
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    int l=sqrt(min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}));
                    dp[i][j]=pow(l+1,2);
                }
                else dp[i][j]=0;
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};