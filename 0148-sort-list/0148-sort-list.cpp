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
Merge Sort implementation from my brain
MergeSort(arr, low, high){
    if(low == high) return;
    mid = low + (high - low)/2;
    MergeSort(arr, low, mid-1);
    MergeSort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}
Merge(arr, low, mid, high){
    temp[];
    left = low;
    right = mid + 1;
    while(left <= mid && right <= n){
    if(arr[left] < arr[right]){
    temp.add(arr[left]);
    left++;
    }
    else{
    temp.add(arr[right]);
    right++;
    }
    }
    while(left <= mid){
    temp.add(arr[left]);
    }
    while(right <= high){
    temp.add(arr[right]);
    }
    for(int i = low; i<=high;i++){
        arr[i] = temp[i-low];
    }
}
*/
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy;
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }        
            tail->next = l1 ? l1: l2;
            return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rightHalf = slow->next;
        slow ->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);

        return merge(left, right);
    }
};