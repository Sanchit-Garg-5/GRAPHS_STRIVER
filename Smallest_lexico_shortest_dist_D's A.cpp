//https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
    typedef long long ll;
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        int n = V;
        vector<vector<pair<ll, ll>>> me(n + 1);
        for (auto &e : edges) {
            me[e[0]].push_back({e[1], e[2]});
            me[e[1]].push_back({e[0], e[2]});
        }

        vector<ll> dist(n + 1, LLONG_MAX);
        vector<int> parent(n + 1, -1);

        // Start Dijkstra from dest
        dist[dest] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, dest});

        while (!pq.empty()) {
            ll dis = pq.top().first;
            ll u = pq.top().second;
            pq.pop();
            if(u==src){break;}
            if (dis > dist[u]) continue;

            for (auto &edge : me[u]) {
                ll v = edge.first;
                ll weight = edge.second;

                if (dist[v] > dis + weight) {
                    dist[v] = dis + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                } else if (dist[v] == dis + weight) {
                    if (parent[v] == -1 || u < parent[v]) {
                        parent[v] = u;
                    }
                }
            }
        }

        if (dist[src] == LLONG_MAX) return {-1};

        // Trace forward directly from src to dest (no reverse needed)
        vector<int> path;
        for (int curr = src; curr != -1; curr = parent[curr]) {
            path.push_back(curr);
        }

        return path;
    }
};
