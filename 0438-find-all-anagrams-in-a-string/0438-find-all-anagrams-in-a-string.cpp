class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())return {};
        vector<int>re;
        unordered_multiset<char>r;
        for(auto i:p){
            r.insert(i);
        }
        unordered_multiset<char>tmp;
        for(int i=0;i<p.size();i++){
            tmp.insert(s[i]);
        }
        if(tmp==r)re.push_back(0);
        for(int i=1;i<=s.size()-p.size();i++){
            tmp.erase(tmp.find(s[i-1]));
            tmp.insert(s[i+p.size()-1]);
        
            if(tmp==r)re.push_back(i);
        }
        return re;
    }
};