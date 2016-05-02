/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #14  : Dijkstra & MST
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/25/16
 *************************************************************************/

#ifndef ASSIGN_14_DIJKSTRA_MST_GRAPH_H
#define ASSIGN_14_DIJKSTRA_MST_GRAPH_H

#include "Vertex.h"
#include "Edge.h"

#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <stdio.h>
#include <limits.h>

using namespace std;

enum costType {
    /** Infinity represents that there
     * is no connection between two vertices */
            INFINITY = numeric_limits<int>::max()
};

/**
 * Graph
 * This class implements a graph that has
 * the following attributes:
 *   vector of vertices,
 *   two-dimensional vector of edges,
 *   and the number of vertices
 *   in the vector to keep track
 *   of how many vertices there
 *   are.
 *
 *   The class also implements
 *   the Dijkstra's algorithm and
 *   the minimum spanning tree
 *   algorithm.
 */
template <typename T>
class Graph {
public:
    Graph(int setSize);
    ~Graph();

    void addEdge(Edge<T> *newEdge);
    void addVertex(Vertex<T> *newVertex);
    int getSize() const;
    string displayVertices() const;
    string displayEdges() const;
    int findVertexPosition(T search);

    void dijkstra(int start);
    void primMST();

private:
    int minDistance(int costs[]);
    int minKey(int key[]);
    void printDijkstra(int costs[], int source);
    void printMST(int parent[]);


    vector<Vertex<T> > vertices;
    vector< vector<Edge<T> > > adjacencyMatrix;
    int numberOfVertices;
};

/*****************************************************************
 * Graph(int setSize)
 *    CONSTRUCTOR
 * Assigns the graph and list of vertices to be a fixed size.
 * Ex: If the integer is 5, the graph will only allow
 * 5 vertices and a 5 by 5 graph.
 ****************************************************************/
template <typename T>
Graph<T>::Graph(int setSize) {

    vertices.reserve(setSize);

    adjacencyMatrix.reserve(setSize);
    for(int i = 0; i < setSize; i++) {
        adjacencyMatrix[i].reserve(setSize);
    }
}

/*****************************************************************
 * ~Graph()
 *    DESTRUCTOR
 * Clears the graph and list of vertices. Sets the number of
 * vertices back to 0.
 ****************************************************************/
template <typename T>
Graph<T>::~Graph() {
    numberOfVertices = 0;
    vertices.clear();

    adjacencyMatrix.clear();
}

/*****************************************************************
 * addEdge(Edge<T> *newEdge)
 *    MUTATOR
 * Adds an edge to the adjancency matrix.
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Graph<T>::addEdge(Edge<T> *newEdge) {
    int startPos = (findVertexPosition(newEdge->getStart()));
    int endPos   = (findVertexPosition(newEdge->getEnd()));
    int weight = newEdge->getWeight();

    adjacencyMatrix[startPos][endPos] = *new Edge<T>(newEdge->getStart(),
                                                  newEdge->getEnd(), weight);
    adjacencyMatrix[endPos][startPos] = *new Edge<T>(newEdge->getEnd(),
                                                  newEdge->getStart(), weight);

}

/*****************************************************************
 * addVertex(Vertex<T> *newVertex)
 *    MUTATOR
 * Adds an vertex to the vector of vertices.
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Graph<T>::addVertex(Vertex<T> *newVertex) {
    newVertex->setPosition(numberOfVertices);
    vertices.push_back(*newVertex);

    /** Increments the number of vertices
     * stored in the vector vertices */
    numberOfVertices++;
}

/*****************************************************************
 * findVertexPosition(T search)
 *    ACCESSOR
 * Finds the position of where a specified vertex is located.
 * RETURNS -> If found returns index, else returns -1.
 ****************************************************************/
template <typename T>
int Graph<T>::findVertexPosition(T search) {
    int foundPosition = -1;
    bool found = false;
    int index = 0;

    while(!found && index < numberOfVertices) {

        if(search == vertices[index].getElement()) {
            foundPosition = index;
            found = true;
        }
        else {
            index++;
        }
    }

    /** It will either return -1 if not
     * found/or the position to the foundVertex */
    return index;
}


/*****************************************************************
 * displayVertices() const
 *    ACCESSOR
 * Outputs the list of vertices.
 * RETURNS -> string of vertices.
 ****************************************************************/
template <typename T>
string Graph<T>::displayVertices() const {
    ostringstream output;

    for(int i =0; i < numberOfVertices; i++) {
        output << vertices[i].getElement() << " "
               << vertices[i].getPosition() << "\n";
    }

    output << endl;

    return output.str();
}

/*****************************************************************
 * displayEdges() const
 *    ACCESSOR
 * Outputs the list of adjacent edges.
 * RETURNS -> string of edges in the matrix.
 ****************************************************************/
template <typename T>
string Graph<T>::displayEdges() const {
    ostringstream output;

    for(int i =0; i < numberOfVertices; i++) {
        for(int j = 0; j < numberOfVertices; j++) {
            output << left << setw(8)
            << adjacencyMatrix[i][j].getWeight() << right;
        }

        output << endl;
    }

    output << endl;

    return output.str();
}

