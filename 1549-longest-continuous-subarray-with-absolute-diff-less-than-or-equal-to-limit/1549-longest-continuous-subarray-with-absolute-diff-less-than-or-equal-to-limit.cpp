class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       multiset<int>d;
       int best=0,l=0;
       for(int r=0;r<nums.size();r++){
            d.insert(nums[r]);
            while(*d.rbegin()-*d.begin()>limit){
                d.erase(d.find(nums[l]));
                l++;
            }
            best=max(best,r-l+1);
       }
       return best;
    }
};