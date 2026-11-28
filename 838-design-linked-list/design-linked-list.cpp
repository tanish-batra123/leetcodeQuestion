class Node {
public:
    int val;
    Node* next;

    Node() { next = NULL; }
    Node(int x) {
        val = x;
        next = NULL;
    }
};

class MyLinkedList {
public:
Node*head;
    MyLinkedList() { 
         head = NULL; 
    }

    int get(int index) {
        if (head == NULL)
            return -1;
        Node* temp = head;
        int idx = 0;
        while (temp != NULL) {
            if (idx == index)
                return temp->val;
            idx++;
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {

        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {

        Node* newNode = new Node(val);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        int idx = 0;
        while (temp != NULL && idx != index - 1) {
            temp = temp->next;
            idx++;
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtIndex(int index) {
        if (head == NULL)
            return;
        int idx = 0;
        if(index==0){
            Node*deletionNode=head;
            head=head->next;
            delete deletionNode;
            return;
        }
        Node* temp = head;
        while (temp != NULL && idx != index - 1) {
            temp = temp->next;
            idx++;
        }
        Node* deletionNode;
        if (temp != NULL && temp->next != NULL) {
            deletionNode = temp->next;
            temp->next = deletionNode->next;
            deletionNode->next = NULL;
            delete deletionNode;
        }
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