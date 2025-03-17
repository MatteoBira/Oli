#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <utility>

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

    return -1; 
}

vector<vector<pii>> possibleBridges(const vector<vector<pii>>& graph, int N, int M){
    vector<vector<pii>> res;

}

void printGraph(const vector<vector<pii>> &graph) {
    int nodeIndex = 0;
    for (const auto &node : graph) {
        cout << "Node " << nodeIndex << " -> ";
        for (const auto &edge : node) { // Correctly iterate over pairs inside the adjacency list
            cout << "(" << edge.first << ", weight: " << edge.second << ") ";
        }
        cout << endl;
        nodeIndex++;
    }
}

int main() {

    ifstream cin("input0.txt");
    ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;
    long long minDis;

    vector<int> U(M), V(M);
    for (int i = 0; i < M; ++i)
        cin >> U[i] >> V[i];
    vector<vector<pii>> graph(M);
    for(int i=0;i<M;i++){
        graph[U[i]].push_back({V[i],1});
        graph[V[i]].push_back({U[i],1});
    }

    printGraph(graph);

    minDis = (long long) dijkstra(graph,0,N-1);

    long long C = 0;


    // INSERT YOUR CODE HERE


    cout << C << endl;

    return 0;
}
