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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* oddDummy = new ListNode(-1);
        ListNode* evenDummy = new ListNode(-1);
        ListNode* odd = oddDummy;
        ListNode* even = evenDummy;
        
        ListNode* temp = head;
        int index = 1; // Track the position/index
        
        while (temp != nullptr) {
            if (index % 2 != 0) { // Check position, not value
                odd->next = temp;
                odd = odd->next;
            } else {
                even->next = temp;
                even = even->next;
            }
            temp = temp->next;
            index++;
        }
        
        // Terminate list
        even->next = nullptr;
        // Merge odd and even lists
        odd->next = evenDummy->next;
        return oddDummy->next;
    }
};