/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        unordered_map<string, int> need;
        int count = 0;
        if (s.empty()  || words.size() == 0)
            return res;
        int one_word = words[0].length();
        int words_num = words.size();
        for (auto s : words)
        {
            need[s]++;
        }
        for (int i = 0; i < one_word; i++)
        {
            int left = i;
            int right = i;
            count = 0;
            unordered_map<string, int> temp;
            while (right + one_word <= s.size())
            {
                string s_word = s.substr(right, one_word);
                right += one_word;
                if (!need.count(s_word))
                {
                    //if(need[s_word] < temp[s_world])
                    /* code */
                    count = 0;
                    left = right;
                    temp.clear();
                }
                else
                {
                    temp[s_word]++;
                    count++;
                    //Warning 这里是while而不是if,只要是瞒住如下条件就要一直缩小
                    while (temp[s_word] > need[s_word]) //有重复字串需要缩小范围
                    {
                        /* code */
                        string removeStr = s.substr(left, one_word);
                        count--;
                        temp[removeStr]--;
                        left += one_word;
                    }
                    if (count == words_num)
                        res.push_back(left);
                }
            }
        }
        return res;
    }
};
// @lc code=end
