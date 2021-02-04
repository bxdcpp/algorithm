/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int maxSpeed =  *max_element(piles.begin(),piles.end()); 
        int minSpeed = 1;
        int midSpeed;
        while(minSpeed <= maxSpeed)
        {
            midSpeed = minSpeed + (maxSpeed - minSpeed)/2;            
            if (eatingTime(piles,midSpeed,H))
            {
                maxSpeed = midSpeed - 1;
            }
            else
            {
                minSpeed = midSpeed + 1;
            }
        }
        return minSpeed;

    }
   bool eatingTime(vector<int>&pile,int speed,int h){
       int eatTime = 0;
       int count = pile.size();
       for (size_t i = 0; i < count; i++)
       {
           eatTime += pile[i]/speed + ((pile[i]%speed) ? 1:0); 
       }
       return eatTime <= h ? true : false;

   }
};
// @lc code=end

