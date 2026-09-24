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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        while(prev->next && prev->next->next){
            ListNode* first = prev->next;
            ListNode* second = first->next;
            //prev->next first->next second->next
            first->next = second->next;
            second->next= first;
            prev->next = second;
            prev = first;
        }
        return dummy->next;
    }
};
/*
1->2->3->4
swap(1,2)-> 2->next = 1, 1->next = 2->next; 2->1
swap(3,4)-> 4->next = 3, 3->next = 4->next; 2->1->4-3
*/