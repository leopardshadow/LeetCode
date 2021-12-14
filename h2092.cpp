// Weekly Contest 269


/*
自己覺得最困難的地方是「同時 share」訊息這件事
在時間 t 可能有 3-4, 2-3, 1-2, 0-1，在 t 結束時，0, 1, 2, 3, 4 都會有 secret，但這是從 0-1 那邊慢慢擴散出去的
---
猜測應該和 graph 和 topological sort 有關係，但是不大確定，剩下時間不夠
---
每次 Leetcode 的比賽都沒有在時間內解出 hard 過 QQ
常常是有寫出一版答案，但是會超時..
*/



class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> secret(n, false);
        secret[0] = true;
        secret[firstPerson] = true;
        
        sort(meetings.begin(), meetings.end(), [](vector<int> a, vector<int> b){
            return a[2] < b[2];
        });
        
        meetings.push_back({0, 0, 10000000});
        
        
        // vector<vector<int>> table(n, vector<int>(n, -1));
        
        
        vector<vector<int>> atTimeK;
        
        int prevTime = meetings[0][2];
        //
        if(secret[meetings[0][0]] && !secret[meetings[0][1]]) {
            secret[meetings[0][1]] = true;
        }
        else if(!secret[meetings[0][0]] && secret[meetings[0][1]]) {
            secret[meetings[0][0]] = true;
        }
        else
            atTimeK.push_back(meetings[0]);

        
        for(int i = 1; i < meetings.size(); i++) {
            
            if(prevTime == meetings[i][2]) {
            }
            else {
                // process atTimeK
                bool newAdd;
                do{
                    newAdd = false;
                    int m = 0;
                    while(m < atTimeK.size()) {
                        if(secret[atTimeK[m][0]] && !secret[atTimeK[m][1]]) {
                            secret[atTimeK[m][1]] = true;
                            newAdd = true;
                            atTimeK.erase(atTimeK.begin() + m);
                        }
                        else if(!secret[atTimeK[m][0]] && secret[atTimeK[m][1]]) {
                            secret[atTimeK[m][0]] = true;
                            newAdd = true;
                            atTimeK.erase(atTimeK.begin() + m);
                        }
                        else
                            m++;
                    }
                } while(newAdd);
                    
                //
                atTimeK.clear();
            }
            
            
            if(secret[meetings[i][0]] && !secret[meetings[i][1]]) {
                secret[meetings[i][1]] = true;
            }
            else if(!secret[meetings[i][0]] && secret[meetings[i][1]]) {
                secret[meetings[i][0]] = true;
            }
            else
                atTimeK.push_back(meetings[i]);

            prevTime = meetings[i][2];
            
            // if(secret[meetings[i][0]])
            //     secret[meetings[i][1]] = true;
        }
        
        vector<int> ans;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i])
                ans.push_back(i);
        }
        return ans;
    }
};

//******************************************************************************//
/*
寫了簡單版本的 union find，但還是 TLE QQ
看來要加上 map 了
*/

/*
disjoint set 優化：

1. path compression
2. union by rank
---
~~(感覺在面試寫出有 path compression 的就好w，rank 好容易錯的感覺)~~
其實也還好，就只是判斷一下 x 和 y 誰比較大，讓大的吃下小的，要是都一樣，那 rank 無可避免地會 +1
除了一開始把大家 rank 都設成 1 之外，就只有這時候會碰到 rank (估算值，path compression 時也會動到，但大家忽略不計)
---
但即使這樣，還是會 TLE，我讓 reset 那邊不要全部跑過，而是用一個 vector toReset 紀錄才跑出 AC

這裡有個有趣的問題
---
*/

class UnionFind {
    vector<int> nodes;
    vector<int> ranks;
    vector<int> toReset;
    int n;
public:
    UnionFind(int n) : nodes(n), ranks(n, 1) {
        this->n = n;
        for(int i = 0; i < n; i++) {
            nodes[i] = i;
        }
    }
    int find(int x) {
        if(x == nodes[x])
            return x;
        return nodes[x] = find(nodes[x]);
    }
    // change x's value to y's
    void connect(int x, int y) {
        int rootX = find(x),
            rootY = find(y);
        nodes[rootX] = rootY;
        if(rootX != rootY) {
            if (ranks[rootX] > ranks[rootY]) {
                nodes[rootY] = rootX;
            } 
            else if(ranks[rootX] < ranks[rootY]) {
                nodes[rootX] = rootY;
            } 
            else {
                nodes[rootY] = rootX;
                ranks[rootX] += 1;
            }
        }
        toReset.push_back(x);
        toReset.push_back(y);
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    void reset() {
        for(int i : toReset) {
            if(!isConnected(0, i))
                nodes[i] = i;
        }
        toReset.clear();
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        // sort the meetings by their time
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        
        UnionFind uf(n);
        
        uf.connect(0, firstPerson);
        uf.connect(meetings[0][0], meetings[0][1]);
        
        for(int i = 1; i < meetings.size(); i++) {
                        
            if(meetings[i][2] != meetings[i-1][2]) {
                uf.reset();
            }
            uf.connect(meetings[i][0], meetings[i][1]);
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(uf.isConnected(0, i))
                ans.push_back(i);
        }
        return ans;
    }
};


/*
Runtime: 746 ms, faster than 52.72% of C++ online submissions for Find All People With Secret.
Memory Usage: 138.9 MB, less than 84.88% of C++ online submissions for Find All People With Secret.
*/

//******************************************************************************//
/*
拿掉 rank 反而更快?????
Leetcode 的執行時間真的很謎
*/

class UnionFind {
    vector<int> nodes;
    vector<int> toReset;
    int n;
public:
    UnionFind(int n) : nodes(n) {
        this->n = n;
        for(int i = 0; i < n; i++) {
            nodes[i] = i;
        }
    }
    int find(int x) {
        if(x == nodes[x])
            return x;
        return nodes[x] = find(nodes[x]);
    }
    // change x's value to y's
    void connect(int x, int y) {
        int rootX = find(x),
            rootY = find(y);
        nodes[rootX] = rootY;

        toReset.push_back(x);
        toReset.push_back(y);
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    void reset() {
        for(int i : toReset) {
            if(!isConnected(0, i))
                nodes[i] = i;
        }
        toReset.clear();
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        // sort the meetings by their time
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        
        UnionFind uf(n);
        
        uf.connect(0, firstPerson);
        uf.connect(meetings[0][0], meetings[0][1]);
        
        for(int i = 1; i < meetings.size(); i++) {
                        
            if(meetings[i][2] != meetings[i-1][2]) {
                uf.reset();
            }
            uf.connect(meetings[i][0], meetings[i][1]);
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(uf.isConnected(0, i))
                ans.push_back(i);
        }
        return ans;
    }
};

// 一樣的 code，差超多的執行時間

/*
Runtime: 592 ms, faster than 82.15% of C++ online submissions for Find All People With Secret.
Memory Usage: 142 MB, less than 82.39% of C++ online submissions for Find All People With Secret.
*/

/*
Runtime: 872 ms, faster than 42.22% of C++ online submissions for Find All People With Secret.
Memory Usage: 141.9 MB, less than 82.58% of C++ online submissions for Find All People With Secret.
*/
