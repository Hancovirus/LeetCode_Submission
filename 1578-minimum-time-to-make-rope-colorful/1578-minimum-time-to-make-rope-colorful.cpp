class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;
        int temp = 1;
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] != '_') {
                while (i + temp < colors.size() && colors[i + temp] == colors[i]) {
                    if (neededTime[i + temp] <= neededTime[i]) {
                        colors[i + temp] = '_';
                        sum += neededTime[i + temp];
                        temp++;
                    } else {
                        colors[i] = '_';
                        sum += neededTime[i];
                        break;
                    }
                }
                temp = 1;
            }
        }
        return sum;
    }
};