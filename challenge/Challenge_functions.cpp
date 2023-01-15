#include<iostream>
using namespace std;
template <class T>
class Array{
private:
    T *A;//Arrays
    int size;
    int length;
public:
    Array(){
        size=10;
        A=new T[10];
        length=0;
    }    
    Array(int sz){
        size=sz;
        A=new T[sz];
        length=0;
    }
    ~Array(){
        delete [] A;
    }
    void Intesh();
    void Finfing_1Missing_Sortred();
    void Finding_moreMissing_Sorted();
    void Finding_Missing_Unsorted();
    int Max();
    int Min();
};
template<class T>
int Array<T>::Max(){
    int temp=A[0];
    for(int i=0;i<length;i++){
        if(temp<A[i]){
            temp=A[i];
        }
    }
    return temp;
}
template<class T>
int Array<T>::Min(){
    int temp=A[0];
    for(int i=0;i<length;i++){
        if(temp>A[i]){
            temp=A[i];
        }
    }
    return temp;
}
template<class T>
void Array<T>::Intesh(){
    length=10;
    A[0]=3;A[1]=7;A[2]=4;A[3]=9;A[4]=12;A[5]=6;A[6]=1;A[7]=11;A[8]=2;A[9]=10;
    
}
template<class T>
void Array<T>::Finfing_1Missing_Sortred(){
    //for dogal sayilar n*(n+1)/2 used
    int diff,l=A[0],h=A[length-1];
    diff=l;
    for(int i=0;i<length;i++){
        if(A[i]-i!=diff){
            cout<<"The Missing number is: "<<i+diff;
            break;
        }
    }
}
template <class T>
void Array<T>::Finding_moreMissing_Sorted(){
    int diff,l=A[0],h=A[length-1];
    diff=l;
    for(int i=0;i<length;i++){
        if(A[i]-i!=diff){
            int n=diff;
            diff=A[i]-i;
            while(n<diff){
                cout<<n+i<<" ";
                n++;
            }
            
            continue;
        }
    }
}
template <class T>
void Array<T>::Finding_Missing_Unsorted(){
    //HashMap mf!
    
    int l,h;
    l=Min();
    h=Max();
    int H[l+h]={0};
    for(int i=0;i<length;i++){
        H[A[i]]++;
    }
    for(int i=1;i<=h;i++){
        if(H[i]==0) cout<<i<<" ";

    }
    cout<<endl;

}




int main(){
    Array<int> arr(100);
    arr.Intesh();
    arr.Finding_Missing_Unsorted();
    return 0;
}