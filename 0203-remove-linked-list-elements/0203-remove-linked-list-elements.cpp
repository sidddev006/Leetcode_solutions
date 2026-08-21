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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        if(head -> next == NULL && head->val == val) return NULL;
        ListNode dummy(0, head);
        ListNode* temp = &dummy; // lets treat this as a answer
        ListNode* point = head; // lets treat this as a loop variable
        while(point){
            if(point->val != val){
                temp->next = point;
                temp = temp->next;
            }
            point = point->next;
        }
        temp->next = NULL;
        return dummy.next;
    }
};