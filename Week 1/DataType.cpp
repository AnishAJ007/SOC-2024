#include <iostream>
using namespace std;

class Solution {
public:
    int dataTypeSize(string str) {
        // Determine and return the size of different data types
        if (str == "Character") {
            return sizeof(char); // Size of char is typically 1 byte
        } else if (str == "Integer" || str == "Float") {
            return sizeof(int); // Size of int is typically 4 bytes
        } else if (str == "Long" || str == "Double") {
            return sizeof(double); // Size of double is typically 8 bytes
        } else {
            return -1; // Return -1 for unknown data types
        }
    }
};

// Driver code to test the Solution class
int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        string str;
        cin >> str; // Input data type string
        Solution ob;
        cout << ob.dataTypeSize(str) << "\n"; // Output the size of the data type
    }
    return 0;
}
