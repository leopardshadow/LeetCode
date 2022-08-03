//***************************************************************************//
// 2021.11.30 before G VO


/*
判斷條件好難寫喔 @@
目前還是 WA
---
["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
[[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[9,13],[18,27]]
---

先暫時放棄惹 嗚嗚嗚嗚嗚嗚

可以 binary search 加速
*/

class MyCalendar {
    vector<pair<int, int>> times;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(!times.size()) {
            times.insert(times.begin(), {start, end});
            return true;
        }
        // (new)  === times === 
        if(times.size() && times[0].first >= end) {
            times.insert(times.begin(), {start, end});
            return true;
        }
        // === times ===  (new)
        if(times.size() && times.back().second <= start) {
            times.push_back({start, end});
            return true;
        }
        auto it = times.begin();

        for(it = times.begin(); it != times.end(); it++) {
            if(start >= it->first) {
                break;
            }
        }
        if(it != times.begin()) {
            it--;
        }
        
        if(it != times.begin()) {
            if(prev(it)->second > start)
                return false;
        }
        if(it != times.end()) {
            if(it->first < end)
                return false;
        }
        times.insert(it, {start, end});

        return true;
    }
};



// 2022.8.3

/*
暴力也會過耶
*/

class MyCalendar {
    vector<pair<int, int>> cal;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto &p : cal) {
            if (end > p.first && start < p.second)
                return false;
        }
        cal.push_back({start, end});
        return true;
    }
};
/*
Runtime: 145 ms, faster than 65.04% of C++ online submissions for My Calendar I.
Memory Usage: 37.7 MB, less than 77.01% of C++ online submissions for My Calendar I.
*/

