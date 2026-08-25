class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>tmp;
        for(auto i:nums){
            tmp.insert(i);
        }
        int max=0;
        int cur=0;
        int before;
        for(auto t=tmp.begin();t!=tmp.end();t++){
            if(t==tmp.begin()){
                max=1;
                cur=1;
                before=*t;
                continue;
            }
            if(*t-1==before){
                cur++;
                max=max>cur?max:cur;
            }
            else cur=1;
            before=*t;
            
        }
        return max;
    }
};