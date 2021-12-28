
//******************************************************************************//
// 12.28 - 1 Day Before A VO

/*
這題算是滿經典的題目，感覺常常看到
---
如果是重頭手刻的話會用到 doubly linked list，剛好最近看了 C++ STL 的 list，來用用看
---
移除 k 個之前的部分是用 list 把值都串在一起，頭表示最舊，尾是最新
從 key 找到 value 用的是 unordered_map
---
如果有加 key-value pair，或是 get 指定 key 都會改動 list
---
* 加入 key-value pair 會分兩種情況
    1. key 存在：把 list 代表他的拔掉，加到最尾，並更新 map
    2. key 不存在：加到最尾，並更新 map
* 取得指定 key 的值
    把 list 中代表他的 node 移動到尾巴 (最新)，並更新 map
---
總而言之，大方向的概念是因為我們有兩種資訊想要保存，所以用兩種不同資料結構來表示，兩者互相指對方
當需要更動內容時，會兩個資料結構一起更新
*/

class LRUCache {
    int capacity;
    list<pair<int, int>> l;  // key, value
    unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.count(key)) {
            auto value = m[key]->second;
            l.erase(m[key]);
            auto node = l.insert(l.end(), {key, value});
            m[key] = node;
            return value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        
        // if the key already exist
        if(m.count(key)) {
            l.erase(m[key]);
        }
        auto node = l.insert(l.end(), {key, value});
        m[key] = node;
        
        // remove least recently used data
        if(l.size() > capacity) {
            auto lru = l.begin();
            m.erase(lru->first);
            l.erase(l.begin());
        }
    }
};

// 用 unordered_map
/*
Runtime: 392 ms, faster than 82.54% of C++ online submissions for LRU Cache.
Memory Usage: 174.2 MB, less than 34.34% of C++ online submissions for LRU Cache.
*/

// 用 map
/*
Runtime: 472 ms, faster than 24.88% of C++ online submissions for LRU Cache.
Memory Usage: 174.5 MB, less than 29.22% of C++ online submissions for LRU Cache.
*/
