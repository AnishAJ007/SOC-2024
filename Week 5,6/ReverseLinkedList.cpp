#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Recursive function to reverse a linked list
    void reverse(ListNode* &head, ListNode* &curr, ListNode* &prev) {
        if (curr == nullptr) {
            head = prev; // Update the head to the new head of reversed list
            return;
        }

        ListNode* forward = curr->next; // Store next node before recursive call
        reverse(head, forward, curr);   // Recursive call
        curr->next = prev;              // Reverse the link
    }

    // Function to initiate the reverse process and return the reversed list
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr; // Previous node initially null
        reverse(head, curr, prev); // Call to recursive function
        return head;               // Return the new head of reversed list
    }
};

// Function to print the linked list (for testing)
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to delete the linked list nodes (for testing)
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

// Driver code to test the Solution class
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution ob;
    head = ob.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    // Clean up
    deleteList(head);

    return 0;
}
