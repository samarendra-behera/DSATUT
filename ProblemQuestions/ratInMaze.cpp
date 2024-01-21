#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution{
    private:
        bool isSafe(vector<vector<int>> m, int newx, int newy, int n,  vector<vector<int>> visited  ){
            if(newx>=0 && newx < n && newy>=0 && newy< n && visited[newx][newy]==0 && m[newx][newy]==1){
                return true;
            }
            else{
                return false;
            }
        }
        void slove(vector<vector<int>> m, int n, int srcx, int srcy, vector<vector<int>> visited, string path, vector<string> & ans){
            if (srcx==n-1 && srcy==n-1){
                ans.push_back(path);
                return ;
            }
            visited[srcx][srcy] = 1;

            // Down
            int newx = srcx + 1;
            int newy = srcy;
            if(isSafe(m, newx, newy, n, visited)){
                path.push_back('D');
                slove(m, n, newx, newy, visited, path, ans);
                path.pop_back();
            }

            // UP
            newx = srcx - 1;
            newy = srcy;
            if(isSafe(m, newx, newy, n, visited)){
                path.push_back('U');
                slove(m, n, newx, newy, visited, path, ans);
                path.pop_back();
            }

            // Left
            newx = srcx ;
            newy = srcy -1;
            if(isSafe(m, newx, newy, n, visited)){
                path.push_back('L');
                slove(m, n, newx, newy, visited, path, ans);
                path.pop_back();
            }

            // Right
            newx = srcx;
            newy = srcy +1;
            if(isSafe(m, newx, newy, n, visited)){
                path.push_back('R');
                slove(m, n, newx, newy, visited, path, ans);
                path.pop_back();
            }

            visited[srcx][srcy] = 0;

        }
    public:
        vector<string> findPath(vector<vector<int>> &m, int n){
            vector<string> ans ;
            if (m[0][0] == 0){
                return ans;
            }

            int srcx = 0;
            int srcy = 0;
            vector<vector<int>> visited = m;
            for (int i=0; i<n; i++){
                for (int j = 0; j< n; j++){
                    visited[i][j] = 0;
                }
            }
            string path = "";
            slove(m, n, srcx, srcy, visited, path, ans);
            sort(ans.begin(), ans.end());
            return ans;
        }

};

int main(){
    vector<vector<int>> input = {{1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1}};
    int n = 4;
    Solution obj;

    vector<string> ans = obj.findPath(input, n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}