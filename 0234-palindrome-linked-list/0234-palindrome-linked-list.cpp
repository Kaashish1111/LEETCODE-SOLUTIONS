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
        if (!head || !head->next) return true; // edge cases

        // Step 1: Find middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half starting from 'slow'
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Compare the first half and reversed second half
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;
        while (temp) {
            if (firstHalf->val != temp->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        // Optional Step 4: Restore the second half (if you want to keep list unchanged)
        // reverseList(secondHalf);

        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};