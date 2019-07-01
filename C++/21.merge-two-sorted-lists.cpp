/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 * 
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *pt1 = l1, *pt2 = l2;
        ListNode *ptCur = new ListNode(-1);
        ListNode *ptNewList = ptCur;
        while(pt1 && pt2) {
            if(pt1->val <= pt2->val) {
                ptCur->next = pt1;
                pt1 = pt1->next;
            }
            else {
                ptCur->next = pt2;
                pt2 = pt2->next;
            }
            ptCur = ptCur->next;
        }
        ptCur->next = pt1 ? pt1 : pt2;
        return ptNewList->next;
    }
};

