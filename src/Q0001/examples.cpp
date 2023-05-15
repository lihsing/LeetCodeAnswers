#include "Q0001.h"

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
