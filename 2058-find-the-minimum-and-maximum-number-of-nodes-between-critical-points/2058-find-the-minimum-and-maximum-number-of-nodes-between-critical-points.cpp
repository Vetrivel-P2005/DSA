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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        
        int first_cp = -1;
        int prev_cp = -1;
        int min_dist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int curr_idx = 1; 
        
        while (curr->next != nullptr) {
            ListNode* next_node = curr->next;
            
            bool is_maxima = (curr->val > prev->val && curr->val > next_node->val);
            bool is_minima = (curr->val < prev->val && curr->val < next_node->val);
            
            if (is_maxima || is_minima) {
                if (first_cp == -1) {
                    first_cp = curr_idx;
                } else {
                    min_dist = min(min_dist, curr_idx - prev_cp);
                }
                prev_cp = curr_idx;
            }
            
            prev = curr;
            curr = next_node;
            curr_idx++;
        }
        
        if (first_cp == prev_cp) {
            return {-1, -1};
        }
        
        int max_dist = prev_cp - first_cp;
        return {min_dist, max_dist};
    }
};