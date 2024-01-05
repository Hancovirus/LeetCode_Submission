class Solution {
private:
    int solution(vector<int>& nums, int i, vector<int> &memo) {
        if (memo[i] != -1) {
            return memo[i];
        }
        int curr = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                curr = max(curr, 1 + solution(nums, j, memo));
            }
        }
        memo[i] = curr;
        return curr;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int max = 0;
        vector<int> memo(nums.size(), -1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (solution(nums, i, memo) > max) {
                max = solution(nums, i, memo);
            }
        }
        return max;
    }
};