/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        size_t count = s.length();
        int ans = 0;
        for (size_t i = 0; i < count; i++)
        {
            /* code */
            int num = s[i] - 'A' + 1;
            ans = ans * 26 + num;

        }
        return ans;
    
    }
};
// @lc code=end

