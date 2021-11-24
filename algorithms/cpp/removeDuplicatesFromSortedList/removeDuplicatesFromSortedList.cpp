// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : https://github.com/xinsheng
// Date   : 2021-11-24

/*
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
 * Return the linked list sorted as well.
 */

#include <string.h>
#include <iostream>
#include <string>
using namespace std;

/*
 * Idea:
 * Iterate list one by one, skip the duplicated one.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret = head;
        ListNode* prevNode = NULL;
        while (head) {
			//skip the node that value equals previous one.
            if (prevNode && (prevNode->val == head->val))
            {
                prevNode->next = head->next;
            }
            else {
				//go forword one step
                prevNode = head;
            }
            head = head->next;
        }
        return ret;
    }
};
