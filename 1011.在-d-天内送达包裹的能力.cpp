/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        // 载重可能的最小值
        int left = *max_element(weights.begin(),weights.end()); 
        // 载重可能的最大值 + 1
        int right = getSum(weights) + 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canFinished(weights, D, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    bool canFinished(vector<int>&weights,int D, int capability){
        int cur = capability;
        for (auto w : weights)
        {
            if (w > capability)
                return false;
                if (cur < w)
                {
                    cur = capability;
                    D--;

                   
                }
                 cur -= w;
            
        }
        return D > 0;
    }
    int getSum(std::vector<int>& nums)
    {
        int sum = 0;
        for (auto n : nums)
        {
            sum += n;
        }
        return sum;
    }
};
// @lc code=end

