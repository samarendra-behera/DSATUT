#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    private:
        void slove(string str, int index, vector<string>& result){
            if (index >= str.length()){
                result.push_back(str);
                return;
            }
            for (int i = index; i < str.length(); i++){
                swap(str[index], str[i]);
                slove(str, index+1, result);
                //backtrack
                swap(str[index], str[i]);
            }
        }
    public:
        vector<string> permutation(string str){
            vector<string> result;
            if (str.size()==0){
                return result;
            }
            int index = 0;
            slove(str, index, result);
            return result;
        }
};

int main(){
    string str = "ABC";
    Solution obj;
    vector<string> ans = obj.permutation(str);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}