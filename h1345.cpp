
// 2022.

/*
daily 出的當天沒空寫，現在把它補一補w
---
仔細看了題目發現其實這題沒有很難，用 BFS 的概念解就好
---
一開始 TLE，加了
```
group.erase(arr[x]);
```
就不 TLE 了，hmmm, 為什麼呢？
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        
        queue<int> q;
        vector<int> step(n);
        vector<bool> done(n, false);
        map<int, vector<int>> group;
        
        for(int i = 0; i < n; i++) {
            group[arr[i]].push_back(i);
        }
        q.push(0);
        done[0] = true;
        step[0] = 0;

        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(x - 1 >= 0 && !done[x-1]) {
                done[x-1] = true;
                q.push(x-1);
                step[x-1] = step[x] + 1;
            }
            if(x + 1 < n && !done[x+1]) {
                done[x+1] = true;
                q.push(x+1);
                step[x+1] = step[x] + 1;
            }
            for(const int &nxt : group[arr[x]]) {
                if(!done[nxt]) {
                    done[nxt] = true;
                    q.push(nxt);
                    step[nxt] = step[x] + 1;
                }
            }
            // 加了這行就不 TLE ??????
            group.erase(arr[x]);
        }
        
        return step.back();
    }
};

/*
Runtime: 312 ms, faster than 54.86% of C++ online submissions for Jump Game IV.
Memory Usage: 109.9 MB, less than 9.88% of C++ online submissions for Jump Game IV.
*/
