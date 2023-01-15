#include<iostream>
using namespace std;
void print(int *A,int size);
int main(){
  int A[10]={1,2,3,4,5,6,7,8,9,10};
  print(A,10);


}
void print(int *A,int size){
  for(int i=0;i<size;i++){
	  cout<<A[i]<<"\n";
  }
  cout<<"Done"<<endl;
   


}
