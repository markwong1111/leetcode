struct Node {
    int val; 
    Node* next;

    Node() : val(0), next(nullptr) {}
};


/**
 * Merge Two Sorted Linked Lists
 * 
 * Given two sorted linked lists, merge them into a single sorted linked list.
 */
Node* mergeTwoLists(Node* list1, Node* list2) {
    Node* dummy = new Node();
    Node* cur = dummy;

    while (list1 and list2) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        }
        else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }   

    cur->next = list1 ? list1 : list2;

    return dummy->next;
}


/**
 * Reverse Linked List
 * 
 * Reverse a linked list.
 */
Node* reverseList(Node* head) {
    Node* node = nullptr;
    
    while (head != nullptr) {
        Node* temp = head->next;
        head->next = node;
        node = head;
        head = temp;
    }

    return node;    
}


/**
 * Linked List Cycle
 * 
 * Given a linked list, check if the list contains a cycle.
 */
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;  
        
        if (slow == fast) {
            return true;
        }
    }

    return false;
}