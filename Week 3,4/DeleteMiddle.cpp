#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If head or head's next is null, return null (no middle to delete)//
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;          // Pointer to traverse list one step at a time
        ListNode* fast = head->next;    // Pointer to traverse list two steps at a time
        ListNode* prev = nullptr;       // Pointer to keep track of previous node

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;                // Update prev to current slow
            slow = slow->next;          // Move slow one step forward
            fast = fast->next->next;    // Move fast two steps forward
        }

        // Now slow is at the middle node to delete
        if (prev != nullptr) {
            prev->next = slow->next;    // Skip over the middle node
        } else {
            head = slow->next;          // Update head if the first node was deleted
        }

        delete slow;                    // Delete the middle node

        return head;                    // Return the updated head of the list
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

// Driver code to test the Solution class
int main() {
    // Example linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution ob;
    head = ob.deleteMiddle(head);

    cout << "List after deleting middle node: ";
    printList(head);

    return 0;
}
