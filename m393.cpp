
// 2022.9.13

/*
parsing
*/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = 0;
        bool stat = true;  // T: #bytes, F: seq.
        for (int i = 0; i < data.size(); i++) {
            if (stat) {  // #bytes
                // 1-byte
                if ((data[i] >> 7) == 0)
                    continue;            
                else if ((data[i] >> 5) == 0x6)
                    len = 1;
                else if ((data[i] >> 4) == 0xE)
                    len = 2;
                else if ((data[i] >> 3) == 0x1E)
                    len = 3;
                else
                    return false;
                if (len > 0)
                    stat = false;
            }
            else {
                if (len < 0)
                    return false;
                if ((data[i] >> 6) == 0x2)
                    len--;
                else
                    return false;
                
                if (len == 0)
                    stat = true;
            }
        }
        return len == 0;
    }
};
/*
Runtime: 20 ms, faster than 52.62% of C++ online submissions for UTF-8 Validation.
Memory Usage: 13.8 MB, less than 91.77% of C++ online submissions for UTF-8 Validation.
*/
