
// 2022.7.30

/*
Key: words2 'a' 和 'aaa' 只要取後者，取大的
這樣可以把 TC 縮成 O(A + B)
直接比的話 TC O(A B) 會 TLE ...
*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> ans;
        
        
        vector<int> pat2(26, 0);
        for (int i = 0; i < words2.size(); i++) {
            vector<int> p2(26, 0);
            for (const char &c : words2[i])
                p2[c - 'a']++;
            for (int a = 0; a < 26; a++)
                pat2[a] = max(pat2[a], p2[a]);
        }
        
        vector<vector<int>> pat1(words1.size(), vector<int>(26, 0));
        for (int i = 0; i < words1.size(); i++)
            for (const char &c : words1[i])
                pat1[i][c - 'a']++;

        
        for (int i = 0; i < words1.size(); i++) {
            bool add = true;
            for (int a = 0; a < 26; a++) {
                if (pat2[a] > pat1[i][a]) {
                    add = false;
                    break;
                }
            }
            if (add)
                ans.push_back(words1[i]);
        }
        return ans;  
    }
};
/*
Runtime: 443 ms, faster than 29.67% of C++ online submissions for Word Subsets.
Memory Usage: 105.5 MB, less than 31.69% of C++ online submissions for Word Subsets.
*/
