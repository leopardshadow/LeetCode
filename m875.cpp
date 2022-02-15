// 2022.1.20

/*
binary search
*/


/ ???
class Solution {
    int calH(vector<int>& piles, int k) {
        int hr = 0;
        for(const int &p : piles) {
            hr += (int)(1.0 * p / k + 0.99999);  // ceiling
        }
        return hr;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 10000, m;
        while(l <= r) {
            
            m = (l + r) / 2;
            
            if(calH(piles, m - 1) > h && calH(piles, m) == h && calH(piles, m + 1) < h)
                return m;
            else if(calH(piles, m) > h)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
};


// AC code
class Solution {
    int calH(const vector<int>& piles, int k) {
        int hr = 0;
        for(const int &p : piles)
            hr += p / k + (p % k != 0);

        
            // hr += (int)(1.0 * p / k + 0.99999);  // ceiling
        return hr;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = -1, m;
        
        for(const int &p : piles)
            r = max(r, p);
        
        while(l < r) {
            
            m = (l + r) / 2;
            
            if(calH(piles, m) > h)  // too slow, needs faster
                l = m + 1;
            else  // too fast, needs slower
                r = m;
        }
        return r;
    }
};
