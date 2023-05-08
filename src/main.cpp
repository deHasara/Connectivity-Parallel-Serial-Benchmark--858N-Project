#include <cstdio>

#include "graph.h" 
#include "ldd.h"

int main(int argc, char *argv[]){
    struct Graph * g = init_graph("temp"); 
    print_graph(g);   
    float beta = 0; 
    sscanf(argv[1], "%f", &beta);
    int * labels = LDD_serial(g, g->n, beta);  
    print_labels(labels, g->n); 

    return 0; 
}