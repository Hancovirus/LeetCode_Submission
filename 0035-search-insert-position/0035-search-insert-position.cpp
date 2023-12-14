class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target)
{
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }

    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int result = binarySearch(nums, 0, n - 1, target);
        return result;
    }
};