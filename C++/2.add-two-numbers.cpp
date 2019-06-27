/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryBit = 0;
        ListNode* tail = new ListNode(-1);
        ListNode* head = tail;
        while(l1 != NULL || l2 != NULL)
        {
            int tmp = (l1?l1->val:0) + (l2?l2->val:0) + carryBit;
            int val = tmp % 10;
            carryBit = tmp / 10;
            ListNode* next = new ListNode(val);
            tail->next = next;
            tail = next;
            
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        if(carryBit != 0)
        {
            ListNode* next = new ListNode(carryBit);
            tail->next = next;
            tail = next;
        }
        return head->next;
    }
};

