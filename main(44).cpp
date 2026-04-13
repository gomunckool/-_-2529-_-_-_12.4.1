#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void appendNode(Node*& head, int value);
void printList(Node* head, const string& listName);
bool containsValue(Node* head, int value);
bool areAllElementsPresent(Node* L1, Node* L2);
void clearList(Node*& head);
void inputList(Node*& head, const string& listName);

int main() {
    Node* L1 = nullptr;
    Node* L2 = nullptr;

    inputList(L1, "L1");
    inputList(L2, "L2");

    cout << "\n--- Sformovani spysky ---" << endl;
    printList(L1, "Spysok L1");
    printList(L2, "Spysok L2");

    cout << "\n--- Rezultat perevirky ---" << endl;
    if (areAllElementsPresent(L1, L2)) {
        cout << "TAK: Vsi elementy L1 vkhodiat u L2." << endl;
    } else {
        cout << "NI: U spysku L2 vidsutni deiaki elementy z L1." << endl;
    }

    clearList(L1);
    clearList(L2);

    return 0;
}

void inputList(Node*& head, const string& listName) {
    int n, value;
    cout << "Vvedit kilkist elementiv dlia " << listName << ": ";
    while (!(cin >> n) || n < 0) {
        cout << "Pomylka. Vvedit tsile dodatne chyslo: ";
        cin.clear();
        while (cin.get() != '\n');
    }

    for (int i = 0; i < n; ++i) {
        cout << "[" << listName << "] Element " << i + 1 << ": ";
        while (!(cin >> value)) {
            cout << "Pomylka. Vvedit chyslove znachennia: ";
            cin.clear();
            while (cin.get() != '\n');
        }
        appendNode(head, value);
    }
}

void appendNode(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void printList(Node* head, const string& listName) {
    cout << listName << ": ";
    if (head == nullptr) {
        cout << "porozhnii" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "(kiltse)" << endl;
}

bool containsValue(Node* head, int value) {
    if (head == nullptr) return false;
    Node* temp = head;
    do {
        if (temp->data == value) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

bool areAllElementsPresent(Node* L1, Node* L2) {
    if (L1 == nullptr) return true; 
    
    Node* currentL1 = L1;
    do {
        if (!containsValue(L2, currentL1->data)) {
            return false; 
        }
        currentL1 = currentL1->next;
    } while (currentL1 != L1);
    
    return true;
}

void clearList(Node*& head) {
    if (head == nullptr) return;
    Node* current = head;
    Node* nextNode;
    
    Node* tail = head;
    while (tail->next != head) tail = tail->next;
    tail->next = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}