/*****************************************************************
 * dijkstra(int start)
 *    ACCESSOR
 * Calculates the dijkstra algorithm, which is finding the
 * shortest path from point A to point B. This method calculates
 * all the shortest paths in the matrix.
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Graph<T>::dijkstra(int start) {
    int costs[numberOfVertices];     // The output array.  dist[i] will hold the shortest
    vector<Edge<T>> edgesTaken;
    vector< vector<Edge<T>>> visitedPaths;
    visitedPaths.reserve(12);

    edgesTaken.push_back(*new Edge<T>(vertices[start].getElement(),
                                      vertices[start].getElement(), 0));

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < numberOfVertices; i++) {
        costs[i] = INFINITY, vertices[i].setIsVisited(false);
        visitedPaths[i].reserve(12);
    }


    // Distance of source vertex from itself is always 0
    costs[start] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < numberOfVertices-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(costs);

        // Mark the picked vertex as processed
        vertices[u].setIsVisited(true);

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < numberOfVertices; v++) {

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!(vertices[v].getIsVisit())
                && adjacencyMatrix[u][v].getWeight() != 0 && costs[u] != INFINITY
                && costs[u] + adjacencyMatrix[u][v].getWeight() < costs[v]) {


                if(!visitedPaths[v].empty() && visitedPaths[v].at(visitedPaths[v].size() - 1).getEnd() == vertices[v].getElement()) {
                    visitedPaths[v].pop_back();
                }

                visitedPaths[v].push_back(adjacencyMatrix[u][v]);

                costs[v] = costs[u] + adjacencyMatrix[u][v].getWeight();
            }
        }
    }

    printDijkstra(costs, start);

    cout << "\n+-------------+\n"
         << "| PATHS TAKEN |\n"
         << "+-------------+\n";
    for(int i = 11; i > -1; i--) {
        for(int j = 11; j > -1; j--) {
            if(visitedPaths[i][j].getStart() != "") {
                cout << visitedPaths[i][j].getStart() << " ---> "
                << visitedPaths[i][j].getEnd() << "\t--  " << visitedPaths[i][j].getWeight() << endl;
            }
        }
    }

}

/*****************************************************************
 * printDijkstra(int costs[], int source)
 *    ACCESSOR
 * Prints out all the costs for the vertex and the distance
 * from the starting point/source.
 * RETURNS -> void
 ****************************************************************/
template<typename T>
void Graph<T>::printDijkstra(int costs[], int source)
{
    cout << left;
    cout << setw(15) << "VERTEX" << "DISTANCE FROM "
                        + vertices[source].getElement() + "\n";
    for (int i = 0; i < numberOfVertices; i++) {
        cout << setw(24) << vertices[i].getElement()  << costs[i] << endl;
    }
    cout << right;
}

/*****************************************************************
 * minDistance(int costs[])
 *    ACCESSOR
 * Finds the minimum edge within the matrix.
 * RETURNS -> position of the minimum edge.
 ****************************************************************/
template<typename T>
int Graph<T>::minDistance(int costs[])
{
    // Initialize min value
    int min = INFINITY, min_index;

    for (int v = 0; v < numberOfVertices; v++)
        if (!vertices[v].getIsVisit() && costs[v] <= min)
            min = costs[v], min_index = v;

    return min_index;
}

/*****************************************************************
 * minKey(int key[])
 *    ACCESSOR
 * Finds the minimum key in the matrix.
 * RETURNS -> position of the minimum key
 ****************************************************************/
template <typename T>
int Graph<T>::minKey(int key[])
{
    // Initialize min value
    int min = INFINITY, min_index;

    for (int v = 0; v < numberOfVertices; v++)
        if (!vertices[v].getIsVisit() && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

/*****************************************************************
 * printMST(int parent[])
 *    ACCESSOR
 * Prints out all the corresponding edges with the weight in the
 * minimum spanning tree.
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Graph<T>::printMST(int parent[])
{
    double totalWeight = 0;
    cout << left << setw(35) << "EDGES" << "WEIGHT\n";
    for (int i = 1; i < numberOfVertices; i++) {
        string edges =  vertices[parent[i]].getElement() + " - " + vertices[i].getElement();
        cout  << setw(36) << edges  << adjacencyMatrix[i][parent[i]].getWeight() << endl;
        totalWeight += adjacencyMatrix[i][parent[i]].getWeight();
    }
    cout << right;

    cout << "\nTOTAL MILEAGE: " << totalWeight << endl;

}

/*****************************************************************
 * primMST()
 *    ACCESSOR
 * Determines the minimum spanning tree.
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Graph<T>::primMST()
{
    int parent[numberOfVertices];
    int key[numberOfVertices];

    /** Initialize all keys as INFINITY and sets all places as not
        included in the MST yet */
    for (int i = 0; i < numberOfVertices; i++)
        key[i] = INFINITY, vertices[i].setIsVisited(false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numberOfVertices-1; count++)
    {
        /** Pick the minimum key vertex from the set of vertices
         not yet included in MST */
        int u = minKey(key);

        /* Adds vertices to MST */
        vertices[u].setIsVisited(true);

        /** Updates the value if needed */
        for (int v = 0; v < numberOfVertices; v++)

            /** If adjacencyMatrix[u][v] is none zero, and the vertex
             * has not been visited/included in the MST, therefore
             * update the key only if adjacencyMatrix[u][v] weight
             * is smaller than the currnet key */
            if (adjacencyMatrix[u][v].getWeight() != 0
                && !vertices[v].getIsVisit()
                && adjacencyMatrix[u][v].getWeight() <  key[v]) {

                parent[v] = u, key[v] = adjacencyMatrix[u][v].getWeight();
            }
    }

    /** Outputs the MST */
    printMST(parent);
}



#endif //ASSIGN_14_DIJKSTRA_MST_GRAPH_H
