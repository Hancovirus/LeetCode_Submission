class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> mat(nums.size());
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] - 1 > max) {
                max = mp[nums[i]] - 1;
            }
            mat[mp[nums[i]] - 1].push_back(nums[i]);
        }
        vector<vector<int>> ans;
        for (int i = 0; i <= max; i++) {
            ans.push_back(mat[i]);
        }
        return ans;
    }
};