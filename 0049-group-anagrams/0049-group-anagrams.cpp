class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>tmp;
       for(auto s:strs){
            string key=s;
            sort(key.begin(),key.end());
            tmp[key].push_back(s);
       }

       vector<vector<string>>re;
       for(auto pair:tmp){
        re.push_back(pair.second);
       }
        return re;   
    }
};