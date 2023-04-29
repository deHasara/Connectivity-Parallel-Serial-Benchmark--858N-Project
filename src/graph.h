#include <cstdlib>
#include <cstdio>  
#include <string>   

#ifndef GRAPH_H
#define GRAPH_H

/**************************** STRUCTURES AND CONSTANTS ******************************************/ 
struct Graph
{
    int n; 
    int m;  
    struct EdgeNode ** list;

}; 

struct EdgeNode
{
    int node; 
    struct EdgeNode * next; 
}; 

/******************************* Public Functions*********************************************************************/

/*
Parameters: 
    file_path -> path to SNAP file   
    file format: 
    30 (# of nodes) 
    1,5  (edges)
    2,7 
    ...
Definition: 
    construct adjecency reprsentation of graph from the file 
Return: 
*/
struct Graph * init_graph(std::string file_name);  

void print_graph(struct Graph * g);

#endif 