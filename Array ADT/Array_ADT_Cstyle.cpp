#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct Array{
  int size;
  int *A;
  int length;
};
void Display(struct Array arr){
  for(int i=0;i<arr.length;i++){
    cout<<arr.A[i]<<" ";
  }
}
void Add(struct Array *arr,int index){
    arr->A[arr->length]=index;
    arr->length++;
}
void insert(struct Array *arr,int index,int number){
    if(index>=0&& index<=arr->length){
    for(int i=arr->length;i>index;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=number;
    arr->length++;
    }

}
void Delete(struct Array *arr,int index){
    if(index>=0&&index<=arr->length-1){
    for(int i=index;i<arr->length;i++)
        arr->A[i]=arr->A[i+1];
    arr->length--;    
    }
}
int Linear_Search_improvmented(struct Array *arr,int key){
    for(int i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            //we can alse swap A[i]with A[i-1]and return i-1 that called Transposition
            int s=arr->A[0];
            arr->A[0]=arr->A[i];
            arr->A[i]=s;
            return 0;
        }
    }
    return -1;
}
int Binary_Search(struct Array *arr,int key){
    //the list must be sorted!
    int h,l,m;
    h=arr->A[arr->length-1];
    l=arr->A[0];
    m=(h+l)/2;
    while (true){
        if(key==arr->A[m])
            return m;
        else if(key>arr->A[m]){
            l=m+1;
            m=(h+l)/2;
        }
        else if(key<arr->A[m]){
            h=m-1;
            m=(h+l)/2;
        }
        if(l==h&&arr->A[m]!=key){
            return -1;
            
        }     
    }

}
int Binary_Search_another(struct Array *arr,int key){
    int h,l,m;
    h=arr->A[arr->length-1];
    l=arr->A[0];
    while(l<=h){
        m=(l+h)/2;
        if(key==arr->A[m])
            return m;
        else if(key>arr->A[m])
            l=m+1;   
        else
            h=m-1;         
    }
    return -1;
}
int Binary_Search_Recursionly(struct Array *arr,int key){
    static int l=arr->A[0],h=arr->A[arr->length-1],m;
    
    if(l<=h){
        m=(l+h)/2;
        if(key==arr->A[m])
            return m;
        else if(key>arr->A[m]){
            l=m+1;
            return Binary_Search_Recursionly(arr,key);
        }
        else{
            h=m-1;
            return Binary_Search_Recursionly(arr,key);
            }            
    }        
    return -1;

}
int Get(struct Array *arr,int index){
    if(index>=0&&index<arr->length)
        return arr->A[index];
    return -1;    
        
}
void Swap(int t1,int t2){
    int b=t1;
    t1=t2;
    t2=b;
}
void set(struct Array *arr,int index,int n){
    if(index>=0&&index<arr->length)
        arr->A[index]=n;
}
int Max(struct Array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(max<arr.A[i])
            max=arr.A[i]; 
    }
    return max;
}
int min(struct Array arr){
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(min>arr.A[i])
            min=arr.A[i];
    }
    return min;
}
int Sum(struct Array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.A[i];
        }
    return sum;
    }
