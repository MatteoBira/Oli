#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // (distance, node)

int dijkstra(const vector<vector<pii>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (u == end) {
            return d; // Return the distance when the end node is reached
        }

        if (d > dist[u]) continue; // Skip if we have already found a better path

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return -1; // If the end node is unreachable
}

void solve(int t) {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> Z(A), X(B), Y(B);

    for (int i = 0; i < A; i++) {
        cin >> Z[i];
    }

    for (int i = 0; i < B; i++) {
        cin >> X[i] >> Y[i];
    }

    // Build the graph
    vector<vector<pii>> graph(N + 1); // Add a virtual node N
    for (int i = 0; i < B; i++) {
        graph[X[i]].push_back({Y[i], 1});
        graph[Y[i]].push_back({X[i], 1});
    }

    // Connect the virtual node N to all nodes in Z with weight 0
    for (int i = 0; i < A; i++) {
        graph[N].push_back({Z[i], 0});
    }

    // Run Dijkstra from the virtual node N to find the closest node in Z
    int num = INT_MAX;
    int idx = -1;
    for (int j = 0; j < N; j++) {
        int cur = dijkstra(graph, N, j);
        if (cur != -1 && cur < num) {
            num = cur;
            idx = j;
        }
    }

    cout << "Case #" << t << ": " << idx << " " << num << "\n";
}
int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("interruttori_input_2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
