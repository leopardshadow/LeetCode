
// 2022.10.27

/*
因為題目 size 不大，所以直接硬爆就行
---
好像和 convolution, fft 相關
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int dr = 1 - n; dr <= n - 1; dr++) {
            for (int dc = 1 - n; dc <= n - 1; dc++) {
                int sum = 0;
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {
                        if (r+dr >= 0 && r+dr < n &&
                            c+dc >= 0 && c+dc < n &&
                            img1[r+dr][c+dc] && img2[r][c])
                            sum++;
                    }
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
/*
Runtime: 180 ms, faster than 49.31% of C++ online submissions for Image Overlap.
Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Image Overlap.
*/
