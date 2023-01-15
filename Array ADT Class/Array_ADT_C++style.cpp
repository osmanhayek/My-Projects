#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
template<class T>
class Array{
private:
    T *A;
    int size;
    int length;
public:
    Array(){
        size=10;
        A=new T[size];
        length=0;
    }
    Array(int sz){
        size=sz;
        A=new T[size];
        length=0;
    }
    ~Array(){
        delete []A;
    }
    void Display();
    void Insert(int ,T ); 
    void Delete(int);
};
template<class T>
void Array<T>::Display(){
    for(int i=0;i<length;i++) cout<<A[i]<<" ";
    cout<<endl;
}
template<class T>
void Array<T>::Insert(int index,T x){
    length++;
    if(index>=0&&index<length){
    for(int i=length-1;i!=index;i--){
        A[i]=A[i-1];
    }
    A[index]=x;
    }
    else {
        cout<<"please enter a valid index!"<<endl;
        length--;
}
}
template<class T>
void Array<T>::Delete(int index){
    
    if(index>=0&&index<length){
        for(int i=index;i<length;i++)
            A[i]=A[i+1];
        length--;
        cout<<"The List had updated!"<<endl;    
    }
    else cout<<"Please Enter a valid index!"<<endl;
}
int main() {
    Array<int> arr,arr1(100);
    int index,x,n;
    
    do{
        cout<<"1 or 2?"<<endl;
        cin>>n;
        switch(n){
            case 1: 
                cout<<"Enter index and the number: ";
                cin>>index>>x;
                arr.Insert(index,x);
                break;
            case 2:
                arr.Display();
                break;        
        }
    }while(n==2||n==1);
}

