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
/*
Dry run of test Case:-
1->2->3->4->5 ; k = 2
k=1 - 5->1->2->3->4
k=2 - 4->5->1->2->3
k = 2, n = 5
k = 2 % 5 = 

*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        k = k%n; // this gives the number of rotation
        while(k > 0){
            ListNode* temp = head;
            head = temp;
            ListNode* prev = NULL;
            while(temp->next){
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;
            ListNode* newHead = temp;
            newHead->next = head;
            head = newHead;
            k--;
        }
        return head;
    }
};