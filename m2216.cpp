
// Weekly Contest 286

/*
這題在 contest 中吃了一個 WA，為了讓他是 even length 而多加的部分和重複加的部分重複了
---
這個是 O(1) 的寫法，沒有額外存整條，如果多存好像比較簡單一點 (?)
*/

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); ) {
            
            int n0 = nums[i];
            
            int j = i + 1;
            
            int toAdd = 0;  // avoid add twice (for even length)
            
            while(j < nums.size() && n0 == nums[j]) {
                toAdd++;
                j++;
            }
            
            // for even length
            if(j == nums.size()) {
                ans += (nums.size() - i);
                break;
                cout << i << " " << j << endl;
            }
                
            ans += toAdd;
            
            i = j + 1;   
        }
        
        return ans;
    }
};

/*
Runtime: 277 ms, faster than 14.29% of C++ online submissions for Minimum Deletions to Make Array Beautiful.
Memory Usage: 121.1 MB, less than 57.14% of C++ online submissions for Minimum Deletions to Make Array Beautiful.
*/
