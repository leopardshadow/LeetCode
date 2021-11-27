// Biweekly Contest 66

// greedy

class Solution {
public:
    int minimumBuckets(string street) {
        street = "X" + street + "X";
        int ans = 0;
        for(int i = 1; i < street.length() - 1; i++) {
            if(street[i] == '.' && street[i-1] == 'H' && street[i+1] == 'H') {
                street[i] = 'B';
                street[i-1] = 'h';
                street[i+1] = 'h';
                ans++;
            }
        }
        for(int i = 1; i < street.length() - 1; i++) {
            if(street[i] == '.' && (street[i-1] == 'H' || street[i+1] == 'H')) {
                street[i] = 'B';
                if(street[i-1] == 'H') street[i-1] = 'h';
                if(street[i+1] == 'H') street[i+1] = 'h';
                ans++;
            }
        }
        for(int i = 1; i < street.length() - 1; i++) {
            if(street[i] == 'H')
                return -1;
        }
        return ans;
    }
};

/*
Runtime: 46 ms, faster than 7.14% of C++ online submissions for Minimum Number of Buckets Required to Collect Rainwater from Houses.
Memory Usage: 12.5 MB, less than 14.29% of C++ online submissions for Minimum Number of Buckets Required to Collect Rainwater from Houses.
*/
