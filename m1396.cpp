
// 2022.4.24

/*
這週好像都是 design 類的題目
---
今天打了 Kickstart 2022 Round B 和 Weekly Contest 290
*/

class UndergroundSystem {
    map<int, pair<string, int>> m;
    map<string, pair<int, int>> times; 
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        // (check id)
        string key = m[id].first + "->" + stationName;
        times[key] = make_pair(times[key].first + (t - m[id].second), times[key].second + 1);
        m.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "->" + endStation;
        return (double) times[key].first / times[key].second;
    }
};

/*
Runtime: 178 ms, faster than 69.98% of C++ online submissions for Design Underground System.
Memory Usage: 59.2 MB, less than 46.05% of C++ online submissions for Design Underground System.
*/
