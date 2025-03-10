#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <span>
#include <sstream>
#include <string>
#include <typeinfo>
#include <valarray>
#include <vector>

using namespace std;

bool compareVectors(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

string join_vector(const std::vector<int>& vec, const std::string& delimiter) {
    if (vec.empty()) {
        return "";
    }

    std::stringstream ss;
    ss << vec[0];

    for (size_t i = 1; i < vec.size(); ++i) {
        ss << delimiter << vec[i];
    }

    return ss.str();
}

string joinVectorOfVectors(const vector<vector<int>>& vec) {
    stringstream ss;
    for (const auto& innerVec : vec) {
        for (size_t i = 0; i < innerVec.size(); ++i) {
            ss << innerVec[i];
            if (i < innerVec.size() - 1) {
                ss << ",";
            }
        }
        ss << "},{";
    }
    return "{{" + ss.str() + "}}";
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        if (size(pairs) < 2)
            return size(pairs);
        sort(pairs.begin(), pairs.end(), compareVectors);
        cout << joinVectorOfVectors(pairs) << endl;

        int index = 0;
        int ct = 1;
        bool addable;

        for (int i = 1; i < size(pairs); i++) {

            // i don't want ct to increment unless i see another pair of pairs
            // (a,b) and (c,d) where a<b<c<d;

            addable = (pairs[index][1] < pairs[i][0]);
            // if (addable) {
            //     cout<<" "<<i<<" "<<index<<" "<<join_vector(pairs[index],
            //     ":")<<" "<<join_vector(pairs[i], ":")<<endl;
            // }

            index = index * (!addable) + i * (addable);

            ct = ct + addable;
        }

        return ct;
    }
};



  

int main() {
    Solution s;
    vector<vector<int>> mynums = {{1,2},{2,3},{3,4}};
    mynums  = {{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
        mynums = {{1, 2},{3,5},{4, 5},{3, 8},  {2,11},{9, 14}};

    mynums = {{-2,1},{3,7},{0,10},{-1,8},{0,7},{8,9},{7,10},{-9,-3},{-4,-3},{0,6}};
    // mynums = {{1, 2},{3,5},{4, 5},{3, 8},  {2,11},{9, 14}};

    int result = s.findLongestChain(mynums);
    cout << (result) << endl;
    // mynums = {{1,2},{7,8},{4,5}};
    // result = s.findLongestChain(mynums);
    // cout << (result);

    return 0;
}