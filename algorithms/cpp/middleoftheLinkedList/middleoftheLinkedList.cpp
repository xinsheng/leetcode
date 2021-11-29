// Source : https://leetcode.com/problems/middle-of-the-linked-list/
// Author : https://github.com/xinsheng
// Date   : 2021-11-29

/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Idea:
Get the count of the list, and get the ceil of middle number.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int c = 0;
        while (temp) {
            temp = temp->next;
            c++;
        }
        int mid = ceil(c / 2);
        temp = head;
        while (mid) {
            temp = temp->next;
            mid--;
        }
        return temp;
    }
};
