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
// Definition for singly-linked list
class Solution {
public:
    // Helper function to delete a given node (singly linked list)
    ListNode* deleteNode(ListNode* head, ListNode* del) {
        if (head == NULL || del == NULL) return head;

        // If the node to delete is the head
        if (head == del) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Otherwise, find the node just before 'del'
        ListNode* prev = head;
        while (prev->next != NULL && prev->next != del) {
            prev = prev->next;
        }

        if (prev->next == del) {
            prev->next = del->next;
            delete del;
        }

        return head;
    }

    // Main function
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->val == val) {
                ListNode* nextNode = temp->next;
                head = deleteNode(head, temp);  // call helper
                temp = nextNode;                // move forward safely
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
