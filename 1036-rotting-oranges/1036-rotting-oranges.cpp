class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minu=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        pair<int,int> dirs[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            int n=q.size();
            bool has_gr=false;
            for(int i=0;i<n;i++){
                pair<int,int>p=q.front();q.pop();
                grid[p.first][p.second]=0;
                for(auto [di,dj]:dirs){
                    int i=p.first+di,j=p.second+dj;
                    if(i>=0&&j>=0&&i<grid.size()&&j<grid[0].size()){
                        if(grid[i][j]==1){
                            grid[i][j]=2;
                            q.push({i,j});
                            has_gr=true;
                        }
                    }
                }
            }
            if(has_gr)minu++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return minu;
    }
};