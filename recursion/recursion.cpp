#include <iostream>
#include <stdio.h>
using namespace std;
void Indirect_Recursion2(int);
void Trail_Recursion(int n){//Time O(n) and the space: O(n)
                           //loops: Time O(n) and the space: O(1) so the loops is better
                           //than Trail Recursion
    if(n>0){
        printf("%d ",n);
        Trail_Recursion(n-1);
    }    
}
void Head_Recusion(int n){//
    if(n>0){
        Head_Recusion(n-1);
        printf("%d ",n);
    }
}
void Tree_Recursion(int n){//Time O(2^n) space O(n)!
    if(n>0){
        cout<<n<<" ";
        Tree_Recursion(n-1);
        Tree_Recursion(n-1);
    }
}
void Indirect_Recursion1(int n){
    if(n>0){
        cout<<n<<" ";
        Indirect_Recursion2(n-1);
    }
}
void Indirect_Recursion2(int n){
    if(n>1){
        cout<<n<<" ";
        Indirect_Recursion1(n/2);
    }
}
int Nested_Recursion(int n){
    if(n>100){
        return n-10;
    }
    return Nested_Recursion(Nested_Recursion(n+11));
}
int ex1(int n){//trail_recursion!
    static int sum=0;
    if(n>0){
        sum+=n;
        ex1(n-1);
    }
    return sum;
}
int ex2(int n){
    if(n==0){
        return 1;
    }
    return ex2(n-1)*n;
}
int ex3(int m,int n){/*power*/
    if(n==0)
        return 1;
    return ex3(m,n-1)*m;    
}
int ex3_faster(int m,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0)
        return ex3_faster(m*m,n/2);
    return m*ex3_faster(m*m,(n-1)/2);    
}
/*int ex3_loop(int m,int n){//2 7
    int y;
    if(n%2==0)
        y=2;
    else
        y=1;    
    int i=n; //i=
    if(n==0){
        return y;
    }
    while(i>0){//i=7
        if(i%2!=0){
            i--;//i=6,2
            y=y*m;//2 2*2*2
            continue;
        }

        y=y*y;//2*2,2*2*2*2*2*2
        i=i/2;//
    }
    if(n%2==0)
        return y/2;
    
    return y;
}*/
double Tylor_Number(int x,int n){
    if(n==0)
        return 1;
    static double p=1;
    static double f=1;
    double r;
    r=Tylor_Number(x,n-1);
    p=p*x;
    f=f*(n);
    
    return r+p/f; 
}
double Taylor_Number_faster_loop(int x,int n){
    double s=1.00;
    for(;n>0;n--){
        s=1+(x/n)*s;
    }
    return s;
}
double Taylor_Number_faster_Rec(int x, int n){
    static double s=1;
    if(n==0)
        return s;
    s=1+(x/n)*s;
    Taylor_Number_faster_Rec(x,n-1);    
}
int Fibonacci_with_loop(int n){//time=O[n],space=O[1]
    int a=0,b=1,s=0;
    if(n<=1) return n;
    for(int i=2;i<=n;i++){
        s=a+b;
        a=b;
        b=s;
    }
    return s;
}
int Fibonacci_with_Recursion(int n){//time O(2^n)
    if(n<=0)return n;
    return Fibonacci_with_Recursion(n-2)+Fibonacci_with_loop(n-1);
}
int F[10];
int fib(int n){
  if(n==1||n==0){
    F[n]=n;
    return n;
  }
  else{
    if(F[n-2]==-1){
      F[n-2]=fib(n-2);
    }
    if(F[n-1]==-1){
      F[n-1]=fib(n-1);
    }
    return F[n-2]+F[n-1];
  }
}
int Combination(int n,int r){
    if(r==0||n==r)return 1;
    else{
    return Combination(n-1,r-1),Combination(n-1,r);
}
}

int main(){
    Trail_Recursion(3);
    cout<<endl;
    Head_Recusion(3);
    cout<<endl;
    Indirect_Recursion1(20);
    cout<<endl;
    cout<<Nested_Recursion(95);
    cout<<endl;
    cout<<ex1(5);
    cout<<endl;
    cout<<ex2(5);
    cout<<endl;
    cout<<ex3(2,5);
    cout<<endl;
    cout<<ex3_faster(2,10);
    cout<<endl;
    //cout<<ex3_loop(2,10);
    cout<<Tylor_Number(3,10);
    cout<<endl;
    cout<<Fibonacci_with_loop(8);
    cout<<endl;
    cout<<Fibonacci_with_Recursion(8);
    cout<<endl;
    for(int i=0;i<10;i++) F[i]=-1;
    cout<<fib(5);
    cout<<endl;
    cout<<Combination(4,3);
    return 0;
}