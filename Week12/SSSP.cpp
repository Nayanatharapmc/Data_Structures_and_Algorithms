#include <iostream>
#include <stdio.h>
using namespace std;

//This function is to find the minimum time taken to travel between two cities
int minimumTime(int time[], bool check[]) 
{
    int min=INT_MAX,index;  //Initially setting the minimum time value to a large number
              
    for(int i=0; i<6; i++){ //Iterating through the check list 
        if(check[i]==false && time[i]<=min)    //Finding the minimum time tsken to travel to the node  
        {
            min=time[i];
            index=i;
        }
    }
    return index; //Returning the visited vertex
}

/*This method implements the Dijkstra's Algorithm to find SSSP.
The adjacency matrix related to the graph and the source node are taken as arguments*/
void DijkstraAlgorithm(int graph[6][6],int source)  
{
    int time[6];  // This array is to calculate the minimum distance for each node                             
    bool check[6];// This array is to mark whether each node is checked or not
    
    //Initially all the vertices are marked as unvisited and the distance to each node from source is very large
    for(int i = 0; i<6; i++)
    {
        time[i] = INT_MAX;  
        check[i] = false;    
    }
    
    time[source] = 0;   // The time value of the source vertex is set to 0               
    
    for(int i = 0; i<6; i++)                           
    {
        int m=minimumTime(time,check); //Finding the minimum time taken to travel to each city 
        check[m]=true;  //The city is marked as visited
        for(int k = 0; k<6; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!check[k] && graph[m][k] && time[m]!=INT_MAX && time[m]+graph[m][k]<time[k])
                time[k]=time[m]+graph[m][k]; 
        }
    }
    cout <<"Source vertex : " <<source <<endl; //Printing the source vertex
    cout<<"Vertex\t\tDistance from source vertex" <<endl;
    for(int k = 0; k<6; k++)   //Printing the minimum time taken to travel to each city from the source node          
    {  
        cout<<k <<"\t\t\t"<<time[k]<<endl;
    }
}

int main()
{
    //Adjacency matrix corresponding to the given graph
    int graph[6][6]={
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}};

    //Calling the Dijkstra's Algorithm to find the minimum time taking 0 as the source vertex    
    DijkstraAlgorithm(graph,5);
    return 0;                           
}