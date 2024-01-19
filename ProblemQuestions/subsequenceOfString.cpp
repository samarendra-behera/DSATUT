#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    private:
        void slove(string str, int index, string output, vector<string>& result){
            // base case
            if (index >= str.size()){
                result.push_back(output);
                return;
            }

            //exclude 
            slove(str, index + 1 , output, result);

            //include
            char element = str[index];
            output.push_back(element);
            slove(str, index + 1, output, result);
        }
    public:
        vector<string> subsequences(string str){
            int index = 0;
            vector<string> result;
            string output = "";
            slove(str, index, output, result);
            return result;
        }

};

int main(){
    string str = "abc";
    Solution obj;
    vector<string> ans = obj.subsequences(str);
    for (int i = 0; i < ans.size(); i++){
        cout <<"{"<< ans[i] << "}"<< endl;
    }
    return 0;
}