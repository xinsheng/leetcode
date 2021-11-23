// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : https://github.com/xinsheng
// Date   : 2021-11-22

/*
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
 * Idea:
 * Prepare a single list to store result, then pick each list element insert to result list in right place. 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertVal(ListNode* l, int v) {
        if (!l) {
            return new ListNode(v);
        }

        ListNode* t = l;
        while (t) {
            if ( (v >= t->val)) {
                if (t->next) {
                    if (v <= t->next->val) {
                        ListNode* tmp = new ListNode(v, t->next);
                        t->next = tmp;
                        break;
                    }
                }
                else {
                    ListNode* tmp = new ListNode(v, t->next);
                    t->next = tmp;
                    break;
                }
            } else {
                //insert head
                ListNode* tmp = new ListNode(v, t);
                l = tmp;
                break;
            }
            t = t->next;
        }
        return l;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = NULL;
        for(size_t i =0; i < lists.size(); i++)
        {
            ListNode* current = lists[i];
            while (current) {
                ret = insertVal(ret, current->val);
                current = current->next;
            }
        }

        return ret;
    }
};