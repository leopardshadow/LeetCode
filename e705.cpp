
// 2022.4.21

/*
這題題目滿有趣的，要自己設計 hash set
但我用偷懶的方式解ㄌ
面試時還要注意 input 參數的範圍問題，不過這裡他說 0 <= key <= 1e6，我就不特別判斷了
*/

class MyHashSet {
    vector<bool> sets;
public:
    MyHashSet() : sets(1000001, false) {
        
    }
    
    void add(int key) {
        sets[key] = true;
    }
    
    void remove(int key) {
        sets[key] = false;
    }
    
    bool contains(int key) {
        return sets[key];
    }
};
/*
Runtime: 106 ms, faster than 77.41% of C++ online submissions for Design HashSet.
Memory Usage: 43.5 MB, less than 43.81% of C++ online submissions for Design HashSet.
*/
