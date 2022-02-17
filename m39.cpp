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


//***************************************************************************//
// Review: 2021.11.28 before G VO

// backtracking

class Solution {
    vector<int> nums;
    vector<vector<int>> ans;
public:
    void comb(int c, vector<int>& cands, int target) {
        if(target == 0) {
            ans.push_back(nums);
            return;
        }
        if(c >= cands.size())
            return;
        int i;
        for(i = 0; target - i * cands[c] >= 0; i++) {
            comb(c + 1, cands, target - i * cands[c]);
            nums.push_back(cands[c]);
        }
        i--;
        while(i >= 0) {
            nums.pop_back();
            i--;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        comb(0, candidates, target);
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 69.97% of C++ online submissions for Combination Sum.
Memory Usage: 11.2 MB, less than 46.87% of C++ online submissions for Combination Sum.
*/


// 2022.2.17
// ..w
