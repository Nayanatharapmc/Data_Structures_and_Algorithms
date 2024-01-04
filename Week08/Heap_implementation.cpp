#include <iostream>
#include <cmath>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int left=2*root+1;  
  int right=2*root+2; 
  int max=root;  //set the root as the largest value

  if(left<n && arr[left]>arr[max]){  //checking if the left child is greater than the root
   max=left; 
  }

  if(right<n && arr[right]>arr[max]){  //checking if the right child is greater than the root
   max=right;
  }

  if(max!=root){   //Take the maximum value to the root
   swap(arr[root],arr[max]);
   heapify(arr,n,max);  //recursively heapify the subtrees
  } 
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i=n/2-1;i>=0;i--){
      heapify(arr,n,i); 
   }

   //extracting elements from heap one by one
   for(int i=n-1;i>=0;i--){   
      swap(arr[0],arr[i]);
      heapify(arr,i,0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   cout << "Enter the size of the array: ";  //Taking the size of the array as a user input  
   int n;
   cin >>n;

   int heap_arr[n]; //build the array

   cout <<"Enter elements\n";

   for (int i=0;i<n;i++){ //taking the elements from the user
      cin >>heap_arr[i];  //append the values to the array
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);  //print the input array
  
   heapSort(heap_arr, n);  
  
   cout << "Sorted array"<<endl; //print the sorted array
   displayArray(heap_arr, n);
}