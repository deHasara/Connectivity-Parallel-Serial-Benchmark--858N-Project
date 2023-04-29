#include <cstdlib>
#include <cstdio>     
#include <string>  
#include <cstring>
#include <fstream>

#include "graph.h"

/****************************** PUBLIC FUNCTIONS ******************************************************/ 
struct Graph * init_graph(std::string file_name){  
    //allocate graph
    struct Graph * g = (struct Graph *) malloc(sizeof(struct Graph));
    memset(g, 0, sizeof(struct Graph)); 

    //open file and initalize graph
    std::fstream file; 
    file.open("../data/preped/" + file_name); 
    if(file.is_open()){
        std::string line; 
        getline(file, line); //get # of nodes (first line) 
        g->n = std::stoi(line);   

        g->list = (struct EdgeNode **) malloc(sizeof(struct EdgeNode) * g->n); 
        //add edges 
        while(getline(file, line)){  
            g->m++; 
            int n1; 
            int n2; 
            const char * c_line = line.c_str();   
            sscanf(c_line, "%d,%d ", &n1, &n2 );  
            struct EdgeNode * edgeNode = (struct EdgeNode *) malloc(sizeof(struct EdgeNode)); 
            edgeNode->node = n2; 
            edgeNode->next = NULL;  
            if(g->list[n1] == NULL){
                g->list[n1] = edgeNode; 
            }else{
                struct EdgeNode * ptr = g->list[n1]; 
                g->list[n1] = edgeNode; 
                edgeNode->next = ptr; 
            }
        }
    } 

    return g; 
}    

void print_graph(struct Graph * g){
    printf("**********************\n");
    printf("num of nodes: %d\n", g->n);  
    printf("num of edges: %d\n", g->m);  
    int i = 0; 
    for(; i < g->n; i++){
        printf("%d: ", i); 
        struct EdgeNode * ptr = g->list[i]; 
        while(ptr != NULL){
            printf("%d->", ptr->node);  
            ptr = ptr->next; 
        } 
        printf("\n"); 
    } 
    printf("**********************\n");
}