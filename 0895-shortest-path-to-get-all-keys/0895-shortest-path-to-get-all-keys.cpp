class Solution {
    struct stats{
        int x,y;
        int mask;
    };
    vector<pair<int,int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int count=0,steps=0;
        pair<int,int>beg;
        int n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>='a'&&grid[i][j]<='z')count++;
                if(grid[i][j]=='@')beg={i,j};
                
            }
        }
        vector<vector<vector<bool>>>visited(grid.size(),
        vector<vector<bool>>(grid[0].size(),
        vector<bool>(1<<count)));
        queue<stats>q;

        visited[beg.first][beg.second][0]=true;
        q.push({beg.first,beg.second,0});

        while(q.size()!=0){
            steps++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                stats tmp=q.front();q.pop();
                for(auto [fx,fy]:dirs){
                    int x=tmp.x+fx,y=tmp.y+fy;
                    if(x<0||x>=n||y<0||y>=m||grid[x][y]=='#')continue;//出界或遇到墙壁
                    char cur_char=grid[x][y];

                    if(cur_char>='A'&&cur_char<='Z'){//碰到锁
                        if(!(tmp.mask&(1<<(cur_char-'A'))))continue;//没有对应的钥匙
                    }
                    int new_mask=tmp.mask;
                    if(cur_char>='a'&&cur_char<='z')
                    new_mask |=(1<<(cur_char-'a'));
                    if(new_mask==(1<<count)-1)return steps;
                    if(!visited[x][y][new_mask]){
                        visited[x][y][new_mask]=true;
                        q.push({x,y,new_mask});
                    }
                }
            }
        }
        return -1;
    }
};