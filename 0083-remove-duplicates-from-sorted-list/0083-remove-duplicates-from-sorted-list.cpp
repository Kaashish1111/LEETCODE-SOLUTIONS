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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;  // empty list case

        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                // skip the duplicate node
                ListNode* duplicate = curr->next;
                curr->next = curr->next->next;
                delete duplicate; // free memory
            } else {
                curr = curr->next; // move forward only if no duplicate
            }
        }

        return head;
    }
};