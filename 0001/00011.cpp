#include <vector>

using namespace std;


class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target);
};
vector<int> Solution::twoSum(vector<int> &nums, int target) {
    if (nums.size() < 2) {
        return {-1, -1};
    }
    for (int i=0; i<(nums.size()-1); ++i) {
        for (int j=i+1; j<nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}


void example1() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = Solution::twoSum(nums, 9);
    vector<int> expected = {0, 1};
    assert(ans == expected);
}


void example2() {
    vector<int> nums = {3, 2, 4};
    vector<int> ans = Solution::twoSum(nums, 6);
    vector<int> expected = {1, 2};
    assert(ans == expected);
}


void example3() {
    vector<int> nums = {3, 3};
    vector<int> ans = Solution::twoSum(nums, 6);
    vector<int> expected = {0, 1};
    assert(ans == expected);
}


int main() {
    example1();
    example2();
    example3();
    return 0;
}