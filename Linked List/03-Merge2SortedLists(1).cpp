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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *d, *dd = new ListNode();
        d = dd;
        while(l1 && l2){
            if(l1->val <= l2->val){
                dd->next = l1;
                l1 = l1->next;
            }
            else{
                dd->next = l2;
                l2 = l2->next;
            }
            dd = dd->next;
        }
        if(l1)
            dd->next = l1;
        if(l2)
            dd->next = l2;
        return d->next;
    }
};
