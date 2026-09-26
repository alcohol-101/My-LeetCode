class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int max=1e9;
        vector<int>left(n,max),right(n,max);
        //处理左
        int i=0,cur=0;
        for(int j=0;j<n;j++){
            cur+=arr[j];
            while(cur>target){
                cur-=arr[i];
                i++;
            }
            if(cur==target)left[j]=j-i+1;
            if(j>0)left[j]=min(left[j],left[j-1]);
        }
        //处理右
        i=n-1;cur=0;
        for(int j=n-1;j>=0;j--){
            cur+=arr[j];
            while(cur>target){
                cur-=arr[i];
                i--;
            }
            if(cur==target)right[j]=i-j+1;
            if(j<n-1)right[j]=min(right[j+1],right[j]);
        }
        //左右求解
        int ans=1e5+1;
        for(int k=0;k<n-1;k++){
            ans=min(ans,left[k]+right[k+1]);
        }
        if(ans>1e5)return -1;
        return ans;
    }
};