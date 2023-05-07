#include <cstdio>

#include "graph.h" 
#include "ldd.h"

int main(void){
    struct Graph * g = init_graph("temp"); 
    print_graph(g);  
    int * labels = LDD_serial(g, g->n, 0.2f);  
    print_labels(labels, g->n); 

    return 0; 
}