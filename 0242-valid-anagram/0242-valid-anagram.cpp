class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.size() != s.size()) {
            return false;
        }
        map<int,int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]--;
        }
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] != 0)
                return false;
        }
        return true;
    }
};