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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] != arr[arr.size()-i-1])
                return false;
        }
        return true;
    }
};
