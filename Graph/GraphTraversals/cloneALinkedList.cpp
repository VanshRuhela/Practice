/*=============================================================================
#  PROBLEM:           Clone a linked list with next and random pointer | Set 1

You are given a Double Link List with one pointer of each node pointing to the
next node just like in a single link list. The second pointer however CAN point
to any node in the list and not just the previous node. Now write a program in
O(n) time to duplicate this list. That is, write a program which will create a
copy of this list.

Let us call the second pointer as arbit pointer as it can point to any arbitrary
node in the linked list.


***** Algo ******
The idea is to use Hashing. Below is algorithm.

Traverse the original linked list and make a copy in terms of data.
Make a hash map of key value pair with original linked list node and copied
linked list node. Traverse the original linked list again and using the hash map
adjust the next and random reference of cloned linked list nodes.


=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next, *random;

    Node(int data) {
        this->data = data;
        this->next = this->random = NULL;
    }
};

class LinkedList {
   public:
    Node* head;

    LinkedList(Node* head) { this->head = head; }

    void push(int data) {  // pushes data to the head
        Node* node = new Node(data);
        node->next = head;
        head = node;
    }

    void print() {  // printing the linked list

        Node* temp = head;
        while (temp != NULL) {
            Node* random = temp->random;
            int randomData = (random != NULL) ? random->data : -1;

            cout << "Data :" << temp->data << ", ";
            cout << "Random Data :" << randomData << "\n";

            temp = temp->next;
        }
        cout << "\n";
    }
    // Actual clone method which returns
    // head reference of cloned linked
    // list
    LinkedList* clone() {
        Node* origCurr = head;
        Node* cloneCurr = NULL;

        unordered_map<Node*, Node*> mymap;

        while (origCurr != NULL) {
            cloneCurr = new Node(origCurr->data);
            mymap[origCurr] = cloneCurr;
            origCurr = origCurr->next;
        }

        origCurr = head;

        while (origCurr != NULL) {
            cloneCurr = mymap[origCurr];
            cloneCurr->next = mymap[origCurr->next];
            cloneCurr->random = mymap[origCurr->random];
            origCurr = origCurr->next;
        }

        return new LinkedList(mymap[head]);
    }
};

int main() {
    LinkedList* mylist = new LinkedList(new Node(5));
    mylist->push(4);
    mylist->push(3);
    mylist->push(2);
    mylist->push(1);

    // setting random pointers
    mylist->head->random = mylist->head->next->next;

    mylist->head->next->random = mylist->head->next->next->next;

    mylist->head->next->next->random = mylist->head->next->next->next->next;

    mylist->head->next->next->next->random =
        mylist->head->next->next->next->next->next;

    mylist->head->next->next->next->next->random = mylist->head->next;

    // making a clone
    LinkedList* clone = mylist->clone();

    cout << "Original Linked List \n";
    mylist->print();
    cout << "\nCloned Linked List\n";
    clone->print();
}