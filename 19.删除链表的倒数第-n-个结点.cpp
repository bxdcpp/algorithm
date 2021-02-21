/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        if (head == nullptr){
            return head;
        }
        
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        while(fast && fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        //如果n = ListNode length
        if(fast == nullptr)
            return head->next;
        slow->next = slow->next->next;
        return head;
    }
};
// @lc code=end

