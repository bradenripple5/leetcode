
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <valarray>
#include <typeinfo>
#include <span>
using namespace std;



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        vector<vector<int>> pairs_copy_by_0th = pairs;
        vector<vector<int>> pairs_copy_by_1st = pairs;
        vector<vector<int>> chains = pairs;


        sort(pairs_copy_by_0th.begin(), pairs_copy_by_0th.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });


        sort(pairs_copy_by_1st.begin(), pairs_copy_by_1st.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];

             });

        sort(chains.begin(), chains.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0] && a[1] < b[1];

             });

        for (const auto& row : chains) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        return 0;
    }
};

int findIndexOfNextHighestPair( vector<vector<int>> pairs){

    return 0;
}

int main() {
    Solution s;
    // vector<vector<int>> mynums = {{1,2},{2,3},{3,4}};

    vector<vector<int>> mynums = {{1,2},{3,8},{4,5}};

    int result = s.findLongestChain(mynums);
    cout<<result<<endl;
    // vector<int> slice = vector<int>(mynums.begin() , mynums.begin()+result);
    // cout<<join(slice,",");
    return 0;
}
