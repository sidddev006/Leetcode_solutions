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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        if(head == NULL)
            return NULL;
        if(head-> next == NULL) {
            delete head;
            return NULL;
        }
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        n = len - n+1;
        if(n == 1){
            temp = head;
            head= head->next;
            delete temp;
            return head;
        }
        int cnt = 0;
        temp = head;
        ListNode* prev = NULL;
        while(temp!= NULL){
            cnt++;
            if(cnt == n){
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp= temp->next;
        }
        return head;
    }
};