#include <iostream>
using namespace std;
void Tower_Of_Hanoi(int n,int A,int B,int C){
    if(n>0){
        Tower_Of_Hanoi(n-1,A,C,B);
        cout<<"("<<A<<","<<C<<")"<<endl;
        Tower_Of_Hanoi(n-1,B,A,C);
    }
}
int main(){
    int n=0,a=0;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;i++)
        p[i]=i;
    cin>>a;
    int *q=new int [a];
    for(int i=0;i<n;i++)
        q[i]=p[i];
    delete []p;
    p=q;
    q=nullptr;
    cout<<p[3];    
    
    Tower_Of_Hanoi(3,1,2,3);
}