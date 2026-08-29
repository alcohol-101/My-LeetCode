class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        if(m<n)return "";
        unordered_map<char,int>need;
        for(char c:t)need[c]++;

        unordered_map<char,int>win;
        int l=0,start=0;
        int minLen=INT_MAX,match=0;

        for(int r=0;r<m;r++){
            char x=s[r];
            if(need.count(x)!=0){
                win[x]++;
                if(need[x]==win[x])match++;
            }
            while(match==need.size()){
                char b=s[l];
                if(need.count(b)!=0){
                    if(need[b]==win[b]){
                        match--;
                        win[b]--;
                        int len=r-l+1;
                        start=minLen<len?start:l;
                        minLen=minLen<len?minLen:len;
                    }
                    else{
                        win[b]--;
                    }
                }
                l++;
            }
        }
        if(minLen==INT_MAX)return "";
        return s.substr(start,minLen);

    }
    
};