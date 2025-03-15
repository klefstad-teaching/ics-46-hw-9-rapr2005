#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) 
{
    int n = G.numVertices;
    vector<int> distance(n, INF);
    vector<bool> visited(n, false);
    previous.assign(n, -1);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& e : G[u]) 
        {
            int v = e.dst, weight = e.weight;

            if (!visited[v] && distance[u] + weight < distance[v]) 
            {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) 
{
    vector<int> path;
    if (distances[destination] == INF) return path;

    for (int v = destination; v != -1; v = previous[v]) 
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& path, int total_cost) 
{
    for (size_t i = 0; i < path.size(); ++i) 
    {
        cout << path[i] << " ";
    }
    cout << "\nTotal cost is " << total_cost << endl;
}

