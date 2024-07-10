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
    // Function to find the middle node of a linked list
    ListNode* getmid(ListNode* &head) {
        ListNode* slow = head;
        ListNode* fast = head->next;//

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* &left, ListNode* &right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        ListNode* ans = new ListNode(-1); // Dummy node for the result
        ListNode* temp = ans;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        // Append remaining nodes if any
        while (left != nullptr) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != nullptr) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next; // Move to the actual head of merged list
        return ans;
    }

    // Function to recursively sort a linked list
    ListNode* sortList(ListNode* head) {
        // Base case: empty list or single node list is already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid = getmid(head);       // Find the middle node
        ListNode* left = head;              // Head of left half
        ListNode* right = mid->next;        // Head of right half
        mid->next = nullptr;                // Split the list into two halves

        left = sortList(left);              // Recursively sort left half
        right = sortList(right);            // Recursively sort right half

        ListNode* result = merge(left, right); // Merge sorted halves
        return result;
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
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    Solution ob;
    head = ob.sortList(head);

    cout << "Sorted List: ";
    printList(head);

    // Clean up
    deleteList(head);

    return 0;
}
