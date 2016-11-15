#include <iostream>
#include <cstdlib>

using namespace std;

//Class of the matrix graph
class matrixGraph {
public:
    // Taking in the input of n and e in order to create the matrix
    matrixGraph(int n, int e) {
        this->n=n; // Makes sure to update the number of vertices
        this->e=e; // Makes sure to update the number of edges
        // Initializes the graph and makes it empty
         for ( int i = 0; i < n; i++ ) {
             for ( int j = 0; j < n; j++ ) {
                 adjMatrix[i][j] = 0;
             }
         }
    }
    
    // Adding an edge to the undirected Matrix Graph
    void addedge(int c, int x, int w) {
        // Makes sure that the weight is the same if the values are flipped
        adjMatrix[c][x] = adjMatrix[x][c] = w;
    }
    
    // Printing the Matrix Graph
    void PrintMG() {
        cout << "\n |_"; // Separates the vertex value from the weight
        for ( int k = 0; k < n; k++)
            cout << k << "_" ; // Added it to make it look cleaner between the row vertex value
        
        cout << "\n";
        for( int i = 0; i < n; ++i ) {
            cout << i;
            cout << "| "; // Up to here (makes it look cleaner)
            for( int j = 0; j < n; ++j ) {
                // This is the actual adjacency matrix being printed out
                if ( i == j )
                    cout << "X ";
                
                else
                    cout << adjMatrix[i][j] << " ";
                    //cout << adjMatrix[c][x] << " ";
            }
            cout << "\n";
        }
    }
private:
    int adjMatrix[100][100];
    int n, e; // The number of vertices and number of edges
    int c, x, w; // Current Vertex, Next Vertex, Edge Weight
    
    
};