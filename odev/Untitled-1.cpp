#include <iostream>
using namespace std;
void First_Part(){
  int size;
  cin>>size;
  for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            // reflect (x, y) to the top left quadrant as (a, b)
            int a = x;
            int b = y;
            if (a >= size / 2) a = size - a - 1;
            if (b >= size / 2) b = size - b - 1;

            // calculate distance from center ring
            int u = abs(a - size / 2);
            int v = abs(b - size / 2);
            int d = u > v ? u : v;
            int L = size / 2;
            if (size % 4 == 0) L--;

            // fix the top-left-to-bottom-right diagonal
            if (y == x + 1 && y <= L) d++;

            cout<<((d + size / 2) % 2 == 0 ? "X" : " ");
        }

        cout<<endl;
    }
  
}
void Second_Part(){
  int a;
  cin>>a;
  int ilkspace=a-1,ilkstar=1,n=(a/2)+1;
  while(a>0){
    for(int i=ilkspace;i>0;i--){
      cout<<" ";
    }
    for(int j=ilkstar;j>0;j--){
      cout<<"*";
    }
    cout<<endl;
    if(a>n){
      ilkspace-=2;
      ilkstar++;
    }
    else{
      ilkspace+=2;
      ilkstar--;
    }
    a--; 
}
  }
void Third_Part(){
  
  int a,i=0,x=1,max=12,n=1;
  cin>>a;
  /*bosluklar 3-0 3-2 3-3 0+1 3-0... seklinde gidiyor boyle olunca 3-3e geldikten zorlasiyor isler onun icin once n!=0 iken 3 bosluk 1 bosluk 0 bosluk yap dedim sonra n==0 olunca ni 1 yap dedim i ve x de baslangic degerlerine geri donsun dedim sonra x!=0 olacagi icin periyodik olarak n 0 olana kadar islem yapacaktir tabiki islemler bittikten sonra a yi bir azalt dedim*/
  while(a>0){
    if(n==0){
      n=1;
      i=0;x=1;
    }
    else{
    n=3-i;
    x++;
    i=x;
    }
    for(int i=n;i>0;i--){
        cout<<" ";
    }
    for(int i=max-2*n;i>0;i--){
        cout<<"*";
    }
    for(int i=n;i>0;i--){
        cout<<" ";
    }
    cout<<endl;
    a--;
}}
int main() {
  First_Part();
  Second_Part();
  Third_Part();
}