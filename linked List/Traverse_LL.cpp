#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLinkedList(Node* head) {
    Node* temp = head;
    int pos = 0;
    while (temp != nullptr) {
        cout << "Node " << pos << ": ";
        cout << "Address: " << temp << ", ";
        cout << "Data: " << temp->data << ", ";
        cout << "Next Address: " << temp->next << endl;
        temp = temp->next;
        pos++;
    }
}




int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    cout << "The linked list is: "
}
