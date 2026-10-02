class Solution {
private:
    vector<vector<bool>>tu;
    vector<int>use;
    int n;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        tu.resize(n,vector<bool>(n,false));
        use.resize(n,0);
        for(int i=0;i<prerequisites.size();i++){
            tu[prerequisites[i][0]][prerequisites[i][1]]=true;
        }
        for(int i=0;i<n;i++){
            if(use[i]==0&&dfs(i))return false;
        }
        return true;
    }

    bool dfs(int u){
        use[u]=1;
        for(int i=0;i<n;i++){
            if(tu[i][u]==true){
                if(use[i]==1)return true;
                else if(use[i]==0){
                    if(dfs(i))return true;
                }
                else if(use[i]==2){
                    continue;
                }
            }
        }
        use[u]=2;
        return false;
    }
};