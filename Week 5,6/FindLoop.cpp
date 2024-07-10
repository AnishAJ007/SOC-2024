#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Check for empty list or single node list
        if (head == nullptr || head->next == nullptr) {
            return false;//
        }

        ListNode* slow = head;  // Slow pointer moves one step at a time
        ListNode* fast = head;  // Fast pointer moves two steps at a time

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;      // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps

            if (slow == fast) {     // If they meet, there's a cycle
                return true;
            }
        }

        return false; // If fast reaches end (nullptr), no cycle found
    }
};

// Function to create a cyclic linked list (for testing)
ListNode* createCyclicList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Create a cycle from 4 to 2
    return head;
}

// Function to print result of cycle detection (for testing)
void testCycleDetection(ListNode* head) {
    Solution ob;
    if (ob.hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }
}

// Driver code to test the Solution class
int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = createCyclicList();

    cout << "Testing linked list 1:" << endl;
    testCycleDetection(head1);

    cout << "Testing linked list 2 (with cycle):" << endl;
    testCycleDetection(head2);

    return 0;
}
