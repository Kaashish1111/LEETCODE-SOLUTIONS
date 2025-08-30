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
// class Solution {
// public:
//     // Function to merge two sorted linked lists
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         vector<int> arr;
//         ListNode* temp1 = list1;
//         ListNode* temp2 = list2;

        
//         // Add elements from list1 to the vector
//         while(temp1 != NULL){
//             arr.push_back(temp1->val); 
//             // Move to the next node in list1
//             temp1 = temp1->next; 
//         }

//         // Add elements from list2 to the vector
//         while(temp2 != NULL){
//             arr.push_back(temp2->val);
//             // Move to the next node in list2
//             temp2 = temp2->next; 
//         }

//         // Sorting the vector in ascending order
//         sort(arr.begin(), arr.end());

//         // Sorted vector to linked list
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* temp = dummyNode;
//         for(int i = 0; i < arr.size(); i++){
//             temp->next = new ListNode(arr[i]); 
//             temp = temp->next; 
//         }

//         // Return the head of 
//         // merged sorted linked list
//         return dummyNode->next; 
//     }
// };

// optimal
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as
        // the head of the merged list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // Traverse both lists simultaneously
        while (list1 != nullptr && list2 != nullptr) {
            /*Compare elements of both lists
            and link the smaller node
            to the merged list*/
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move the temporary pointer
            // to the next node
            temp = temp->next;
        }

        /*If any list still
        has remaining elements,
        append them to the merged list*/
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return merged list
        return dummyNode->next;
    }
};