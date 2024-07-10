#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find a peak element in the array
    int findPeakElement(vector<int>& nums) {
        int s = 0; // Start index of the array
        int e = nums.size() - 1; // End index of the array
        int n = nums.size(); // Size of the array //

        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate middle index

            // Check if mid is a peak element
            if ((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == n - 1 || nums[mid + 1] <= nums[mid])) {
                return mid; // Return index of the peak element
            }

            // If the element to the left of mid is greater, move left
            if (mid > 0 && nums[mid - 1] >= nums[mid]) {
                e = mid - 1;
            } else { // Otherwise, move right
                s = mid + 1;
            }
        }

        return -1; // Return -1 if no peak element found
    }
};

// Driver code to test the Solution class
int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    Solution ob;
    cout << "Peak element index: " << ob.findPeakElement(nums) << "\n";
    return 0;
}
