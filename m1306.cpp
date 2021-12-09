/*
Hint: BFS
---
一開始看錯題目，他問的是 check if you can reach to **any** index with value 0

我原本把題目整個看錯 @@ i 可以跳到 i + arr[i] or i - arr[i] with 0-cost，問能不能到 **every** index，但題目根本不是這個意思...

只要在走的過程中有遇到 0，任何一個 0，都可以回傳 true
全部走完後如果都沒遇到 0，最後就回傳 false
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        vector<bool> visited(arr.size(), false);
        
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        if(arr[start] == 0)
            return true;
        
        while(!q.empty()) {
            int pos = q.front();
            q.pop();
            
            int newPos = pos + arr[pos];
            if(newPos < arr.size() && !visited[newPos]) {
                if(arr[newPos] == 0)
                    return true;
                q.push(newPos);
                visited[newPos] = true;
            }
            newPos = pos - arr[pos];
            if(newPos >= 0 && !visited[newPos]) {
                if(arr[newPos] == 0)
                    return true;
                q.push(newPos);
                visited[newPos] = true;
            }
        }
        return false;
    }
};


/*
Runtime: 94 ms, faster than 8.17% of C++ online submissions for Jump Game III.
Memory Usage: 31.2 MB, less than 83.03% of C++ online submissions for Jump Game III.
*/
