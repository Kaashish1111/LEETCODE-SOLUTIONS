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
    // Helper function to skip all nodes with the same value
    ListNode* skipDuplicates(ListNode* node) {
        int val = node->val;
        while (node != nullptr && node->val == val) {
            node = node->next;
        }
        return node; // first different node
    }

    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                // Found duplicates → skip them
                head = skipDuplicates(head);
                prev->next = head; 
            } else {
                // No duplicate → move forward
                prev = head;
                head = head->next;
            }
        }
        return dummy->next;
    }
};