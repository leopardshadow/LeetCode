
// 2022.11.29

/*
這題有趣的地方是他的要求：時間複雜度 O(1)
hashmap 可以解決 insert 和 remove，但無法處理 random
所以這裡用了一個 array 來幫忙
insert 或 remove 時這個 array 也會對應的增減
insert 就直接往後加，時間複雜度 O(1)
麻煩的是 remove，如果要從中間拔時間複雜度會是 O(n)
所以這邊用了一個小技巧，把要拔的和最後一個交換位置後再拔
*/

class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> xs;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        else {
            xs.push_back(val);
            m[val] = xs.size() - 1;
            return true;
        }
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        else {
            int idx = m[val];
            m[xs.back()] = idx;
            xs[idx] = xs.back();
            m.erase(val);
            xs.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        int idx = rand() % xs.size();
        return xs[idx];
    }
};
/*
Runtime: 253 ms, faster than 85.50% of C++ online submissions for Insert Delete GetRandom O(1).
Memory Usage: 97.1 MB, less than 19.16% of C++ online submissions for Insert Delete GetRandom O(1).
*/
