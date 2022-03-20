
// Weekly Contest 285 (2022.3.20)

/*
這題還滿有趣的
---
collision 的情況有三種：RL, RS, SL
發生 collision 後，原本移動的也會變成 S，可能對前面的造成影響
---
這題給我的感覺和 Google Kickstart 的這題很像 https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d94f5
那時候在這題我是在外面加掛迴圈，如果狀態有任何變動就全部重跑一次，Test set 1 有 AC，但 Test set 2 TLE
---
在這裡也一樣，直接加掛迴圈會 TLE
因此我用一個 queue 來存需要處理的 index
.. a x b ..
如果 x 的狀態發生改變 (從 L 或 R 變成 S)，他隔壁的 a, b 就要加進 queue 裡，x 的改變可能造成 a x 或 x b 相撞
*/


class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        queue<int> q;
        
        for(int i = 0; i < directions.size() - 1; i++)
            q.push(i);
        
         while(!q.empty()) {
             
            int i = q.front();
            q.pop();
             
            if(i < 0 || i >= directions.size())
                continue;
             
            string cars = directions.substr(i, 2);
             
            if(cars == "RL") {
                q.push(i-1);
                q.push(i);
                q.push(i+1);
                ans += 2;
                directions[i] = 'S';
                directions[i+1] = 'S';
            }
            else if(cars == "SL") {
                q.push(i);
                q.push(i+1);
                ans += 1;
                directions[i+1] = 'S';
            }
            else if(cars == "RS") {
                q.push(i-1);
                q.push(i);
                ans += 1;
                directions[i] = 'S';
            }
        }
        return ans;
    }
};
/*
Runtime: 835 ms, faster than 12.50% of C++ online submissions for Count Collisions on a Road.
Memory Usage: 42.9 MB, less than 37.50% of C++ online submissions for Count Collisions on a Road.
*/
