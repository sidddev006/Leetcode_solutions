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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL|| head ->next == NULL) return head;
        ListNode dummy(0, head);
        ListNode* temp = &dummy;
        ListNode* point = head;
        while(point && point->next){
            if(point->val == point->next->val){
                int dupVal = point->val;
                while(point && point->val == dupVal){
                    point = point ->next;
                }
                temp->next = point;
            }
            else{
                temp = point;
                point = point->next;
            }
        }
        return dummy.next;
    }
};