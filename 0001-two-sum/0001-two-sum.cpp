class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> outPut(2);
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                outPut[0] = mp[target - nums[i]];
                outPut[1] = i;
                return outPut;
            } else {
                mp[nums[i]] = i;
            }
        }
        return outPut;
    }
};