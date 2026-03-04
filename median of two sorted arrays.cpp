#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize the binary search range
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            // If partition is at 0, there is nothing on the left side. Use -INF.
            // If partition is at length, there is nothing on the right side. Use +INF.
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // We have partitioned the arrays correctly
                if ((m + n) % 2 == 0) {
                    return (max((double)maxLeft1, (double)maxLeft2) + 
                            min((double)minRight1, (double)minRight2)) / 2.0;
                } else {
                    return (double)max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // We are too far right in nums1, move left
                high = partition1 - 1;
            } else {
                // We are too far left in nums1, move right
                low = partition1 + 1;
            }
        }

        return 0.0; // Should never reach here if inputs are sorted
    }
};
