#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    private:
        void slove(string str, int index, string output, vector<string>& result, string mapper[]){
            //base case
            if (index >= str.size()){
                result.push_back(output);
                return;
            }
            int number = str[index] - '0';
            string value =mapper[number];
            for (int i = 0; i< value.size(); i++){
                output.push_back(value[i]);
                slove(str, index+1, output, result, mapper);
                output.pop_back();
            }
            
        }
    
    public:
        vector<string> phoneKeyPad(string str){
            vector<string> result;
            if (str.size() == 0){
                return result;
            }
            int index = 0;
            string output = "";
            string mapper[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            slove(str, index, output, result, mapper);
            return result;
        }
};

int main(){
    string str = "23";
    Solution obj;
    vector<string> ans = obj.phoneKeyPad(str);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}