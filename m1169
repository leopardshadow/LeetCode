/*
玩了一下 Leetcode 的 online assessment 練習，這是兩題中的第一題
我用 map 來記錄相同的名字
感覺難點在 parsing (?
*/

class Trans {
public:
    string city, orig;
    int time, amount;
    bool added = false;
    
    Trans(string orig, int time, string city, int amount) {
        this->orig = orig;
        this->time = time;
        this->city = city;
        this->amount = amount;
    }
};

class Solution {
public:
    
    map<string, vector<Trans> > m;
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        for(string tr : transactions) {
            
            string name, city;
            int time, amount;
            
            int start = 0, len = 0, curStat = 0;
            while(1) {
                if(tr[start+len] != ',') {
                    len++;
                }
                else {
                    if(curStat == 0) {
                        name = tr.substr(start, len); 
                    }
                    else if(curStat == 1) {
                        time = stoi(tr.substr(start, len));
                    }
                    else if(curStat == 2) {
                        amount = stoi(tr.substr(start, len));
                        city = tr.substr(start + len + 1);
                        break;
                    }
                    curStat++;
                    start = start + len + 1;
                    len = 0;
                }
            } // end of parsing
            
            Trans t = Trans(tr, time, city, amount);
            
            if(amount > 1000) {
                ans.push_back(tr);
                t.added = true;
            }
                
            m[name].push_back(t);
        }
        
        for(map<string, vector<Trans> >::iterator it = m.begin(); it != m.end(); it++) {
            for(int i = 0; i < it->second.size() - 1; i++) {
                for(int j = i + 1; j < it->second.size(); j++) {
                    Trans *transA = &it->second[i];
                    Trans *transB = &it->second[j];
                    if(transA->city != transB->city && 
                       abs(transA->time - transB->time) <= 60)
                    {
                        if(!transA->added) {
                            ans.push_back(transA->orig);
                            transA->added = true;
                        }
                        if(!transB->added) {
                            ans.push_back(transB->orig);
                            transB->added = true;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};

/*
Runtime: 20 ms, faster than 92.05% of C++ online submissions for Invalid Transactions.
Memory Usage: 14.8 MB, less than 60.26% of C++ online submissions for Invalid Transactions.
*/
