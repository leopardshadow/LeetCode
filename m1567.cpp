/*
                 [1,-2,-3, 4, 0]
wholePosCnt -  0     1  1  1
partPosCnt  -  0  1  0  0  
wholeNegCnt -  0     1  2
    ans.    -  0  1  1  2

[5,-20,-20,-39,-5,0,0,0,36,-32,0,-7,-10,-7,21,20,-12,-34,26,2]
wholePosCnt - 
partPosCnt  -         
wholeNegCnt - 
    ans.    -
*/

// 錯誤的邏輯
// class Solution {
// public:
//     int getMaxLen(vector<int>& nums) {
//         nums.push_back(0);
//         int ans = 0;
//         int wholePosCnt = 0, partPosCnt = 0, wholeNegCnt = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == 0) {
//                 if(wholeNegCnt % 2 == 0)
//                     ans = max(ans, wholePosCnt + wholeNegCnt);
//                 wholePosCnt = 0;
//                 partPosCnt = 0;
//                 wholeNegCnt = 0;
//             }
//             else if(nums[i] > 0) {
//                 wholePosCnt++;
//                 partPosCnt++;
//                 ans = max(ans, partPosCnt);
//             }
//             else {  // nums[i] < 0
//                 wholeNegCnt++;
//                 partPosCnt = 0;
//                 if(wholeNegCnt % 2 == 0)
//                     ans = max(ans, wholePosCnt + wholeNegCnt);
//             }
//         }
//         return ans;
//     }
// };

//***************************************************************************//
/*
下面這個寫法用 sliding window 的想法
在寫這題時讓我想到在寫網程作業時的字串
*/

/*
0 0 0 1 1 1 -1 -1 1 -1 -1 0
                        r i
       l
    0. 1. 2       
   -1  2
    l     i
       r
*/



class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        nums.push_back(0);
        int i = 0;
        int l, r;
        int negCnt;
        int ans = 0;
        while(i < nums.size()) {
            // find non-zeros
            while(i < nums.size() && nums[i] == 0)
                i++;
            l = i;
            negCnt = 0;
            // find zeros
            while(i < nums.size() && nums[i] != 0) {
                if(nums[i] < 0)
                    negCnt++;
                i++;
            }
            r = i - 1;
            if(negCnt % 2 == 0)
                ans = max(ans, r - l + 1);
            else { // find the negative from each side, can be optimized
                int j = r;
                while(nums[j] > 0)  // find negative
                    j--;
                ans = max(ans, j - l);
                j = l;
                while(nums[j] > 0)  // find negative
                    j++;
                ans = max(ans, r - j);
            }
            i++;
        }
        return ans;
    }
};

/*
Runtime: 208 ms, faster than 7.11% of C++ online submissions for Maximum Length of Subarray With Positive Product.
Memory Usage: 57.9 MB, less than 76.31% of C++ online submissions for Maximum Length of Subarray With Positive Product.
*/

//***************************************************************************//
// 這個算是上面 sliding window 寫法的加強版，少掉了找負值那段 (用 j 去找)

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        nums.push_back(0);
        int i = 0;
        int l, r;
        int negCnt;
        int ans = 0;
        int firstNeg, lastNeg;
        while(i < nums.size()) {
            // find non-zeros
            while(i < nums.size() && nums[i] == 0)
                i++;
            l = i;
            negCnt = 0;
            // find zeros
            firstNeg = -1;  // 這裏的初始值很有趣
            lastNeg = 1000000;
            while(i < nums.size() && nums[i] != 0) {
                if(nums[i] < 0) {
                    negCnt++;
                    lastNeg = i;
                    if(firstNeg == -1)
                        firstNeg = i;
                }
                i++;
            }
            r = i - 1;
            if(negCnt % 2 == 0)
                ans = max(ans, r - l + 1);
            else { // find the negative from each side, can be optimized
                ans = max(ans, r - firstNeg);
                ans = max(ans, lastNeg - l);
            }
            i++;
        }
        return ans;
    }
};

/*
Runtime: 112 ms, faster than 55.08% of C++ online submissions for Maximum Length of Subarray With Positive Product.
Memory Usage: 57.9 MB, less than 76.31% of C++ online submissions for Maximum Length of Subarray With Positive Product.
*/
