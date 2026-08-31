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
/*
Dry run of testcase
5->3->1->2->5->1->2
vector<int> critical_point;
curr, prev, next and a iterator like i = 0->length of linked list;
if curr>prev && curr>next critical_point.push_back(i)
else curr<prev && curr<next critical_point.push_back(i);
*/
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL) return {-1, -1};
        vector<int> critical_point;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        ListNode* next = head->next;
        int i=0;
        while(next!= NULL){
            if(i==0){
                prev = curr;
                curr = curr->next;
                next = next->next;
                i++;
                continue;
            }
            if(prev->val > curr->val && next->val > curr->val) critical_point.push_back(i);
            else if(prev->val < curr->val && next->val < curr->val)
            critical_point.push_back(i);
            i++;
            prev = curr;
            curr = curr->next;
            
            next = next->next;
        }
        int n = critical_point.size();
        if(n < 2) return {-1,-1};
        int minDist = INT_MAX;
        for(int j = 1; j<n;j++){
            minDist = min(minDist, critical_point[j] - critical_point[j-1]);
        }
        int maxDist = critical_point[n-1] - critical_point[0];
        return {minDist, maxDist};
    }
};