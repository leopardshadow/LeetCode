// Google
/*
有點有趣的題目，好像不用特別用到什麼特殊的資料結構，重要的是熟悉 vector 操作 XD
「感覺」和 Google kickstart 2021 Round H 的 Silly Substitutions 好像 (?)

stack-like
注意那個 i 的操作
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asters) {
        vector<int> ans;
        for(int i = 0; i < asters.size(); ) {
            if(ans.empty()) {
                ans.push_back(asters[i]);
                i++;
                continue;
            }
            if(ans.back() > 0 && asters[i] < 0) {
                if(ans.back() > -asters[i]) {
                    i++;
                }                    
                else if(ans.back() < -asters[i]) {
                    ans.pop_back();
                }
                else {
                    ans.pop_back();
                    i++;
                }
            }
            else {
                ans.push_back(asters[i]);
                i++;
            }
        }
        return ans;
    }
};

/*
Runtime: 12 ms, faster than 81.35% of C++ online submissions for Asteroid Collision.
Memory Usage: 17.4 MB, less than 81.22% of C++ online submissions for Asteroid Collision.
*/
