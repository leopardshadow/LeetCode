
// 2022.3.18 G+

/*
好怕 monotonic stack 的題目..
---
參考了解答 QQ
---
一開始在思考的時候有個地方轉不過來：當把東西加進 stack 時，要 pop 掉已經存的東西，但是如果現在刪除了，後面沒有怎麼辦
所以用了 last index 陣列來儲存這個訊息，如果這個 character 的 last index 比較 i 大，代表可以等到後面再加進答案裡就好，現在遇到的這個可以放心 pop 掉沒關係
---
核心主要是 for 迴圈內的那個 while 迴圈，有三個條件
 - !ans.empty() 這個 while 迴圈就是要 pop 東西，沒東西當然就跳出
 - ans.back() > s[i] 代表前面的 character 比當前的 s[i] 大，**如果可以**的話想把前面的 character pop 掉
 - lastIdx[ans.back() - 'a'] > i) 這個就是對應到上一行的如果可以的話 (不能的情況就是後面已經沒有了，只能留著前面的)
而迴圈內部就是把 char pop 掉，更新目前在 stack 中 char 的狀況
---
其實 monotonic stack 很多都有固定的模式

把每個元素跑過一次 {
    while 假如這個元素加入後，還是要維持某種 monotonic 的性質，用這個元素去掃 stack
    把這個元素加進 stack
}
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> lastIdx(26, -1);
        vector<bool> added(26, false);

        for(int i = 0; i < s.length(); i++)
            lastIdx[s[i] - 'a'] = i;
        
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            if(added[s[i] - 'a'])
                continue;
            while(!ans.empty() && ans.back() > s[i] && lastIdx[ans.back() - 'a'] > i) {
                added[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            added[s[i] - 'a'] = true;
        }
        
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Duplicate Letters.
Memory Usage: 6.5 MB, less than 92.50% of C++ online submissions for Remove Duplicate Letters.
*/


// 錯誤的邏輯 嗚嗚嗚
class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> places(26, -1);
        
        for(int i = 0; i < s.size(); i++) {
            if(places[s[i] - 'a'] == -1)
                places[s[i] - 'a'] = i;
            
            for(int ch = 0; ch <= s[i] - 'a'; ch++) {
                if(places[ch] != -1) {
                    places[s[i] - 'a'] = i;
                    break;
                }
            }
        }
        
        vector<pair<int, char>> temp;
        for(int i = 0; i < 26; i++) {
            if(places[i] != -1)
                temp.push_back({places[i], 'a' + i});
        }
        sort(temp.begin(), temp.end());
        
        string ans = "";
        for(auto p : temp)
            ans.push_back(p.second);
        
        return ans;
    }
};
