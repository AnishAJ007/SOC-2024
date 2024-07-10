#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    nums.push_back(6); // Add element to end
    nums.pop_back();   // Remove last element
    
    for (int num : nums)
        cout << num << " ";
    cout << endl;
    
    return 0;
}
