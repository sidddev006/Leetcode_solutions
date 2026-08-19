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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* headm = new ListNode(0);
        ListNode* merge = headm;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val) {
                merge->next = temp1;
                temp1 = temp1->next;
                merge= merge->next;
            }
            else{
                merge->next = temp2;
                temp2 = temp2->next;
                merge= merge->next;
            }
        }
        /* This can be shortened by writing
        while(temp1){
            merge->next = temp1;
            temp1 = temp1->next;
            merge= merge->next;
        }
        while(temp2){
            merge->next = temp2;
            temp2 = temp2->next;
            merge= merge->next;
        }
        */
        merge->next = temp1 ? temp1 : temp2; // this works as either of them will be null after the initial while loop that i am running.
        return headm->next;//This should be headm->next as headm contains a value 0 which will disrupt the entire merged linked list
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        while(n > 1){
            int newSize = 0;
            for(int i = 0;i<n;i+=2){
                if(i+1 < n){
                    lists[newSize] = merge(lists[i], lists[i+1]);
                }
                else{
                    lists[newSize] = lists[i];
                }
                newSize++;
            }
            n = newSize;
        }
        return lists[0];
    }
};