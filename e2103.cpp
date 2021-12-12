// Weekly Contest 271

class Solution {
public:
    int countPoints(string rings) {
        
        int rods[10] = {0};
        
        for(int i = 0; i < rings.length() / 2; i++) {
            
            int n = rings[2 * i + 1] - '0';
            
            if(rings[2 * i] == 'R')
                rods[n] |= 1;
            else if(rings[2 * i] == 'G')
                rods[n] |= 2;
            else
                rods[n] |= 4;
        }
        int ans = 0;
        for(int i = 0; i < 10; i++) {
            if(rods[i] == 7)
                ans++;
        }
        return ans;
    }
};

// Weekly Contest 271

class Solution {
public:
    int countPoints(string rings) {
        
        int rods[10] = {0};
        
        for(int i = 0; i < rings.length() / 2; i++) {
            
            int n = rings[2 * i + 1] - '0';
            
            if(rings[2 * i] == 'R')
                rods[n] |= 1;
            else if(rings[2 * i] == 'G')
                rods[n] |= 2;
            else
                rods[n] |= 4;
        }
        int ans = 0;
        for(int i = 0; i < 10; i++) {
            if(rods[i] == 7)
                ans++;
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rings and Rods.
Memory Usage: 6.3 MB, less than 42.86% of C++ online submissions for Rings and Rods.
*/
