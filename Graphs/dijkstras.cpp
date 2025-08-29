#include <bits/stdc++.h>
using namespace std;

// Represents an edge from the current node to `destination` with a given `weight`
struct edge {
    string destination;
    int weight;

    // This makes priority_queue behave as a *min-heap* based on weight
    // (because by default C++ priority_queue is a max-heap)
    bool operator<(const edge& other) const {
        return weight > other.weight; // smallest weight has highest priority
    }
};

// Dijkstra's algorithm to find shortest distance from `startingNode` to all others
void dijkstras(const unordered_map<string, vector<edge>>& graph, const string& startingNode) {
    // Check if starting node exists in the graph
    if (!graph.count(startingNode)) {
        cout << "Starting node not found!\n";
        return;
    }

    unordered_map<string, int> distn;      // Stores shortest distance to each node
    unordered_map<string, bool> visited;   // Tracks whether a node has been processed
    unordered_set<string> nodes;           // Keeps a set of all nodes in the graph

    // Collect all nodes (both from keys and from adjacency lists)
    for (auto& item : graph) {
        nodes.insert(item.first); // Add source node
        for (auto& adj : item.second) {
            nodes.insert(adj.destination); // Add destination node
        }
    }

    // Initialize distances: ∞ (INT_MAX) for all except the starting node
    for (auto& node : nodes) {
        distn[node] = INT_MAX; // Initially, assume all nodes unreachable
        visited[node] = false; // No node visited yet
    }
    distn[startingNode] = 0; // Distance to starting node is 0

    // Min-heap priority queue storing (node, distance) pairs
    priority_queue<edge> pq;
    pq.push({startingNode, 0}); // Start from the source node

    // Main Dijkstra loop
    while (!pq.empty()) {
        // Get the node with the smallest distance from the queue
        edge current = pq.top();
        pq.pop();
        string currentNode = current.destination;

        // Skip if already processed
        if (visited[currentNode]) continue;
        visited[currentNode] = true; // Mark as processed

        // Check all neighbors of the current node
        for (auto& adj : graph.at(currentNode)) {
            // Calculate new possible distance to neighbor
            int newDist = distn[currentNode] + adj.weight;

            // Relaxation step: If this new path is shorter, update
            if (newDist < distn[adj.destination]) {
                distn[adj.destination] = newDist; // Update shortest distance
                pq.push({adj.destination, newDist}); // Push new distance into heap
            }
        }
    }

    // Output shortest distances
    for (auto& item : distn) {
        cout << item.first << " "
             << (item.second == INT_MAX ? -1 : item.second) // -1 means unreachable
             << endl;
    }
}

int main() {
    // Graph represented as adjacency list
    unordered_map<string, vector<edge>> graph;
    graph["A"].push_back({"B", 4});
    graph["A"].push_back({"C", 2});
    graph["B"].push_back({"C", 3});
    graph["B"].push_back({"E", 3});
    graph["B"].push_back({"D", 2});
    graph["C"].push_back({"B", 1});
    graph["C"].push_back({"D", 4});
    graph["C"].push_back({"E", 5});
    graph["E"].push_back({"D", 1});

    // Run Dijkstra starting from "A"
    dijkstras(graph, "A");
}
