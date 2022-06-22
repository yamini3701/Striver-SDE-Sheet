/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;
        while(headA){
            hash.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(hash.find(headB) != hash.end())
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};
