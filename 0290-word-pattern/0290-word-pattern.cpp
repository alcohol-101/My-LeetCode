class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>m;
        unordered_map<string,char>n;
        stringstream ss(s);
        vector<string>word;
        string w;
        while(ss>>w){
            if(w!="")word.push_back(w);
            else break;
        }
        if(pattern.size()!=word.size())return false;
        int j=0;
        for(auto i:pattern){
            string wo=word[j++];
            if(!m.count(i)&&!n.count(wo)){
                m[i]=wo;
                n[wo]=i;
            }
            else if(m[i]==wo&&n[wo]==i)continue;
            else return false;
        }
        
        return true;
    }
};