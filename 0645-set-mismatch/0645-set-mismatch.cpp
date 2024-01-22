class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int dup;
        int miss;
        for (int i = 1; i <= n; i++) {
            if (mp[i] == 2) {
                dup = i;
            } else if (mp[i] != 1) {
                miss = i;
            }
            
        }
        return {dup,miss};
    }
};