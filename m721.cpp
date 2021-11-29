// 2021.11.29
//***************************************************************************//
// 2021.11.29 before G VO :))

/*
又是這種合併的題目，剛結束的 Weekly Contest 269 - 2092. Find All People With Secret 也是這類型的
不過他那題感覺一定要用 union find，因為還包含了時間資訊，要一直重建 map 嗎(?)
---
這題可以用 graph 的 connected components 解
在建立 graph 之前，要先想好用哪種方式，這裡我用 adjacency list
幾個地方注意
1.
建 adjacency list 或 adjacency matrix 時，如果 1 2 3 4 是相連的，不用建一個全 1 的矩陣或每個鄰居數都是 3 的 list
因為他只要相鄰就好，就用最少的 1 -> 2, 3, 4 而 2, 3, 4 又各自連到 1 就好，不然到時候要檢查一堆，浪費時間

2.
在這裡 email 對應到 name，我只用了第一個 email。當然每一個 email 都會對應到一個名字，但每次我都是從 firstEmail 出發去找，就不多浪費空間惹

3.
這題 email 和 name 都是 string，要想清楚哪個 string 代表的是什麼，他應該被怎麼用
像是 graph 定義的 string 到 list of string 是 email 到跟他屬於同一個人的 email，跟 name 完全沒關係
*/

class Solution {
    //           adjacency list (bi-directional graph: from email to email)
    unordered_map<string, vector<string>> graph;
    unordered_map<string,string> emailToName; // first email to name
    unordered_set<string> visited; // email

    vector<vector<string>> ans;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // construct the graph
        for(auto account : accounts) {
            string name = account[0];
            string firstEmail = account[1]; // representative
            emailToName[firstEmail] = name;

            for(int j = 2; j < account.size(); j++) {
                graph[firstEmail].push_back(account[j]);
                graph[account[j]].push_back(firstEmail);
            }
        }
        
        for(auto account : accounts) {
            
            if(visited.count(account[1]))
                continue;
            
            vector<string> onePerson;
            string name = emailToName[account[1]];
            onePerson.push_back(name);
            queue<string> q;  // email
            q.push(account[1]);
            while(!q.empty()) {
                string email = q.front();
                q.pop();

                if(visited.count(email))
                    continue;
                
                onePerson.push_back(email);
                visited.insert(email);
                
                for(auto adjEmail : graph[email]) {
                    if(!visited.count(adjEmail)) {
                        q.push(adjEmail);
                    }
                }
            }
            sort(onePerson.begin() + 1, onePerson.end());
            ans.push_back(onePerson);
        }
        return ans;
    }
};

/*
Runtime: 116 ms, faster than 67.02% of C++ online submissions for Accounts Merge.
Memory Usage: 55.3 MB, less than 14.68% of C++ online submissions for Accounts Merge.
*/
