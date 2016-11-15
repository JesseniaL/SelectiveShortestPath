#include <iostream>
#include <cstdlib>
using namespace std;

//Adjacency List Node
struct ListNode {
    int dest;
    struct ListNode* next;
};

//Adjacency List
struct List {
    struct ListNode* head;
};

//Graph (array) class of adjacency list
class listGraph {
public:
    //Taking in the input of n and creates an array
    listGraph( int n ) {
        this->n=n; //makes sure to update the number of vertices
        array = new List [n]; //the graph is created
        //Initializes the list as empty by making the head (beginning of list) equal to nullptr
        for (int i = 0; i < n; i++)
            array[i].head = NULL;
    }
    
    // Creating a new adjacency List Node
    ListNode* newListNode( int dest ) {
        ListNode* newNode = new ListNode; //new list node
        newNode->dest = dest; //the new list node points to the dest
        newNode->next = NULL; //it points to next which is assigned to NULL
        return newNode; //returns our new list node so it can be stored
    }
    
    // Adding Edge to an undirected graph
    void addEdge( int begg, int dest ) {
        //New node is added to the beggining of the adjacency list begg
        ListNode* newNode = newListNode(dest);
        newNode->next = array[begg].head;
        array[begg].head = newNode;
        //An edge from dest to begg must be added since it's an undirected graph
        newNode = newListNode(begg);
        newNode->next = array[dest].head;
        array[dest].head = newNode;
    }
    
    //Printing the Adjacency List
    void PrintLG() {
        int j = 0; // we assign the int to 0 since right now for me it's easier to work with number's than char
        while ( j >= 0 && j < n ) { //make sure my list doesn't surpass the number of vertices
            ListNode* adj = array[j].head; //made a new node called adjacency (adj for short)
            cout << "\n Adjacency list of vertex " << j << ":\n";
            while( adj ) { //check the edges
                cout << " -> " << adj-> dest;
                adj = adj-> next;
            }
            j++; //move on to the next vertex
            cout << "\n";
            
        }
    }
    
private:
    int n; //number of vertices
    struct List* array; //the array
};