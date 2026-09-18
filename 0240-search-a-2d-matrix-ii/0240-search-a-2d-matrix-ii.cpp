class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size()-1,n=0;
        while(true){
            if(n>matrix.size()-1||m<0)break;
            if(matrix[n][m]==target)return true;
            else if(matrix[n][m]<target)n++;
            else m--;
        }
        return false;
    }
};