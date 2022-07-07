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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1){
            return head;   
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int count=0;
        ListNode *curr = dummy, *nexxt = dummy, *pre = dummy;
        while(curr->next != NULL){
            count++;
            curr = curr->next;
        }
        while(count >= k){
            curr = pre->next;
            nexxt = curr->next;
            for(int i=1 ; i<k ; i++){
                curr->next = nexxt->next;
                nexxt->next = pre->next;
                pre->next=nexxt;
                nexxt=curr->next;
            }
            pre = curr;
            count -=k;
        }
        return dummy->next;
    }
};
