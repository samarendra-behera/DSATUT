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

            //exclude
            slove(str, index + 1, output, result, mapper);

            //include
            char element = str[index];
            string value = mapper[element - '0'];
            for (int i = 0; i < value.length(); i++){
                output.push_back(value[i]);
                slove(str, index + 1, output, result, mapper);
                output.pop_back();
            }
        }
    
    public:
        vector<string> phoneKeyPad(string str){
            int index = 0;
            vector<string> result;
            string output = "";
            string mapper[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            slove(str, index, output, result, mapper);
            return result;
        }
};

int main(){
    return 0;
}