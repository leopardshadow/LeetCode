
/*
Note. 通常 Graph 可以用
        * adjacency matrix 或
        * adjacency list 來實作
*/
class Course {
public:
    int inDeg;  // you need to take inDeg courses before taking this one
    vector<int> nextC;  // the course is other courses'  prerequisites
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<Course> courses(numCourses);
        // 1 -> 0
        for(int i = 0; i < prerequisites.size(); i++) {
            courses[ prerequisites[i][1] ].nextC.push_back( prerequisites[i][0] );
            courses[ prerequisites[i][0] ].inDeg++;
        }
        
        // find out courses that didn't need prerequisites        
        vector<int> q;
        for(int i = 0; i < courses.size(); i++) {
            if(courses[i].inDeg == 0) {
                q.push_back(i);
            }
        }
        
        //
        while(!q.empty()) {
          
            for(int i = 0; i < courses[q[0]].nextC.size(); i++) {
                courses[courses[q[0]].nextC[i]].inDeg--;
                if(courses[courses[q[0]].nextC[i]].inDeg == 0)
                    q.push_back(courses[q[0]].nextC[i]);
            }
            q.erase(q.begin());
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(courses[i].inDeg > 0)
                return false;
        }
        return true;
        
    }
};

/*
Runtime: 12 ms, faster than 99.44% of C++ online submissions for Course Schedule.
Memory Usage: 13.1 MB, less than 92.46% of C++ online submissions for Course Schedule.
*/