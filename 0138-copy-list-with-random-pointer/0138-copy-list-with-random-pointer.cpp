/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         // If the head is null, return null
        if (!head) return NULL;

        /*Create an unordered_map to map 
        original nodes to their corresponding copied nodes*/
        unordered_map<Node*, Node*> mpp;
        Node* temp = head;

        // Create copies of each node
        while (temp != NULL) {
            // Create new node with same value as original
            Node* newNode = new Node(temp->val);
            // Map to original node 
            mpp[temp] = newNode;
            // Move to next node
            temp = temp->next;
        }

        // Reset temp 
        temp = head;

        /*Connect the next and 
        random pointers of the 
        copied nodes using the map*/
        while (temp != NULL) {
            // Get copied node from the map
            Node* copyNode = mpp[temp];
            /*Set next pointer of copied node 
            to the copied node of the next 
            original node*/
            copyNode->next = mpp[temp->next];
            /*Set the random pointer of the 
            copied node to the copied node of 
            the random original node*/
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }

        // Return the head
        return mpp[head];
    }
};