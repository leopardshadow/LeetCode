// O (n ^ 2) approach

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
        
//         int ans = 1;
//         vector<int> table(nums.size(), 1);
//         table[0] = 1;
//         for(int i = 1; i < nums.size(); i++) {
//             for(int j = i - 1; j >= 0; j--) {
//                 if(nums[i] > nums[j])
//                     table[i] = max(table[i], table[j] + 1);
//             }
//             ans = max(ans, table[i]);
//         }
//         return ans;
//     }
// };

/*
Runtime: 284 ms, faster than 33.52% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 10.6 MB, less than 12.27% of C++ online submissions for Longest Increasing Subsequence.
*/


// O(n logn)


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int ans = 1;
        vector<int> table(nums.size(), 0);
        // table[0] = 1;
        
        
        
        
        
        return ans;
    }
};




//***************************************************************************//
// Review: 2021.11.29 before G VO

/*
錯誤的邏輯
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        deque<int> st;
        st.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > st.back())
                st.push_back(nums[i]);
            else if(nums[i] < st.back() && (st.size() <= 1 || nums[i] > st[st.size() - 2]))
                st.back() = nums[i];
        }
        return st.size();
    }
};


//***************************************************************************//
// 今天 5.25 Daily - 354. Russian Doll Envelopes 會用到 LIS 

/*
這裡 LIS[i] 的意思是，長度 i+1 的所有 increasing subsequence 中，最小的末位值
這個值很重要，因為同樣長度為 3 的 increasing subsequence [1,2,8] 和 [2,4,5]，後者比較好，因為他更有可能再往後接變長
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int i = 0; i < nums.size();i++){
            
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            
            if(it == lis.end())
                lis.push_back(nums[i]);
            else
                *it = nums[i];
        }
        
        return lis.size();
    }
};
/*
Runtime: 16 ms, faster than 75.18% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 10.3 MB, less than 88.02% of C++ online submissions for Longest Increasing Subsequence.
*/

// 2022.8.8
