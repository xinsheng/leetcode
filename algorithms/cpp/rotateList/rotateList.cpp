// Source : https://leetcode.com/problems/rotate-list/
// Author : https://github.com/xinsheng
// Date   : 2021-11-26

/*
 * Given the head of a linked list, rotate the list to the right by k places.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * Split list by k, then join both.
 */

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
    int listCount(ListNode* head) {
        int i = 0; 
        while (head) {
            head = head->next;
            i++;
        }
        return i;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        size_t n = listCount(head);
        if (k >= n) {
            k = k % n;
        }
        if ((k == 0) || (n == 1)) return head;

        ListNode* temp = head;

        ListNode* prev = NULL;
        for (size_t i = 0; i < (n - k); i++) {
            prev = temp;
            temp = temp->next;
        }
        ListNode* ans = temp;
        if(prev) prev->next = NULL;

        while (temp && temp->next) {
            temp = temp->next;
        }
        if(temp) temp->next = head;

        return ans;
    }
};

	