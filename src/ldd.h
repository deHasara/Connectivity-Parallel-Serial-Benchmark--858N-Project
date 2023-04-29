#include "graph.h"

/**************************** STRUCTURES AND CONSTANTS ******************************************/ 
struct BFS_Queue{
   struct BFS_Queue_Ele * head;   
   struct BFS_Queue_Ele * tail; 

};

/* 
An element used for a linked list queue in the breath first search of the serial ldd algorithim 
*/
struct BFS_Queue_Ele
{
    int node; 
    struct BFS_Queue_Ele * next; 
};



/****************************** PUBLIC FUNCTIONS ******************************************************/ 
/* 
Paramters: 
    g -> the graph to preform LDD on (adjecency list)
    n -> number of nodes in the graph (lenght of adjecency list) 
    b -> LDD edge fraction paramter   
Definiton: 
    Preforms low-diameter decomposition on g, such that only b * m
    edges are cut, where m is the total number of edges in g. g isn't maniulated, but
    instead an array denoting the resultign cluster that each node belongs to is returned 
Return: l -> node-to-label array 
*/
int * LDD_serial(struct Graph * g, int n, float b);  

void print_labels(int * l, int n);



/******************************* PRIVATE FUNCTIONS ******************************************************/

//BFS Queue functions  

/* 
Paramters: 
    queue -> the BFS_queue
Definiton: 
    dequeues the head element of queue
Return: node id
*/
int dequeue(struct BFS_Queue * queue); 

/* 
Paramters: 
    queue -> the BFS_queue 
    node -> node id to enqueue
Definiton: 
    adds element to tail of queue
Return:
*/
void enqueue(struct BFS_Queue * queue, int node);
