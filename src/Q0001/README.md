# 第一题：两数之和

## 解法一

取该数组的所有2个元素的组合，判断这两个元素的和是否为target，如果为target则返回这两个元素的下标。

```c++
vector<int> Solution::twoSum(vector<int> &nums, int target) {
    if (nums.size() < 2) {
        return {};
    }
    for (int i=0; i<(nums.size()-1); ++i) {
        for (int j=i+1; j<nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}
```

## 解法二

建立一个哈希表map，对于数组的任意一个元素num，判断target-num是否存在于map。如果不存在，则以num为健，num的下标为值插入到哈希表中。如果存在，则
返回num的下标和map中target-num的下标。

```c++
vector<int> Solution::twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i=0; i<nums.size(); ++i) {
        auto it = map.find(target-nums[i]);
        if (it != map.end()) {
            return {it->second, i};
        }
        map.insert(pair<int, int>{nums[i], i});
    }
    return {};
}
```