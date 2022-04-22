
// 2022.4.22

/*
昨天是 hash set，今天是 hash map
偷懶..
*/

class MyHashMap {
    vector<int> maps;
public:
    MyHashMap() : maps(1000001, -1)  {
        
    }
    
    void put(int key, int value) {
        maps[key] = value;
    }
    
    int get(int key) {
        return maps[key];
    }
    
    void remove(int key) {
        maps[key] = -1;
    }
};
