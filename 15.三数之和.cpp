/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // n 为 3，从 nums[0] 开始计算和为 0 的三元组
        return nSumTarget(nums, 3, 0, 0);
    }

    /* 注意：调用这个函数之前一定要先给 nums 排序 */
    vector<vector<int>> nSumTarget(
        vector<int> &nums, int n, int start, int target)
    {
        int sz = nums.size();
        vector<vector<int>> res;
        // 至少是 2Sum，且数组大小不应该小于 n
        if (n < 2 || sz < n)
            return res;
        // 2Sum 是 base case
        if (n == 2)
        {
            // 双指针那一套操作
            int lo = start, hi = sz - 1;
            while (lo < hi)
            {
                int sum = nums[lo] + nums[hi];
                int left = nums[lo], right = nums[hi];
                if (sum < target)
                {
                    while (lo < hi && nums[lo] == left)
                        lo++;
                }
                else if (sum > target)
                {
                    while (lo < hi && nums[hi] == right)
                        hi--;
                }
                else
                {
                    res.push_back({left, right});
                    while (lo < hi && nums[lo] == left)
                        lo++;
                    while (lo < hi && nums[hi] == right)
                        hi--;
                }
            }
        }
        else
        {
            // n > 2 时，递归计算 (n-1)Sum 的结果
            for (int i = start; i < sz; i++)
            {
                vector<vector<int>>
                    sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int> &arr : sub)
                {
                    // (n-1)Sum 加上 nums[i] 就是 nSum
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                // 跳过第一个数字重复的情况，否则会出现重复结果
                while (i < sz - 1 && nums[i] == nums[i + 1])
                    i++;
            }
        }
        return res;
    }
};
// @lc code=end

