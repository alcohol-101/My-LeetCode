class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>de;
        vector<int>re;
        for(int i=0;i<nums.size();i++){
            while(!de.empty()&&de.front()<i-k+1){
                de.pop_front();
            }
            while(!de.empty()&&nums[de.back()]<=nums[i]){
                de.pop_back();
            }
            de.push_back(i);

            if(i>=k-1)re.push_back(nums[de.front()]);
        }
        return re;

    }
};