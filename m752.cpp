// https://blog.techbridge.cc/2019/12/21/leetcode-%E5%88%B7%E9%A1%8C-pattern-breadth-first-search/
/*
超帥，可以用 BFS 解
---
這題好多 corner case 喔，要小心，包括
* 頭 ("0000") 本身是 deadends
* 尾 (target) 本身是 deadends
* 如果把所有能走的都走過一次，但不能到達 target
* 如果 target 就是 "0000"

沒有考慮清楚害我吃了好幾個 WA...QQ
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        // corner case
        if(target == "0000")
            return 0;
        
        unordered_set<string> deadM;
        for(string d : deadends)
            deadM.insert(d);
        
        unordered_map<string, int> m;
        queue<string> q;
        if(!deadM.count("0000"))
            q.push("0000");
        m["0000"] = 0;
        
        while(!q.empty()) {

            string curStr = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                for(int d = -1; d <= 1; d+=2) {
                    string newStr = curStr;
                    newStr[i] = (newStr[i] - '0' + d + 10) % 10 + '0';
                    if(deadM.count(newStr) || m[newStr] != 0)
                        continue;
                    //*********************//
                    if(newStr == target) {
                        return m[curStr] + 1;
                    }
                    //*********************//    
                    //
                    q.push(newStr);
                    m[newStr] = m[curStr] + 1;
                }
            }
        }
        return -1; // go through every possibilities but cannot find
    }
};

/*
Runtime: 172 ms, faster than 71.50% of C++ online submissions for Open the Lock.
Memory Usage: 35.2 MB, less than 60.93% of C++ online submissions for Open the Lock.
*/
