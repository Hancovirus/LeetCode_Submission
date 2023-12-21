class Solution {
public: 
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        set<int> s1;
        for (int i = 0; i < n; i++) {
            s1.insert(points[i][0]);
        }
        int max = 0;
        int prev = *s1.begin();
        for (auto i : s1) {
            if (i - prev > max) {
                max = i - prev;
            }
            prev = i;
        }
        return max;
    }
};