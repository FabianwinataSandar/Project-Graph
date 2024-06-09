#include <iostream>
#include "header.h"

using namespace std;

int main() {
    int V, E, src, dest, cek_src, cek_dest;

    cout << "Silahkan input vertex: ";
    cin >> V;

    Graph* graph = createGraph(V);

    cout << "Silahkan input edge: ";
    cin >> E;

    for (int i = 0; i < E; ++i) {
        cout << "Input edge " << i + 1 << " (asal dan tujuan): ";
        cin >> src >> dest;
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    cout << "Input 2 vertex untuk memeriksa apakah ada edge di antaranya (asal dan tujuan): ";
    cin >> cek_src >> cek_dest;

    if (hasEdge(graph, cek_src, cek_dest)) {
        cout << "Edge ditemukan antara vertex " << cek_src << " dan " << cek_dest << endl;
    } else {
        cout << "Edge tidak ditemukan antara vertex " << cek_src << " dan " << cek_dest << endl;
    }

    return 0;
}
