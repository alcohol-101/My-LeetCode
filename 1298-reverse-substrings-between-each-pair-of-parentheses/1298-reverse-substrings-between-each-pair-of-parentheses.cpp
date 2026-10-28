class Solution {
    int last;
public:
    string dfs(const string& s,int i){
        string re;
        for(int j=i;j<s.size();j++){
            if(s[j]>='a'&&s[j]<='z'){
                re+=s[j];
            }
            else if(s[j]=='('){
                string tmp=dfs(s,j+1);
                re+=string{tmp.rbegin(),tmp.rend()};
                j=last;
            }
            else {
                last=j;
                break;
            }
        }
        return re;
    }
    string reverseParentheses(string s) {
        return dfs(s,0);
    }

   
};