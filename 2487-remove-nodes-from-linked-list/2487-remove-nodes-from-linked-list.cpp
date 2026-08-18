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
/* This was a case of extreme brute force -_-
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL||head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* nextNode = temp->next;
            int count = 0;
            while(nextNode != NULL  && nextNode->val <= temp->val ){
                nextNode = nextNode->next;
            }
            if(nextNode != NULL) {
                if(temp == head){
                    head = head->next;
                    temp = head;
                }
                else{
                    prev->next = temp->next;
                    temp = prev->next;
                }
            }
            else{
                prev = temp;
                temp = temp->next;
            }            
        }
        return head;
    }
    */
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head){
        head = reverseLL(head);
        ListNode* temp = head;
        ListNode* prev = NULL;
        int maxi = INT_MIN;
        while(temp){
            ListNode* nextNode = temp->next;
            if(temp->val < maxi){
                if(prev) prev->next = nextNode;
            }
            else  {
                maxi = temp->val;
                prev = temp;
            }
            temp = nextNode; 
        }
        head = reverseLL(head);
        return head;
    }
};