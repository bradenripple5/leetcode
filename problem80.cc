
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


    int removeDuplicates(vector<int>& nums) {
        if (size(nums) <2) { return size(nums); }
        int duplicateCount = 0;
        int current_index = 0;
        int lastIndex = size(nums) - 1;
        for (int i = 0; i < size(nums) - 1; i++) {
            //cout<<std::to_string(i)<<std::to_string(duplicateCount)<<std::to_string(current_index)<<endl;
      
            if (duplicateCount < 2) {
                cout <<"if (duplicateCount < 2) {"<<endl;
                nums[current_index] = nums[i];
                current_index++;
            }

            if (nums[i] != nums[i + 1]) {
                duplicateCount = 0;
            } else {
                duplicateCount++;
            }
        }

        if (nums[lastIndex] != nums[lastIndex - 1] || duplicateCount < 2) {
            //cout<<"last if"<<endl;
            // //cout << std::to_string(nums[lastIndex])
            //      << std::to_string(nums[current_index]);
            nums[current_index] = nums[lastIndex];
            current_index++;
        }
        return current_index;
    }

};

    string join(const std::vector<int>& vec, const std::string& delimiter) {
        if (vec.empty()) {
            return "";
        }
        return std::accumulate(std::next(vec.begin()), vec.end(), std::to_string(vec[0]),
        [&](std::string a, int b) {
            return a + delimiter + std::to_string(b);
        });
    }


int main() {
    Solution s;
    vector<int> mynums = {1,1,1,1,1};

    unsigned int result = s.removeDuplicates(mynums);
    vector<int> slice = vector<int>(mynums.begin() , mynums.begin()+result);
    cout<<join(slice,",");
    return 0;
}



