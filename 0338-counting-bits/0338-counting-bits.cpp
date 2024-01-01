class Solution {
private:
    int solution(std::unordered_map<int, int>& mp, int i) {
        if (mp.find(i) != mp.end()) {
            return mp[i];
        }

        if (i == 0) {
            return 0;
        }

        int count = 0;

        if (i % 2 == 1) {
            count++;
        }

        count += solution(mp, i / 2);
        mp[i] = count;

        return count;
    }

public:
    vector<int> countBits(int n) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i <= n; i++) {
            ans.push_back(solution(mp, i));
        }
        return ans;
    }
};