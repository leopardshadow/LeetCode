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
