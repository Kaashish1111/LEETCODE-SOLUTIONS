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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
             // Move slow one step
            slow = slow->next;
            
            // Move fast two steps
            fast = fast->next->next;

            // If slow and fast meet,
            // a loop is detected
            if (slow == fast) {
                
                // Reset the slow pointer
                // To the head of the list
                slow = head;

                // Phase 2: Find the first node of the loop
                while (slow != fast) {
                    
                    // Move slow and fast one step
                    // At a time
                    slow = slow->next;
                    fast = fast->next;

                    // When slow and fast meet again,
                    // It's the first node of the loop
                }
                
                // Return the first node of the loop
                return slow;
            }
        }
        
        //If no loop is found, 
        //Return NULL
        return NULL;
    }
};