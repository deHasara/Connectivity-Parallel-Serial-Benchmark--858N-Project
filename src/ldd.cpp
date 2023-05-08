#include <cstdlib>
#include <cstdio>  
#include <cstring>
#include <cmath>
#include "ldd.h" 

/****************************** PUBLIC FUNCTIONS ******************************************************/ 
int * LDD_serial(struct Graph * g, int n, float b){   
    //initalize labels
    int * labels = (int *) malloc(sizeof(int) * n);  
    bool visited[n]; 

    for(int i = 0; i < n; i++){
        labels[i]  = -1;  
        visited[i] = false; 
    }   

    //for each node, grow ball if unlabeled  
    int cluster = 0; 
    int node = 0; 
    for(; node < n; node++){
        if(labels[node] != -1){
            continue; //current node is in a ball, start ball with another node
        } 

        
        struct EdgeNode * ptr = g->list[node];  
        
        float cut_edges = 0; 
        float internal_edges = 0; 
        struct BFS_Queue * queue = (struct BFS_Queue *) malloc(sizeof(struct BFS_Queue)); 
        memset(queue, 0, sizeof(struct BFS_Queue));   
        int cut_array[n]; 
        memset(cut_array, 0, n * sizeof(int)); 

        enqueue(queue, node);   
        visited[node] = true; 
        while(queue->head != NULL && cut_edges >= b * internal_edges ){ //bfs
            int curr_node = dequeue(queue); 
            labels[curr_node] = cluster;   
            //redistrubute edges already seen
            internal_edges += cut_array[curr_node]; 
            cut_edges -= cut_array[curr_node]; 
            

            ptr = g->list[curr_node]; 
            while(ptr != NULL){ 
                if(!visited[ptr->node]){ //if not clusterd yet 
                    enqueue(queue, ptr->node);  
                    visited[ptr->node] = true;
                } 
                if(labels[ptr->node] != cluster){
                    cut_edges +=1; // add cut edges added by curr_node 
                    cut_array[ptr->node]++; 
                }else{ 
                    internal_edges += 1; 
                }
                ptr = ptr->next; 
            }
        } 
        //free queue
        while(queue->head != NULL){
            dequeue(queue);
        } 
        free(queue);

        memset(cut_array, 0, n * sizeof(int)); 
        cluster++; 
    } 

    return labels; 
}


/******************************* PRIVATE FUNCTIONS ******************************************************/
void enqueue(struct BFS_Queue * queue, int node){
    struct BFS_Queue_Ele * ele = (struct BFS_Queue_Ele *) malloc(sizeof(struct BFS_Queue_Ele));  
    ele->node = node; 
    ele->next = NULL;

    if(queue->head == NULL){ //empty queue
       queue->head = ele; 
       queue->tail = ele;  
       return; 
    } 

    //append to end
    struct BFS_Queue_Ele * ptr = queue->tail; 
    queue->tail = ele; 
    ptr->next = ele; 
} 

int dequeue(struct BFS_Queue * queue){
    if(queue->head == NULL){ //empty queue
        return -1; 
    } 

    
    int node = queue->head->node; 
    struct BFS_Queue_Ele * ptr = queue->head->next; 
    free(queue->head);  
    queue->head = ptr;  
    if(queue->head == NULL){ //previoulsy size 1 queue
        queue->tail = NULL; 
    }  

    return node; 
} 

void print_labels(int * l, int n){
    printf("Labels:\n"); 
    for(int i = 0; i < n; i++){
        if(i != 0 && i % 20 == 0){
            printf("\n");
        } 
        printf("%d in %d, ", i, l[i]); 
    }
}