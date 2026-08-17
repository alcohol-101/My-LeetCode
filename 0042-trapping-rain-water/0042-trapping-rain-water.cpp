class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int left_max=height[0],right_max=height[height.size()-1];
        int cap=0;

        while(left<right){
            left_max=max(left_max,height[left]);
            right_max=max(right_max,height[right]);
            if(left_max<right_max){
                cap+=(left_max-height[left]);
                left++;
            }
            else {
                cap+=(right_max-height[right]);
                right--;
            }
            
        }
        return cap;
    }
};