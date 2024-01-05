class Solution {
public:
    bool isIsomorphic(string s, string t) {
       map<char, char> mps;
        map<char, char> mpt;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (mps.find(s[i]) == mps.end()) {
                mps[s[i]] = t[i];
            } else {
                if (t[i] != mps[s[i]]) 
                    return false;
            }

            if (mpt.find(t[i]) == mpt.end()) {
                mpt[t[i]] = s[i];
            } else {
                if (s[i] != mpt[t[i]]) 
                    return false;
            }
        }
        return true;
    }
};