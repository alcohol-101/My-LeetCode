class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>answer(nums.size());
        int l=0,r=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                answer[i]=accumulate(nums.begin()+1,nums.end(),0);
            }
            else if(i==nums.size()-1){
                answer[i]=accumulate(nums.begin(),nums.end()-1,0);
            }
            else{
                l=accumulate(nums.begin(),nums.begin()+i,0);
                r=accumulate(nums.begin()+i+1,nums.end(),0);
                answer[i]=abs(r-l);
            }
        }
        return answer;
    }
};