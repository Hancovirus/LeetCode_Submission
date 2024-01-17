class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        map<int, int> ctrl;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if (ctrl[it->second] == 1) {
                return false;
            }
            ctrl[it->second] = 1;
        }
        return true;
    }
};