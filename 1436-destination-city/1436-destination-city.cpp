class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> mp;
        for (vector<string> road : paths) {
            mp[road[0]]++;
        }

        for (vector<string> road : paths) {
            if (mp[road[1]] == 0) {
                return road[1];
            }
        }
        return "No city";
    }
};