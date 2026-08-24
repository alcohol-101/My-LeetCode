class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int max=min(height[i],height[j])*(height.size()-1);
        while(i<j){
            if(height[i]<height[j]){
                ++i;
                int cap=min(height[i],height[j])*(j-i);
                max=max>cap?max:cap;
            }
            else {
                --j;
                int cap=min(height[i],height[j])*(j-i);
                max=max>cap?max:cap;
            }
        }
        
        return max;
    }
};