#include <iostream>
#include <vector> 
using namespace std;

class Solution {
    private:
        void slove(vector<int>& nums, int index, vector<int> output, vector<vector<int>>& powerset) {
            // base case
            if (index >= nums.size()){
                powerset.push_back(output);
                return;
            }

            // exclude
            slove(nums, index + 1, output, powerset);

            // include
            int element = nums[index];
            output.push_back(element);
            slove(nums, index + 1, output, powerset);
        }
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> powerset;
            vector<int> output;
            int index = 0;
            slove(nums, index, output, powerset);
            return powerset;
        }
};


int main(){
    vector<int> arr = {1,2,3};
    Solution obj;
    vector<vector<int>> ans = obj.subsets(arr);
    for (int i = 0; i < ans.size(); i++){
        cout<<"{";
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "} ";
        cout << endl;
    }
    return 0;
}