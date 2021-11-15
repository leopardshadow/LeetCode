// Hint: LIS
// Longest Increasing Subsequence
// ***use another table to store previos results***
// sort it first
// if a < b < c && b % a == 0 && c % b == 0
// then c % a == 0
// b % a == 0 --> b = n a
// c % b == 0 --> c = m b
//            --> c = m (n a)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        //
        sort(nums.begin(), nums.end());
        
        vector<int> table(nums.size(), 1);
        vector<int> prevIdx(nums.size(), -1);
        int lastElement = 0, maxLen = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(table[j] + 1 > table[i]) {
                        table[i] = table[j] + 1;
                        prevIdx[i] = j;
                    }
                }
            }
            if(table[i] > maxLen) {
                lastElement = i;
                maxLen = table[i];
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastElement]);
        int i = prevIdx[lastElement];
        while(i != -1) {
            ans.push_back(nums[i]);
            i = prevIdx[i];
        }
        
//         int cnt = table[lastElement] - 1;
//         for(int i = lastElement - 1; i >= 0; i--) {
//             if(nums[lastElement] % nums[i] == 0 &&
//                 cnt == table[i]) {
//                 ans.push_back(nums[i]);
//                 cnt--;
//             }
            
//         }
        return ans;
    }
};
