
class Solution {
public:
    
    vector<vector<int>> ans;
    
    void csum(vector<int>& candidates,
        vector<int> &comb,
        unordered_map<int, int> &m,
        unordered_map<int, int>::iterator cur,
        int target) {

        if(target == 0) {
            ans.push_back(comb);
            return;
        }
                

        if(cur == m.end()) {
            return;
        }
        
        csum(candidates, comb, m, next(cur), target);
        
        for(int i = 1; target - cur->first * i >= 0 && i <= cur->second; i++) {
            comb.push_back(cur->first);
            csum(candidates, comb, m, next(cur), target - cur->first * i);
        }
        
        for(int i = 1; target - cur->first * i >= 0 && i <= cur->second; i++)
            comb.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        unordered_map<int, int> m;
        
        for(int c : candidates)
            if(target >= c)
                m[c]++;
            
        vector<int> comb;
        csum(candidates, comb, m, m.begin(), target);
        
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 59.73% of C++ online submissions for Combination Sum II.
Memory Usage: 14.6 MB, less than 18.08% of C++ online submissions for Combination Sum II.
*/




// class Solution {
// public:
//     vector<vector<int> > ans;
//     map<vector<int>, bool> m;
    
//     vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
//         vector<int> proc;
//         run(candidates, candidates.begin(), target, proc);
//         return ans;
//     }
//     void run(vector<int>& candidates, vector<int>::iterator it, int target, vector<int> proc) {
//         if(target == 0) {
//             sort(proc.begin(), proc.end());
//             if(m.find(proc) == m.end()) {
//                 ans.push_back(proc);
//                 m[proc] = true;
//             }
//             return;
//         }
//         if(it == candidates.end()) {
//             return;
//         }
//         run(candidates, it+1, target, proc);
//         proc.push_back(*it);
//         run(candidates, it+1, target-*it, proc);
//     }
// };