void Reverse_1(struct Array *arr){
    //O(n)
    int *p;
    p=new int[arr->size];
    for(int i=arr->length-1,j=0;i>=0;i--,j++)
        p[j]=arr->A[i];
    for(int i=0;i<arr->length;i++)
        arr->A[i]=p[i];    
}
void Reverse_2(struct Array *arr){
    //O(n)
    int temp;
    for(int i=0,j=arr->length-1;i<j;i++,j--){
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}
void Left_Shift(struct Array *arr){
    for(int i=0;i<arr->length;i++){
        if(i==arr->length-1){
            arr->A[i]=0;
        }
        else{
        arr->A[i]=arr->A[i+1];
    }
    }
}
void Rotate(struct Array *arr){
    int temp=arr->A[0];
    for(int i=0;i<arr->length-1;i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=temp;
}
void Insert_sorted(struct Array *arr,int x){
    if(arr->length==arr->size) return;
    int i=arr->length-1;
    while(i>=0&&x<arr->A[i]){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
bool isSorted(struct Array *arr){
    for(int i=0;i<arr->length-1;i++){
        if(arr->A[i]>arr->A[i+1])
            return false;
    }
    return true;
}
void Negative_On_Left(struct Array *arr){
    //O(n)
    int i=0,j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0) {i++;}
        while(arr->A[j]>=0) {j--;}
        if(i<j){
            int temp=arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
    }
}
void Marging(struct Array *arr1,struct Array *arr2){
    int i=0,j=0,k=0,*C;
    C=new int [arr1->length+arr2->length];
    while(i<arr1->length&&j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            C[k]=arr1->A[i];
            k++;
            i++;
        }
        else{
            C[k]=arr2->A[j];
            k++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        C[k]=arr1->A[i];
        k++;
    }
    for(;j<arr2->length;j++){
        C[k]=arr2->A[j];
        k++;
    }
    for(int q=0;q<arr1->length+arr1->length;q++)
        cout<<C[q]<<" ";
}
void Union(struct Array *arr1,struct Array *arr2){
    //O(n*n)
    int *p,i;
    p=new int[arr1->length+arr2->length];
    for(i=0;i<arr1->length;i++){
        p[i]=arr1->A[i];
    }
    for(int j=0;j<arr2->length;j++){
        int x=0;
        for(int q=0;q<arr1->length;q++){
            if(arr2->A[j]!=arr1->A[q]){
                x++;
            }
        }
        if(x==arr1->length){
            p[i]=arr2->A[j];
            i++;
        }
}
    for(int a=0;a<i;a++)
        cout<<p[a]<<" ";
}
void Union_if_Sorted(struct Array *arr1,struct Array *arr2){
    //O(n)
    int *C,i=0,j=0,k=0;
    C=new int[arr1->length+arr2->length];
    while(i<arr1->length&&j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            C[k]=arr1->A[i];
            i++;
            k++;
        }
        else if (arr1->A[i]>arr2->A[j]){
            C[k]=arr2->A[j];
            j++;
            k++;
        }
        else{
            C[k]=arr1->A[i];
            i++;
            j++;
            k++;
        }
    }
    for(;j<arr2->length;j++){
        C[k]=arr2->A[j];
        k++;
    }
    for(;i<arr1->length;i++){
        C[k]=arr1->A[i];
        k++;
    }
    for(int a=0;a<k;a++)
        cout<<C[a]<<" ";

}
void Introsection(struct Array *arr1,struct Array *arr2){
    //O(n*n)
    int *p,k{};
    p=new int [arr1->length+arr2->length];
    for(int i=0;i<arr1->length;i++){
        for(int j=0;j<arr2->length;j++){
            if(arr1->A[i]==arr2->A[j]){
                p[k]=arr1->A[i];
                k++;
            }
        }
    }
    for(int a=0;a<k;a++)
        cout<<p[a]<<" ";
}
void Introsection_Sorted(struct Array *arr1,struct Array *arr2){
    //O(n)
    int *C,i=0,j=0,k=0;
    C= new int[arr1->length+arr2->length];
    while(i<arr1->length&&j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
            continue;
        }
        else if(arr1->A[i]>arr2->A[j]) {
            j++;
            continue;
        }
        else{
            C[k]=arr1->A[i];
            i++;
            j++;
            k++;
            continue;
        }
    }
    for(int a=0;a<k;a++) cout<<C[a]<<" ";
}
void Diffrence(struct Array *arr1,struct Array *arr2){
    int *C,k=0;
    C=new int [arr1->length+arr2->length];
    for(int i=0;i<arr1->length;i++){
        int x=0;
        for(int j=0;j<arr2->length;j++){
            if(arr1->A[i]!=arr2->A[j]) x++;
        }
        if(x==arr2->length){
            C[k]=arr1->A[i];
            k++;
        }
    }
    for(int a=0;a<k;a++) cout<<C[a]<<" ";
}
void Diffrence_Sorted(struct Array *arr1,struct Array *arr2){
    //O(n)
    int *C,i=0,j=0,k=0;
    C=new int [arr1->length+arr2->length];
    while(i<arr1->length&&j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            C[k]=arr1->A[i];
            i++;
            k++;
        }
        else if(arr1->A[i]>arr2->A[j]) j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        C[k]=arr1->A[i];
        k++;
    }
    for(int a=0;a<k;a++) cout<<C[a]<<" ";
}
int main() {
  struct Array arr;
  int n{};
  cout<<"Enter size of array: ";
  cin>>arr.size;
  arr.A=new int[arr.size];
  arr.length=0;
  cout<<"Enter number of the numbers: ";
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr.A[i];
  }
  //arr.length=n;
  //arr1.A=new int [10];
  //arr2.A=new int [10];
  //arr1.length=5;
  //arr2.length=3;
  //int A[]={3,5,10,14,16};
  //int B[]={2,4,5};
  //arr1.A=A;
  //arr2.A=B;
  //Diffrence_Sorted(&arr1,&arr2);
}