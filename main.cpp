/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #14  : Dijkstra & MST
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/25/16
 *************************************************************************/

#include "Header.h"

int main() {
    Graph<string> map(12);

    cout << OutputHeading();

    map.addVertex(new Vertex<string>("Denver"));
    map.addVertex(new Vertex<string>("Chicago"));
    map.addVertex(new Vertex<string>("Seattle"));
    map.addVertex(new Vertex<string>("Dallas"));
    map.addVertex(new Vertex<string>("Houston"));
    map.addVertex(new Vertex<string>("Boston"));
    map.addVertex(new Vertex<string>("New York"));
    map.addVertex(new Vertex<string>("Atlanta"));
    map.addVertex(new Vertex<string>("Miami"));
    map.addVertex(new Vertex<string>("San Francisco"));
    map.addVertex(new Vertex<string>("Los Angeles"));
    map.addVertex(new Vertex<string>("Kansas City"));

    map.addEdge(new Edge<string>("Seattle", "San Francisco", 807));
    map.addEdge(new Edge<string>("Seattle", "Denver", 1331));
    map.addEdge(new Edge<string>("Seattle", "Chicago", 2097));

    map.addEdge(new Edge<string>("San Francisco", "Denver", 1267));
    map.addEdge(new Edge<string>("San Francisco", "Los Angeles", 381));

    map.addEdge(new Edge<string>("Los Angeles", "Denver", 1015));
    map.addEdge(new Edge<string>("Los Angeles", "Kansas City", 1663));
    map.addEdge(new Edge<string>("Los Angeles", "Dallas", 1435));

    map.addEdge(new Edge<string>("Denver", "Kansas City", 599));
    map.addEdge(new Edge<string>("Denver", "Chicago", 1003));

    map.addEdge(new Edge<string>("Kansas City", "Chicago", 553));
    map.addEdge(new Edge<string>("Kansas City", "Dallas", 496));
    map.addEdge(new Edge<string>("Kansas City", "Atlanta", 864));
    map.addEdge(new Edge<string>("Kansas City", "New York", 1260));

    map.addEdge(new Edge<string>("Dallas", "Atlanta", 781));
    map.addEdge(new Edge<string>("Dallas", "Houston", 239));

    map.addEdge(new Edge<string>("Chicago", "Boston", 983));
    map.addEdge(new Edge<string>("Chicago", "New York", 787));

    map.addEdge(new Edge<string>("New York", "Boston", 214));
    map.addEdge(new Edge<string>("New York", "Atlanta", 888));

    map.addEdge(new Edge<string>("Atlanta", "Houston", 810));
    map.addEdge(new Edge<string>("Atlanta", "Miami", 661));

    map.addEdge(new Edge<string>("Miami", "Houston", 1187));

    cout << "\n\n+------------------------+\n"
         << "|  Dijkstra's Algorithm  |\n"
         << "+------------------------+\n";
    map.dijkstra(map.findVertexPosition("Atlanta"));
    cout << endl;

    cout << "+-------------------------+\n"
         << "|  Minimum Spanning Tree  |\n"
         << "+-------------------------+\n";
    map.primMST();

}