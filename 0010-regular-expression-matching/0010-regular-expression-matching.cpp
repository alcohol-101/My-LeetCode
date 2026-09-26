class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1));
        
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        for(int j=1;j<=m;j++){
            if(j==1)dp[0][j]=false;
            else dp[0][j]=dp[0][j-2]&&(p[j-1]=='*');
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]!='*'&&p[j-1]!='.'){
                    dp[i][j]=dp[i-1][j-1]&&(s[i-1]==p[j-1]);
                }
                else if(p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(p[j-2]=='.'||p[j-2]==s[i-1]){//p[j-2]可以匹配s[i-1]
                        dp[i][j]=dp[i][j-2]||dp[i-1][j];//为空或压缩s
                    }
                    else {
                        dp[i][j]=dp[i][j-2];//由为空是否可以匹配来直接决定
                    }
                }
            }
        }
        return dp[n][m];
    }
};