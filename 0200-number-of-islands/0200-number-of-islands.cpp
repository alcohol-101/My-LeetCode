class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
       
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dr(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }

    void dr(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        if(i-1>=0)if(grid[i-1][j]=='1')dr(grid,i-1,j);
        if(i+1<grid.size())if(grid[i+1][j]=='1')dr(grid,i+1,j);
        if(j-1>=0)if(grid[i][j-1]=='1')dr(grid,i,j-1);
        if(j+1<grid[0].size())if(grid[i][j+1]=='1')dr(grid,i,j+1);
    }
};