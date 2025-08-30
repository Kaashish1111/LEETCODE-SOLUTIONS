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
    int lengthoflinkedlist(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;  // edge cases
        
        int n = lengthoflinkedlist(head);
        k = k % n;
        if(k == 0) return head;

        // find the new tail at position (n-k-1)
        ListNode* temp = head;
        for(int i = 0; i < n-k-1; i++){
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = nullptr;

        // find old tail and connect to head
        ListNode* tail = newHead;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }
};
