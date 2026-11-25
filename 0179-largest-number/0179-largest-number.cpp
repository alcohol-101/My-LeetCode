class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        str.reserve(nums.size());
        for(auto s:nums)str.push_back(to_string(s));

        sort(str.begin(),str.end(),[](const string& a,const string& b){
            return a+b>b+a;
        });
        if(str[0]=="0")return "0";
        string re;
        for(auto& s:str)re+=s;
        return re;
    }
};