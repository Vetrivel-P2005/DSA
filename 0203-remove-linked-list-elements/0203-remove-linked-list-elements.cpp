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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *pre = nullptr,*cur = head;
        while(cur){
            if(cur->val==val){
                if(!pre)head = cur->next;
                else pre->next = cur->next;
            }
            else
                pre = cur;
            cur = cur->next;
        }
        return head;
    }
};