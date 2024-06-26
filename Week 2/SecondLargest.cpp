#include <iostream>
using namespace std;

class Solution {
public:
    // Function returns the second largest element
    int print2largest(int arr[], int n) {
        // Check if there are fewer than 2 elements
        if (n < 2) {
            return -1; // Return -1 as per problem statement
        }
        
        int first = arr[0]; // Initialize first largest element
        int second = -1;    // Initialize second largest element
        
        for (int i = 1; i < n; ++i) {
            // Update first and second largest elements
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            } else if (arr[i] > second && arr[i] != first) {
                second = arr[i];
            }
        }
        
        return second; // Return the second largest element
    }
};

// Driver code to test the Solution class
int main() {
    int arr[] = { 12, 35, 1, 10, 34, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution ob;
    cout << ob.print2largest(arr, n) << "\n";
    return 0;
}
