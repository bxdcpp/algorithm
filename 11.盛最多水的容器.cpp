/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
      int maxArea(vector<int>& height) {
        int s = 0;
        int len = height.size();
        int left = 0; int right = len - 1;
        while(left <= right)
        {
            s= max(s, (right - left) *min(height[left],height[right]));
            if(height[left] >= height[right])
                right--;
            else
                left++;
        }
        return s;

    }
};
// @lc code=end

