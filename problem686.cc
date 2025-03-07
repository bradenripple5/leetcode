
#include <iostream>
#include <numeric>
#include <span>
#include <sstream>
#include <string>
#include <typeinfo>
#include <valarray>
#include <vector>
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

        for (const auto& row : pairs_copy_by_1st) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        return 0;
    }
};
// use bisection of list, but with doubling the range instead of cutting it down
// from the top
int findIndexOfNextHighestPair(vector<vector<int>> pairs, int startIndex,
                               int value_to_search,
                               int index_in_pair_to_search) {
    if (pairs[startIndex][index_in_pair_to_search] > value_to_search) {
        return startIndex;
    }
    if (pairs[size(pairs) - 1][index_in_pair_to_search] < value_to_search) {
        return  -1;
    }
    bool indexNotFound = true;
    int endIndex = startIndex + 1;
    int halfway_point;
    while (indexNotFound) {
        cout << startIndex << " " << endIndex << " " << "= startindex, end"
             << endl;
        if (pairs[endIndex][index_in_pair_to_search] > value_to_search) {

            if (startIndex + 1 == endIndex) {
                cout << "startIndex + 1 == endIndex" << endl;
                if (pairs[startIndex][index_in_pair_to_search] >
                    value_to_search) {
                    cout << "startIndex";

                    return startIndex;
                } else {
                    return endIndex;
                }
            } else {
                halfway_point = (endIndex + startIndex) / 2;
                if (pairs[halfway_point][index_in_pair_to_search] >
                    value_to_search) {
                    endIndex = halfway_point;

                } else {
                    startIndex = halfway_point;
                }
            }

        } else { // double the range
            endIndex = (endIndex - startIndex) * 2 + endIndex;
            if (endIndex > size(pairs) - 1) {
                endIndex = size(pairs) - 1;
            }
            // cout<<"endIndex = "<<endIndex<<endl;
        }
    }
    return 0;
}

int main() {
    Solution s;
    // vector<vector<int>> mynums = {{1,2},{2,3},{3,4}};

    vector<vector<int>> mynums = {{1, 2}, {3, 8}, {4, 5},{7,6}};
    sort(mynums.begin(), mynums.end(),
     [](const vector<int>& a, const vector<int>& b) {
         return a[1] < b[1];
     }); 
    int result = s.findLongestChain(mynums);
    result = findIndexOfNextHighestPair(mynums,0,7,1);

    cout << result << endl;
    return 0;
}
