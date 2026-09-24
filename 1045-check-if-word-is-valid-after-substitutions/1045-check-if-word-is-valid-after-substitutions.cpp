class Solution {
public:
    bool isValid(string s) {
        stack<char>q;
        for(auto i:s){
            if(i=='a')q.push(i);
            else if(i=='b'){
                if(q.empty())return false;
                if(q.top()!='a')return false;
                q.push(i);
            }
            else if(i=='c'){
                if(q.empty())return false;
                if(q.top()!='b')return false;
                q.pop();
                q.pop();
            }
        }
        if(!q.empty())return false;
        return true;
    }
};