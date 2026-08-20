class Solution {
public:
    string reverseWords(string s) {
        auto it=s.find(" ");
        if(it==string::npos)return s;
        bool use=false;
        bool first=true;
        string tmp="";
        string result="";
        for(auto i:s){
            if(i==' '){
                if(use){
                    if(first){
                        result=tmp;
                        first=false;
                    }
                    else result=tmp +" "+ result;
                    tmp="";
                    use=false;
                }
            }
            else{
                tmp+=i;
                use=true;
            }
        }
        if(!tmp.empty())result=tmp +" "+ result;
        return result;
    }
};