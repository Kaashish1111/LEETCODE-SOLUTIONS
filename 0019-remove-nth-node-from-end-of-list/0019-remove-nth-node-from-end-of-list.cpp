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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if (!head) return head;

        // 1. Count total number of nodes
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // 2. Find position from start to delete
        int pos = n - k + 1; // kth from end = (n-k+1)th from start

        // 3. Delete node at position 'pos'
        if (pos == 1) { // delete head
            ListNode* t = head;
            head = head->next;
            delete t;
            return head;
        }

        temp = head;
        ListNode* prev = nullptr;
        int count = 1;
        while (temp) {
            if (count == pos) {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }

        return head;
    }
};

// optimal approch -> 2pointer approch
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int k) {

//     }
// };