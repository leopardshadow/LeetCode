class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cand;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     
        cand = candidates;
        
        run(cand.begin(), target, vector<int>());
        
        return ans;
    }
    
    void run(vector<int>::iterator it, int target, vector<int> proc) {
        if(target == 0) {
            ans.push_back(proc);
            return;
        }
        if(it == cand.end()) {
            return;
        }
        for(int i = target; i >= 0; i -= *it) {
            run(it+1, i, proc);
            proc.push_back(*it);
        }
    }
};

/*
Runtime: 96 ms, faster than 18.49% of C++ online submissions for Combination Sum.
Memory Usage: 25.1 MB, less than 21.79% of C++ online submissions for Combination Sum.
*/