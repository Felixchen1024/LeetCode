/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 * 
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * 
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 
 * Note:
 * Given n will always be valid.
 * 
 * Follow up:
 * Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n <= 0) return nullptr;

        //new a sentry, to deal the situation that the n is head
        ListNode *tmpHead = new ListNode(-1);
        tmpHead->next = head;
        ListNode *ptA = tmpHead, *ptB = tmpHead;
        //ptA - ptB = n
        for(int m=0;m<n;m++) {
            if(ptA->next)
                ptA = ptA->next;
            else
                return nullptr;
        }
        //ptA ptB walk
        while(ptA->next) {
            ptA = ptA->next;
            ptB = ptB->next;
        }
        //delete n
        ptB->next = ptB->next->next;
        return tmpHead->next;
    }
};

