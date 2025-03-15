#include "dijkstras.h"

int main() {
    string filename = "small.txt"; 

    Graph G;
    ifstream in(filename);
    if (!in) {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1;
    }
    in >> G;
    in.close();

    int source = 0;
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    for (int destination = 0; destination < G.numVertices; ++destination) {
        if (destination == source) {
            cout << destination << "\nTotal cost is 0\n";
            continue;
        }
        
        vector<int> path = extract_shortest_path(distances, previous, destination);
        if (!path.empty()) {
            print_path(path, distances[destination]);
        }
    }

    return 0;
}
