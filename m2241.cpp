
// Biweekly Contest 76

/*
模擬，就按照他說的做~
要小心 overflow 的問題，還有他的規則一開始我理解錯誤（英文問題 ... 嗚嗚）
*/

class ATM {
    vector<long long> notes;  // 20 50 100 200 500
    vector<long long> ns;
public:
    ATM() : notes(5, 0), ns({20, 50, 100, 200, 500}) {
    
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++)
            notes[i] += (long long)banknotesCount[i];
    }
    
    vector<int> withdraw(int a) {
        
        vector<long long> delta(5, 0);
        long long amount = a;
        
        
        // for (int i = 4; i >= 0; i--)
        //     cout << "i = " << i << " " << notes[i] << endl;
        // cout << endl;
        
        for (int i = 4; i >= 0; i--) {
            
            // cout << "i = " << i << " " << notes[i] << endl;
            
            if (notes[i] == 0)
                continue;
            
            delta[i] = min(amount / ns[i], notes[i]);
            // cout << amount << " " << ns[i] << endl;
            // cout << "delta = " << delta[i] << endl;
            // cout << "notes = " << notes[i] << endl;
            // if (delta[i] > notes[i])
            //     return {-1};
            
            amount = amount - ns[i] * delta[i];
        }
        if (amount != 0)
            return {-1};
            
        for (int i = 0; i < 5; i++)
            notes[i] -= delta[i];
        
        return {(int)delta[0], (int)delta[1], (int)delta[2], (int)delta[3], (int)delta[4]};
    }
};
// 都是 66.67% 耶，2 / 3
/*
Runtime: 700 ms, faster than 66.67% of C++ online submissions for Design an ATM Machine.
Memory Usage: 108.2 MB, less than 66.67% of C++ online submissions for Design an ATM Machine.
*/
