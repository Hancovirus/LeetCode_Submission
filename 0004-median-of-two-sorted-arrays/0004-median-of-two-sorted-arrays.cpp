class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int mergedSize = totalSize / 2 + 1;

        int nums1Index = 0;
        int nums2Index = 0;
        int prev = 0;
        int curr = 0;

        for (int i = 0; i < mergedSize; i++) {
            prev = curr;
            if (nums1Index < nums1.size() && (nums2Index >= nums2.size() || nums1[nums1Index] <= nums2[nums2Index])) {
                curr = nums1[nums1Index];
                nums1Index++;
            } else {
                curr = nums2[nums2Index];
                nums2Index++;
            }
        }

        if (totalSize % 2 == 1) {
            return (double)curr;
        } else {
            return (double)(prev + curr) / 2;
        }
    }
};
