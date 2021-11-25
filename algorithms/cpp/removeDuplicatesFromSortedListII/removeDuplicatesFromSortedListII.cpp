// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : https://github.com/xinsheng
// Date   : 2021-11-25

/*
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list. Return the linked list sorted as well.
 */

#include <string.h>
#include <iostream>
#include <string>
using namespace std;

/*
 * Idea:
 * My solution is easy understand, iterate the list, and prepare a temp list to store the temp data.
 * the final list always get data from the temp if not duplicate.
 
 * temp queue      3 3
 * main queue  1 2     4 4 5
 * final queue 1 2 
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
    ListNode* storeInList(ListNode* main, ListNode* add) {
        if (!main) {
            return add;
        }
        ListNode* ret = main;
        while (main->next) {
            main = main->next;
        }
        main->next = add;
        return ret;
    }

    bool isDuplicate(ListNode* main) {
        if (main && (main->next)) {
            return true;
        }
        return false;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* finalList = NULL;
        ListNode* tempList = NULL;

        ListNode* nextItem = NULL;
        while (head) {
            nextItem = head->next;
            head->next = NULL;

            if (tempList) {
                if (tempList->val == head->val) {
                    tempList = storeInList(tempList, head);
                }
                else {
					//if not duplicate, then store to finalList, else, abandon it.
                    if (!isDuplicate(tempList)) {
                        finalList = storeInList(finalList, tempList);
                    }
                   
                    //reset tempList and push new to tempList
                    tempList = NULL;
                    tempList = storeInList(tempList, head);
                }
            }
            else {
                tempList = storeInList(tempList, head);
            }
            head = nextItem;
        }
        if (tempList && (!isDuplicate(tempList))) {
            finalList = storeInList(finalList, tempList);
        }
        return finalList;
    }
};
