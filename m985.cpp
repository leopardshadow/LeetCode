
// 2022.9.21

/*
就照著題目說的做
*/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum = 0;
        for (const int &n : nums)
            if (n % 2 == 0)
                sum += n;
        
        vector<int> ans;
        for (vector<int> &q  : queries) {
            int val = q[0], pos = q[1];
            if (nums[pos] % 2 == 0) {
                if (val % 2 == 0) // even -> even
                    sum += val;
                else // even -> odd
                    sum -= nums[pos];
            }
            else {
                if (val % 2 == 0) // odd -> odd
                    ;
                else
                    sum += (nums[pos] + val); // odd ->even
            }
            nums[pos] += val;
            ans.push_back(sum);
        }
        return ans;
    }
};
