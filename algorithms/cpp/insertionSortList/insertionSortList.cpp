// Source : https://leetcode.com/problems/insertion-sort-list/
// Author : https://github.com/xinsheng
// Date   : 2021-12-15

/*
Discuss:
https://leetcode.com/problems/insertion-sort-list/discuss/1629635/Super-Clear-C%2B%2B-Solution
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* insert(ListNode* ans, ListNode* item){
        ListNode* first = ans;
        if(!ans) return item;
        if(item->val <= ans->val){
            item->next = ans;
            return item;
        }
        
		while (ans) {
			if (ans->next && item->val >= ans->val && item->val <= ans->next->val) {
				item->next = ans->next;
				ans->next = item;
				break;
			}
			if (!ans->next) {
				ans->next = item;
				break;
			}
			ans = ans->next;
		}
        return first;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans = NULL;
        while(head){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            ans = insert(ans, temp);
        }
        return ans;
    }
};