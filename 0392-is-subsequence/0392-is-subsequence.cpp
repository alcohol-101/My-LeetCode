class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty())return true;
        int i=0,n=s.size();
        for(int j=0;j<t.size();j++){
            if(t[j]==s[i]){
                if(i==n-1)return true;
                ++i;
            }
        }
        return false;
    }
};