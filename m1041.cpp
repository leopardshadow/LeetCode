
// 2022.1.9

/*
Hint 2 對我滿有用的 (一開始我還想用 map 去存走過的點之類的 ...)
The robot stays in the circle if and only if (looking at the final vector) it changes direction (ie. doesn't stay pointing north), or it moves 0.
---
但這個 Hint 也不是這麼好懂

如果在一套 instructions，移動是 (+Δx, +Δy)，而且朝向從北轉 90 度到東，那下一套指令造成的移動是 (+Δy, -Δx)
總共四套指令完成後，robot 會回到原點，同時朝向北方

以此類推其他方向
0 > 1 > 2 > 3 > 0
0 > 2 > 0
0 > 3 > 2 > 1 > 0
---
所以如果一開始回到原點 or 一套指令後朝向不是北方，就會讓 robot 進入 circle
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        int x = 0, y = 0;
        int face = 0;
        //          0 -> 1 -> 2 -> 3 (turn right)
        int dx[4] = {0, 1,  0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        /*
               0
               ^
               |
       3 <-----------> 1
               |
               v
               2
        */
                
        for(const char &instr : instructions) {
            switch(instr) {
                case 'G':
                    x += dx[face];
                    y += dy[face];
                    break;
                case 'L':
                    face = (face -1 + 4) % 4;
                    break;
                case 'R':
                    face = (face + 1) % 4;
                    break;
            }
        }
        
        return (face != 0) || (x == 0 && y == 0);
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Robot Bounded In Circle.
Memory Usage: 6 MB, less than 79.18% of C++ online submissions for Robot Bounded In Circle.
*/
