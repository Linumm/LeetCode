class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Finding "Cycle" in Directed Graph
        // Using DFS
        vector<int> visited(numCourses, 0); //0: Never visited, 1:In this search, visited, 2: visited in process
        vector<int> adj[numCourses];
        
        // Push edge vertices to adjacent matrix
        for (auto i: prerequisites) 
            adj[i[0]].push_back(i[1]);
        
        // Check the cycle from 0
        for (int i=0; i<numCourses; i++)
            if (isCycle(adj, visited, i))
                return false;
        
        return true;
    }
    bool isCycle(vector<int> adj[], vector<int>& visited, int current_node)
    {
        if (visited[current_node] == 1) // visited in current search process
            return true;
        if (visited[current_node] == 0) { // not visited yet
            visited[current_node] = 1; // now check
            
            for (auto edge: adj[current_node])
                if (isCycle(adj, visited, edge))
                    return true;
        }
        visited[current_node] = 2;
        return false;
    }
};