
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
//use bisection of list, but with doubling the range instead of cutting it down from the top
int findIndexOfNextHighestPair( vector<vector<int>> pairs,int startIndex , int value_to_search, int index_in_pair_to_search){
    if (pairs[startIndex][index_in_pair_to_search] > value_to_search){ return startIndex; }
    bool indexNotFound = true;
    int endIndex = startIndex + 1;
    int halfway_point
    int difference
    while (indexNotFound){
        if (pairs[index_in_pair_to_search][endIndex] > value_to_search){
            
            if (startIndex+1 == endIndex){
                return endIndex
            }
  
        } else { //double the range 
            endIndex = (endIndex-startIndex)*2 + endIndex
            

        }

    }
    return index;
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
