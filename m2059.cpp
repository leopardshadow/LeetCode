// [LeetCode] - Weekly Contest 265

// how to deal with overflow value, it is not defined in the spec ...
// 好吧，又是沒看清楚題目
// 他是說 x 只能在 0~ 1000 之間，不是說 operation 最多做 1000 次
// 最多做 1000 次 的話要額外處理 overflow 的問題，而且要存的會變超大

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        vector<bool> m(1001, false);
        queue<int> q;
        int i;
        int qf;
        int proc;
        int depth = 0;
        bool of;
        
        q.push(start);
        m[start] = true;
        
        while(!q.empty()) {
            depth++;
            i = q.size();
            while(i > 0) {
                qf = q.front();
                q.pop();
                i--;
                for(auto n : nums) {
                    
                    proc = qf + n;
                    if(proc == goal) return depth;
                    if(proc >= 0 && proc <= 1000 && !m[proc]) {
                        q.push(proc);
                        m[proc] = true;
                    }
                    
                    proc = qf - n;
                    if(proc == goal) return depth;
                    if(proc >= 0 && proc <= 1000 && !m[proc]) {
                        q.push(proc);
                        m[proc] = true;
                    }

                    proc = qf ^ n;
                    if(proc == goal) return depth;
                    if(proc >= 0 && proc <= 1000 && !m[proc]) {
                        q.push(proc);
                        m[proc] = true;
                    }

                }
            }
        }
        
        return -1;
    }
};


/*
Runtime: 74 ms, faster than 97.06% of C++ online submissions for Minimum Operations to Convert Number.
Memory Usage: 8.5 MB, less than 64.71% of C++ online submissions for Minimum Operations to Convert Number.
*/