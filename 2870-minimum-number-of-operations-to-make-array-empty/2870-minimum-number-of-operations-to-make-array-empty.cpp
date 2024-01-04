class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == 1) {
                return -1;
            }
            if (it->second % 3 == 1) {
                sum += (it->second - 4) / 3;
                sum += 2;
            } else if (it->second % 3 == 2) {
                sum += (it->second - 2) / 3;
                sum += 1;
            } else {
                sum += it->second / 3;
            }
        }
        return sum;
    }
};