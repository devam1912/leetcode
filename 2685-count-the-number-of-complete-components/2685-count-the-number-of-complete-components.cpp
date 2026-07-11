class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    void dfs(int node, vector<int>& component)
    {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        adj.resize(n);
        visited.assign(n, false);

        // Build graph
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int completeComponents = 0;

        // Visit every component
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int> component;

                dfs(i, component);

                int size = component.size();

                bool isComplete = true;

                // Every node should connect to all other nodes
                for (int node : component)
                {
                    if (adj[node].size() != size - 1)
                    {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete)
                {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};