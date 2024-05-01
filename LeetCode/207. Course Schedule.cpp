class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            Finishing all courses means we need to find a valid topological ordering, but the problem
            doesn't ask to find the ordering but to check if it exists.
            A topological ordering exists if and only if the given graph(prerequisites) has no cycles, it means
            if the given graph is DAG we can always at least one valid ordering.
            Checking graph acyclicity can be easily done using dfs(depth first search).
            We need to run dfs for each connected component in the graph. A vertex should pass throw 3 states:
            - Unvisited State: we mark the vertex with color white(0)
            - Entering State: we mark the vertex with color gray(1)
            - Exit State: we mark the vertex with color black(2)
            The graph has a cycle if we are currently on a gray vertex and we are going to another gray vertex.
            Otherwise return true.
        */

        // We also need to build adjacency list
        vector < vector < int > > graph(numCourses);
        for (auto &edge : prerequisites)
            graph[edge[0]].push_back(edge[1]);

        // This vector will indicate the state of the vertex.
        vector < int > color(numCourses , 0);

        // This boolean will be returned later, but it will be true if at least one component is cyclic
        bool isCyclic = false;

        // Run a series of dfs to check every connected component
        for (int i = 0 ; i < numCourses ; ++i)
            isCyclic |= dfs(i , graph , color);

        return !isCyclic;
    }

private:
    bool dfs(int u , vector < vector < int > > &graph , vector < int > &color) {
        // Entering state
        color[u] = 1;

        for (auto v : graph[u]) {
            if (color[v] == 0) {
                // It's okay to continue
                if (dfs(v , graph , color))
                    return true;
            } else if (color[v] == 1) {
                // We are entring a cycle
                return true;
            }
        }

        // we finished without entering a cycle
        color[u] = 2;
        return false;
    }
};

/*
    Considering N = number of vertices and M = number of edges
    Time: O(N + M)
    Space: O(N + M)
*/
