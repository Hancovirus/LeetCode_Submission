class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>, int> mp;
        pair<int, double> mypair;
        mypair.first = 0;
        mypair.second = 0;
        mp[mypair] = 1;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == 'N') {
                mypair.second++;
            } else if (path[i] == 'E') {
                mypair.first++;
            } else if (path[i] == 'S') {
                mypair.second--;
            } else {
                mypair.first--;
            } 
            if (mp[mypair] == 1) {
                return true;
            }
            mp[mypair] = 1;
        }
        return false;
    }
};