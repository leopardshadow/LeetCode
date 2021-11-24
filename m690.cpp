// Google

/*
這題其實本身要解出來不難，對我來說比較麻煩的是 subordinates 存的是 id，一開始我把它弄成 Employee*
如果在面試時弄錯不是一件好事誒，和 phone interview 那次一樣 @@

話說看別人的截圖，這題在之前是 easy，但現在是 medium，不知道是以什麼條件升級的
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // find the employee with designated id
        unordered_map<int, Employee*> id2employee;
        Employee *target;
        for(int i = 0; i < employees.size(); i++) {
            id2employee[employees[i]->id] = employees[i];
            if(employees[i]->id == id)
                target = employees[i];
        }
        // do BFS search
        queue<Employee*> q;
        unordered_map<Employee*, bool> visited;
        int ans = target->importance;
        visited[target] = true;
        q.push(target);
        while(!q.empty()) {
            target = q.front();
            q.pop();
            for(int i = 0; i < target->subordinates.size(); i++) {
                if(visited.find(id2employee[target->subordinates[i]]) == visited.end()) {
                    ans += id2employee[target->subordinates[i]]->importance;
                    visited[id2employee[target->subordinates[i]]] = true;
                    q.push(id2employee[target->subordinates[i]]);
                }
            }
        }
        return ans;
    }
};


// 用 map
/*
Runtime: 59 ms, faster than 16.93% of C++ online submissions for Employee Importance.
Memory Usage: 14.2 MB, less than 47.85% of C++ online submissions for Employee Importance.
*/


// 用 unordered_map
/*
Runtime: 28 ms, faster than 83.45% of C++ online submissions for Employee Importance.
Memory Usage: 14.3 MB, less than 37.29% of C++ online submissions for Employee Importance.
*/
