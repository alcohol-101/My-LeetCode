class Solution {
    vector<string>result;
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>graph;
public:
    void dfs(string& now){
        while(!graph[now].empty()){
            string tmp=graph[now].top();
            graph[now].pop();
            dfs(tmp);
        }
        result.push_back(now);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& t:tickets){
            graph[t[0]].push(t[1]);
        }
        string beg="JFK";
        dfs(beg);
        reverse(result.begin(),result.end());
        return result;
    }

};