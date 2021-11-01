/*
Nice: https://blog.techbridge.cc/2019/10/26/leetcode-pattern-next-greater-element/
*/
// 搞錯題目意思惹 QQ
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans(nums1.size(), -1);
//         unordered_map<int, int> table;
//         stack<int> st;
//         for(int i = 1; i < nums2.size(); i++) { // note the size!
            
//             if(i - 1 < nums1.size()) {
//                 st.push(nums1[i-1]);
//                 table[nums1[i-1]] = i - 1;
//             }
            
//             while(!st.empty() && nums2[i] > st.top()) {
//                 ans[ table[st.top()] ] = i;
//                 st.pop();
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> table;
        stack<int> st;

        // 先不要管 nums1，先幫 nums2 把每個位置往後最大的找出來
        st.push(nums2[0]);
        for(int i = 1; i < nums2.size(); i++) {
            while( !st.empty() && nums2[i] > st.top()) {
                table[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()) {
            table[st.top()] = -1;
            st.pop();
        }
        
        // 接著才來管 nums1，從建立的表格中找答案
        // nums1 的數字位置不大重要，以 Exampl 1 來說，
        // 如果 nums1 換成 [1, 4, 2]，那就只是對應的位置改變，變成 [3, -1, -1]
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++)
            ans[i] = table[nums1[i]];
        
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 92.46% of C++ online submissions for Next Greater Element I.
Memory Usage: 8.8 MB, less than 70.12% of C++ online submissions for Next Greater Element I.
*/