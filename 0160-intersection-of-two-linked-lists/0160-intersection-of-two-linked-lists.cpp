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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Edge case
        if(headA == NULL || headB == NULL) return NULL;
        
        //Initialize two pointers to traverse the lists
        ListNode *d1 = headA;
        ListNode *d2 = headB;

        //Traverse both lists until the pointers meet
        while (d1 != d2) {
            
            // Move both the pointers by one place
            d1 = d1-> next;
            d2 = d2-> next;
            
            // If intersectionn is found
            if(d1 == d2) return d1;
            
            // If either of the two pointers reaches end, place at the front of next linked list 
            if(d1 == NULL) d1 = headB;
            if(d2 == NULL) d2 = headA;
            
            
        }
        return d1;
    }
};