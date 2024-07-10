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
    ListNode* getmid(ListNode* head) {
        ListNode* slow = head;//
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // Function to reverse a linked list
    ListNode* reverse(ListNode* &head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        // Check if list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* middle = getmid(head);         // Find middle of the list
        ListNode* second_half = middle->next;    // Second half of the list
        middle->next = nullptr;                  // Break the list into two halves

        second_half = reverse(second_half);      // Reverse the second half

        ListNode* p1 = head;                     // Pointer for first half
        ListNode* p2 = second_half;              // Pointer for reversed second half

        // Compare values of corresponding nodes in both halves
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val != p2->val) {
                return false;                    // Not a palindrome
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Restore the list by reversing the second half back
        second_half = reverse(second_half);
        middle->next = second_half;

        return true;                             // List is a palindrome
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
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    Solution ob;
    
    cout << "List 1: ";
    printList(head1);
    cout << "Is palindrome? " << (ob.isPalindrome(head1) ? "Yes" : "No") << endl;

    cout << "List 2: ";
    printList(head2);
    cout << "Is palindrome? " << (ob.isPalindrome(head2) ? "Yes" : "No") << endl;

    // Clean up
    deleteList(head1);
    deleteList(head2);

    return 0;
}
