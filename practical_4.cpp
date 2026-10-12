
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class Singly {
    Node* head = nullptr;

public:
    void insert(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* t = head;
        while (t) {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }

    void remove(int x) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == x) {
            Node* t = head;
            head = head->next;
            delete t;
            cout << "Node deleted\n";
            return;
        }
        Node* t = head;
        while (t->next && t->next->data != x) t = t->next;
        if (!t->next) cout << "Element not found\n";
        else {
            Node* d = t->next;
            t->next = d->next;
            delete d;
            cout << "Node deleted\n";
        }
    }

    void search(int x) {
        Node* t = head;
        int pos = 1;
        while (t) {
            if (t->data == x) {
                cout << "Element found at position " << pos << "\n";
                return;
            }
            t = t->next;
            pos++;
        }
        cout << "Element not found\n";
    }

    void reverse() {
        Node *prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        cout << "List reversed\n";
    }

    void count() {
        int c = 0;
        Node* t = head;
        while (t) {
            c++;
            t = t->next;
        }
        cout << "Number of nodes: " << c << "\n";
    }

    void middle() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }
};

class Doubly {
    Node* head = nullptr;

public:
    void insert(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* t = head;
        while (t) {
            cout << t->data << " <-> ";
            t = t->next;
        }
        cout << "NULL\n";
    }

    void remove(int x) {
        Node* t = head;
        while (t && t->data != x) t = t->next;
        if (!t) {
            cout << "Element not found\n";
            return;
        }
        if (t->prev) t->prev->next = t->next;
        else head = t->next;
        if (t->next) t->next->prev = t->prev;
        delete t;
        cout << "Node deleted\n";
    }

    void search(int x) {
        Node* t = head;
        int pos = 1;
        while (t) {
            if (t->data == x) {
                cout << "Element found at position " << pos << "\n";
                return;
            }
            t = t->next;
            pos++;
        }
        cout << "Element not found\n";
    }

    void reverse() {
        Node* t = head;
        Node* temp = nullptr;
        while (t) {
            temp = t->prev;
            t->prev = t->next;
            t->next = temp;
            t = t->prev;
        }
        if (temp) head = temp->prev;
        cout << "List reversed\n";
    }

    void count() {
        int c = 0;
        Node* t = head;
        while (t) {
            c++;
            t = t->next;
        }
        cout << "Number of nodes: " << c << "\n";
    }

    void middle() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }
};

class Circular {
    Node* head = nullptr;

public:
    void insert(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* t = head;
        do {
            cout << t->data << " -> ";
            t = t->next;
        } while (t != head);
        cout << "(back to head)\n";
    }

    void remove(int x) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node *cur = head, *prev = nullptr;
        do {
            if (cur->data == x) break;
            prev = cur;
            cur = cur->next;
        } while (cur != head);

        if (cur->data != x) {
            cout << "Element not found\n";
            return;
        }

        if (cur->next == cur) head = nullptr;
        else {
            if (!prev) {
                Node* last = head;
                while (last->next != head) last = last->next;
                head = head->next;
                last->next = head;
            } else prev->next = cur->next;
        }
        delete cur;
        cout << "Node deleted\n";
    }

    void search(int x) {
        if (!head) {
            cout << "Element not found\n";
            return;
        }
        Node* t = head;
        int pos = 1;
        do {
            if (t->data == x) {
                cout << "Element found at position " << pos << "\n";
                return;
            }
            t = t->next;
            pos++;
        } while (t != head);
        cout << "Element not found\n";
    }

    void reverse() {
        if (!head || head->next == head) {
            cout << "List reversed\n";
            return;
        }
        Node *prev = head, *cur = head->next, *next;
        while (cur != head) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = prev;
        head = prev;
        cout << "List reversed\n";
    }

    void count() {
        int c = 0;
        if (head) {
            Node* t = head;
            do {
                c++;
                t = t->next;
            } while (t != head);
        }
        cout << "Number of nodes: " << c << "\n";
    }

    void middle() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node *slow = head, *fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }
};

int main() {
    Singly s;
    Doubly d;
    Circular c;
    int type, choice, x;

    do {
        cout << "\n--- LINKED LIST MENU ---\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Circular Singly Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter list type: ";
        cin >> type;

        if (type == 0) break;
        if (type < 1 || type > 3) {
            cout << "Invalid choice\n";
            continue;
        }

        do {
            cout << "\n1. Insert\n2. Delete\n3. Display\n";
            cout << "4. Search\n5. Reverse\n6. Count Nodes\n";
            cout << "7. Find Middle\n0. Back\n";
            cout << "Enter operation: ";
            cin >> choice;

            if (choice == 0) break;

            if (choice == 1 || choice == 2 || choice == 4) {
                cout << "Enter value: ";
                cin >> x;
            }

            if (type == 1) {
                if (choice == 1) s.insert(x);
                else if (choice == 2) s.remove(x);
                else if (choice == 3) s.display();
                else if (choice == 4) s.search(x);
                else if (choice == 5) s.reverse();
                else if (choice == 6) s.count();
                else if (choice == 7) s.middle();
                else cout << "Invalid choice\n";
            } else if (type == 2) {
                if (choice == 1) d.insert(x);
                else if (choice == 2) d.remove(x);
                else if (choice == 3) d.display();
                else if (choice == 4) d.search(x);
                else if (choice == 5) d.reverse();
                else if (choice == 6) d.count();
                else if (choice == 7) d.middle();
                else cout << "Invalid choice\n";
            } else {
                if (choice == 1) c.insert(x);
                else if (choice == 2) c.remove(x);
                else if (choice == 3) c.display();
                else if (choice == 4) c.search(x);
                else if (choice == 5) c.reverse();
                else if (choice == 6) c.count();
                else if (choice == 7) c.middle();
                else cout << "Invalid choice\n";
            }
        } while (choice != 0);

    } while (type != 0);

    return 0;
}
