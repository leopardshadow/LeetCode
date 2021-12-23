// Same as 207. but 207 returns true/false

class Course {
public:
    int inDeg;  // you need to take inDeg courses before taking this one
    vector<int> nextC;  // the course is other courses'  nextCequisites
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<Course> courses(numCourses);
        // 1 -> 0
        for(int i = 0; i < prerequisites.size(); i++) {
            courses[ prerequisites[i][1] ].nextC.push_back( prerequisites[i][0] );
            courses[ prerequisites[i][0] ].inDeg++;
        }
        
        vector<int> ans;
        
        // find out courses that didn't need prerequisites        
        vector<int> q;
        for(int i = 0; i < courses.size(); i++) {
            if(courses[i].inDeg == 0) {
                q.push_back(i);
                ans.push_back(i);
            }
        }
        
        //
        while(!q.empty()) {
          
            for(int i = 0; i < courses[q[0]].nextC.size(); i++) {
                courses[courses[q[0]].nextC[i]].inDeg--;
                if(courses[courses[q[0]].nextC[i]].inDeg == 0) {
                    q.push_back(courses[q[0]].nextC[i]);
                    ans.push_back(courses[q[0]].nextC[i]);
                }

            }
            q.erase(q.begin());
        }        
        
        for(int i = 0; i < numCourses; i++) {
            if(courses[i].inDeg > 0)
                return vector<int>();
        }
        return ans;
    }
};
/*
Runtime: 12 ms, faster than 99.40% of C++ online submissions for Course Schedule II.
Memory Usage: 13.2 MB, less than 94.85% of C++ online submissions for Course Schedule II.
*/






// 2021.12.23

/*
感覺最近的 daily 題好常遇到做過的喔
---
就 topologocal sort
*/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
        vector<pair<int, vector<int>>> cs(numCourses);
        
        // p[1] --> p[0]
        for(auto p : prerequisites) {
            cs[p[0]].first++;
            cs[p[1]].second.push_back(p[0]);
        }
        
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(cs[i].first == 0)
                q.push(i);
        }
        while(!q.empty()) {
            
            int take = q.front();
            q.pop();
            ans.push_back(take);
            
            for(auto next : cs[take].second) {
                cs[next].first--;
                if(cs[next].first == 0)
                    q.push(next);
            }
        }
        // 題目要求如果無法修完所有課 (有 circle)，就回傳空的
        if(ans.size() < numCourses)
            return {};
        return ans;
    }
};

/*
Runtime: 24 ms, faster than 47.25% of C++ online submissions for Course Schedule II.
Memory Usage: 14 MB, less than 61.22% of C++ online submissions for Course Schedule II.
*/
