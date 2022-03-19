
// 2022.3.19

/*
這題是 hard，帶給我的感覺跟面試的 stack 很像，都是要連來連去
---
我原本的寫法很長，而且會 TLE，看了討論區才知道和別人差距有多大，別人的又快又漂亮 QQ
---
這個寫法主要用 heap 來挑現在要 pop 誰，判斷的順序是 1.出現次數 2.出現的編號
在這個寫法裡用 pair<int, pair<int, int>> 來做，會先判斷 first 再來是 second.first
同一個數字會被 push 好幾次，但也沒差，因為 frequency 是連續變化的
例如連續存了三個 8 {出現次數, 出現的編號, 誰}，出現編號從 0 開始編
{1, 0, 8} {2, 1, 8} {3, 2, 8} 這三個東西會被 push 進 heap 裡，到時候第一個被拿出來的是第三個，可以抓出數字是 8，其他也一樣
---
lee215 的作法也滿值得一看的，他用了和這個不一樣的作法
他宣告了三個東西
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    int maxfreq = 0;
freq 是數字 x 對應到的次數
而 m 則是該次數對應到的數字，這裡巧妙得運用了 stack，所以不用存出現的編號，相互關係已經藏在 stack 中！
---
用出現編號的寫法，如果我是面試官就會問如果 push 超過 int 範圍的次數 (但有 pop，記憶體沒有爆炸) 要怎麼辦
我那時候想的是快超過時可以幫他們重新編號，例如 2 < 3 < 10，會被編成 0 < 1 < 2，只要相互關係不變就好
這個選取的過程會用到 heap，移動的感覺跟 merge k sorted list 會很像
*/

class FreqStack {
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> freq;
    int stamp;
public:
    FreqStack() {
        stamp = 0;
    }
    
    void push(int val) {
        freq[val] += 1;
        stamp += 1;
        pq.push({freq[val], {stamp, val}});
    }
    
    int pop() {
        auto val = pq.top();
        pq.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};
/*
Runtime: 180 ms, faster than 87.55% of C++ online submissions for Maximum Frequency Stack.
Memory Usage: 79 MB, less than 93.90% of C++ online submissions for Maximum Frequency Stack.
*/


// 自己想的 TLE 的作法
class FreqStack {
    map<int, int> nToOccur;
    map<int, set<int>> occurToN;
    map<int, stack<int>> nToIdx;
    int id;
    
    void update(int val, int delta) {
        occurToN[ nToOccur[val] ].erase(val);
        if(occurToN[ nToOccur[val] ].size() == 0) {
            occurToN.erase(nToOccur[val]);
        }
        nToOccur[val] += delta;
        occurToN[ nToOccur[val] ].insert(val);
    }
public:
    FreqStack() {
        id = 0;
    }
    
    void push(int val) {

        update(val, +1);
        nToIdx[val].push(id);
        id++;
    }
    
    int pop() {
        
        int rmNum = *occurToN.rbegin()->second.begin();
        for(int cand : occurToN.rbegin()->second) {
            if(nToIdx[cand].top() > nToIdx[rmNum].top())
                rmNum = cand;
        }
        update(rmNum, -1);
        nToIdx[rmNum].pop();

        return rmNum;
    }
};
