#include <climits>
#include <iostream>
using namespace std;

#define V 6 //Set the no. of vertices in the graph as a constant

//This function returns the edge names in a user-friendly manner
string getEdgeName(int edge,int v){
    string edgeName = "Edge "+to_string(edge)+"->"+to_string(v);
    return edgeName;
}

//This function chooses the edge with the minimum weight for the MST
int minKey(int key[],bool mst[]){
    int min = INT_MAX,min_index; //minimum weight is initially set to infinity

    for(int i=0;i<V;i++){
        if(mst[i]==false && key[i]<min){
            min = key[i];  //Updating minimum weight and the corresponding minimum edge 
            min_index = i;
        }
    }
    return min_index;  
}
//This function prints the MST
void printMST(int source[], int G[V][V]){
    cout <<"Edge \t Weight \t" <<endl;
    for (int i=1;i<V;i++){
        string edgeName = getEdgeName(source[i],i);
        cout <<edgeName <<":" <<"\t" <<G[i][source[i]] <<endl; //Printing edges and corresponding weights
    }
}
//Prim's algorithm to find the MST
void prim(int G[V][V]){
    
    int source[V],key[V];  //key array stores the minimum weight of edges
    bool mst[V];           //mst array track vertices included in MST
    
    for(int i=0; i<V; i++){
        key[i]=INT_MAX;   //Initialize all key values to infinity 
        mst[i]=false;     //No vertices included in MST initially
    }
    key[0]=0;      //starting vertex
    source[0]=-1;  //no source for the starting vertex

    for(int count=0;count<V-1;count++){
        int edge = minKey(key,mst); //choosung the edge with the minimum weight
        mst[edge]=true;     //Include the edge in MST
        for(int v=0;v<V;v++){
            //Update key values and source index of adjacency matrix
            if(G[edge][v]&& mst[v]==false && G[edge][v]<key[v]){
                source[v]=edge;
                key[v]=G[edge][v];
            }
        }
    }
    
    //printing the MST
}

int main() {
    //Adajacency matrix representation of the graph
    int G[V][V] = {{0, 3, 0, 0, 0, 1},
                   {3, 0, 2, 1, 10, 0},
                   {0, 2, 0, 3, 0, 5},
                   {0, 1, 3, 0, 5, 0},
                   {0, 10, 0, 5, 0, 4},
                   {1, 0, 5, 0, 10, 0}};
    
    prim(G);  //Find the MST using Prim's algorithm

    return 0;
}