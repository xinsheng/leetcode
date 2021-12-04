// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : https://github.com/xinsheng
// Date   : 2021-12-04

/*
Discuss:
https://leetcode.com/problems/reverse-linked-list/discuss/1610433/C%2B%2B-or-Clear-and-Minimal-lines-of-code-or-Faster-than-96
 */

#include <string.h>
#include <iostream>
#include <string>
using namespace std;

/*
Idea:
Make new node at head, and following the previous list
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = NULL;
        while (head) {
            current = new ListNode(head->val, current);//make new node at head
            head = head->next;
        }
        return current;
    }
};
