class Solution {
public:
    string reverseWords(string s) {
        string re="";
        string tmp="";
        for(auto &t:s){
            if(t!=' ')tmp+=t;
            else {
                reverse(tmp.begin(),tmp.end());
                re+=tmp;re+=" ";tmp="";
            }
        }
        reverse(tmp.begin(),tmp.end());
        re+=tmp;
        return re;
    }
   
};