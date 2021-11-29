// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : https://github.com/xinsheng
// Date   : 2021-11-29

/*
Given the head of a linked list, remove the n(th) node from the end of the list and return its head.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Idea:
Get the count of list first, and remove the count-n (th) from the start.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            temp = temp->next;
            count++;
        }
        if (count == n) {
            return head->next;
        }
        temp = head;

        int removeN = count - n;
        ListNode* prev = NULL;
        while (temp && (removeN>0)) {
            prev = temp;
            temp = temp->next;
            removeN--;
        }
        if (prev && temp) {
            prev->next = temp->next;
        }
        return head;
    }
};

	