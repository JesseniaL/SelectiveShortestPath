//  main.cpp
//  Homework#4
//  Prim's Algorithm
//  Copyright © 2016 Jessenia Lopez. All rights reserved.

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include "AdjacencyList.cpp"
#include "AdjacencyMatrix.cpp"

using namespace std;
using namespace std::chrono;

struct Node {
    int vertex;
    int Pv; // Is infinity weight until updated to be the smallest value
    int Dv; // The vertex destination
    bool known; // When vertex is updated, it becomes true
};

class PrimAlgo {
public:
    PrimAlgo(int n, int e) {
        this->n=n; // Vertices
        this->e=e; // Edges
        // Creating the Graph
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ )
                primMatrix[i][j] = 0;
        }
    }
    
    // Find the vertex with minimum key value from unincluded set of vertices
    int min(int key[], bool known[]) {
        int Pv = infi; // Weight
        int Dv = 0; // Destination
            
            for (int i = 0; i < n; i++)
                if (known[i] == false && key[i] < Pv) {
                    Pv = key[i];
                    Dv = i;
                }
            return Dv; // Returns the destination
    }
    
    
    void MST(int c, int x, int w)
    {
        int parent[n]; // Array to store constructed MST
        int key[n]; // Key values used to pick minimum weight edge in cut
        bool known[n]; // To represent set of vertices not yet included in MST
        
        // Initialize all keys as INFINITE
        for (int i = 0; i < n; i++) {
            key[i] = infi;
            known[i] = false;
        }
        
        // First 1st vertex in MST.
        key[0] = 0; // Initializing key
        parent[0] = 0; // Root node
        
        // The MST will have n vertices
        for (int count = 0; count < n - 1; count++)
        {
            // Picking the minimum key vertex from the set of vertices
            int j = min(key, known);
            
            // Add the picked vertex to the MST Set
            known[j] = true;
            
            // Key value (smallest) and parent index is updated
            // Consider only those vertices which are not yet
            for (int i = 0; i < n; i++)
                if (primMatrix[j][i] && known[i] == false && primMatrix[j][i] < key[i]) {
                    parent[i] = j;
                    key[i] = primMatrix[j][i] = w;
                    //ADDED
                    known[parent[i]] = true;
                }
        }
        
        // Print the constructed MST
        PrintMST(parent);
    }
    
    // Printing the MST
    void PrintMST(int parent[]) {
        //cout << "Edge    Weight\n";
        //for ( int i = 0; i < n; i++ ) {
          //  cout << parent[i] << " - " << i << " " << primMatrix[i][parent[i]];
        //}
        for ( int i = 0; i < n; i++ ) {
            listGraph lg(n);
            lg.addEdge(parent[i], i);
        
            matrixGraph mg(n, e);
            //(Edge,Edge, Weight)
            mg.addedge(parent[i], i, primMatrix[i][parent[i]]);
        }
    }
    
private:
    int primMatrix[100][100];
    int n, e; //the number of vertices and number of edges
    int c, x, w; // current vertex, next vertex, edge weight
    int infi = 888;
};

int main() {
    
    steady_clock::time_point t0 = steady_clock::now();
    cout << "\nPractice Example Adjacency List:" << endl;
    listGraph a(8);
    //(Edge,Edge)
    a.addEdge(1, 2);
    a.addEdge(1, 3);
    a.addEdge(1, 4);
    a.addEdge(2, 4);
    a.addEdge(2, 5);
    a.addEdge(3, 4);
    a.addEdge(3, 6);
    a.addEdge(4, 5);
    a.addEdge(4, 6);
    a.addEdge(4, 7);
    a.addEdge(5, 7);
    a.addEdge(6, 7);
    a.PrintLG(); // print the adjacency list representation of the above graph
    steady_clock::time_point t1 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t1 - t0);
    cout << "Running time: " << time_span.count() << " seconds." << endl;
    
    steady_clock::time_point t2 = steady_clock::now();
    cout << "\nPractice Example Matrix Algo:" << endl;
    matrixGraph b(8, 12);
    //(Edge,Edge, Weight)
    b.addedge(1, 2, 3);
    b.addedge(1, 3, 9);
    b.addedge(1, 4, 2);
    b.addedge(2, 4, 1);
    b.addedge(2, 5, 2);
    b.addedge(3, 4, 6);
    b.addedge(3, 6, 5);
    b.addedge(4, 5, 4);
    b.addedge(4, 6, 6);
    b.addedge(4, 7, 8);
    b.addedge(5, 7, 7);
    b.addedge(6, 7, 3);
    b.PrintMG();
    steady_clock::time_point t3 = steady_clock::now();
    duration<double> time_span2 = duration_cast<duration<double>>(t3 - t2);
    cout << "Running time: " << time_span2.count() << " seconds." << endl;
    
    
     steady_clock::time_point t4 = steady_clock::now();
     cout << "\nPractice Example of Prim's Algo:" << endl;
     PrimAlgo p(8, 12);
     //(Edge,Edge, Weight)
     p.MST(1, 2, 3);
     p.MST(1, 3, 9);
     p.MST(1, 4, 2);
     p.MST(2, 4, 1);
     p.MST(2, 5, 2);
     p.MST(3, 4, 6);
     p.MST(3, 6, 5);
     p.MST(4, 5, 4);
     p.MST(4, 6, 6);
     p.MST(4, 7, 8);
     p.MST(5, 7, 7);
     p.MST(6, 7, 3);
     steady_clock::time_point t5 = steady_clock::now();
     duration<double> time_span3 = duration_cast<duration<double>>(t5 - t4);
     cout << "Running time: " << time_span3.count() << " seconds." << endl;
    
    
    cout << "Random Graph Implementation (of size 5)" << endl;
    int size = 5;
    listGraph r(size);
    matrixGraph rm(size, 7);
    
    int random1[size];
    int random2[size];
    int random3[size];
    srand((unsigned)time(NULL));
    for ( int i = 0; i < size; i++ )
        random1[i] = rand() % 1000+1;
    
    for ( int j = 0; j < size; j++ )
        random2[j] = rand() % 1000+1;
    
    for (int k = 0; k < size; k++ )
        random3[k] = rand() % 10+1;
    
    for ( int j = 0; j < size; j++ ) {
        r.addEdge( random1[j], random2[j] );
        rm.addedge( random1[j], random2[j], random3[j] );
    }
    
    r.PrintLG();
    rm.PrintMG();
    
    return 0;
}
