
// 2022.7.1

/*
greedy - sorting
*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] > b[1];
        });
        int ans = 0, i = 0;
        while (truckSize > 0 && i < boxTypes.size()){
            int n = min(truckSize, boxTypes[i][0]);
            ans += n * boxTypes[i][1];
            truckSize -= n;
            i++;
        }
        return ans;
    }
};
/*
Runtime: 45 ms, faster than 91.28% of C++ online submissions for Maximum Units on a Truck.
Memory Usage: 15.9 MB, less than 77.60% of C++ online submissions for Maximum Units on a Truck.
*/
