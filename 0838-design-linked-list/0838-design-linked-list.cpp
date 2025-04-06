class MyNode {
public: 
    int val;
    MyNode* next;
    MyNode(int x): val(x), next(NULL) {};
};

class MyLinkedList {
public:
    MyNode* head;

    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        MyNode *temp;
        temp = head;

        while (index != 0 && temp)  {
            temp = temp->next;
            --index;
        }

        if (temp == NULL) // Check if temp is null before dereferencing
            return -1;

        return temp->val;
    }
    
    void addAtHead(int val) {
        MyNode* new_node = new MyNode(val);
        new_node->next = head;
        head = new_node;
    }
    
    void addAtTail(int val) {
        MyNode* new_node = new MyNode(val);
        if (head == NULL) {
            head = new_node;
            return;
        }

        MyNode* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = new_node;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        MyNode* new_node = new MyNode(val);
        MyNode* current = head;

        while(index > 1 && current != NULL)
        {
            current = current->next;
            --index;
        }

        if (current == NULL) {  // If index is greater than the length of the list, do nothing
            delete new_node;
            return;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
    

    void deleteAtIndex(int index) {
        if (head == NULL) return;

        MyNode* current = head;
        if (index == 0) {  // If the index is 0, update head
            head = head->next;
            delete current;
            return;
        }

        while(index != 1 && current->next != NULL)
        {
            current = current->next;
            --index;
        }
        if (current->next == NULL) return;  // If index is out of bounds, do nothing
        
        MyNode* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */