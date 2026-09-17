class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        zhuanzhi(matrix);
        nixu(matrix);
    }

    void zhuanzhi(vector<vector<int>>& m){
        for(int i=0;i<m.size();i++){
            for(int j=0;j<i;j++){
                std::swap(m[i][j],m[j][i]);
            }
        }
    }

    void nixu(vector<vector<int>>& m){
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size()/2;j++){
                std::swap(m[i][j],m[i][m[0].size()-j-1]);                        
            }
        }
    }
};