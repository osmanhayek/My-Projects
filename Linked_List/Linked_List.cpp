#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;//marging; 

void creat_list(int A[],int n){
    struct Node *t,*last;
    first =new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void creat_list2(int A[],int n){
    struct Node *t,*last;
    second =new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }


}
int Sum(Node *p){
    int sum=0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;

}
int Count(Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
int Max(Node *p){
    int max=p->data;
    p=p->next;
    while(p){
        if(max<p->data) max=p->data;
        p=p->next;
    }
    return max;
}
Node *Search(Node *p,int key){
    Node *q;
    while(p){
        if(p->data==key){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
void Insert(int index,int x){
    Node *t,*p;
    if(index==0){
        t=new Node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(index>0){
        p=new Node;
        p=first;
        for(int i=0;i<index-1&&p;i++) p=p->next;
        if(p){
            t=new Node;
            t->data=x;
            t->next=p->next;
            p->next=t;
        }
        else cout<<"The index is not Valid!"<<endl;
        

    }
}
void Insert_Last(int x){
    Node *t,*last;
    if(first==NULL){
        t=new Node;
        t->data=x;
        t->next=NULL;
        first=t;last=t;
        
    }
    else{
        t=new Node;
        t->data=x;
        t->next=NULL;
        last->next=t;
        last=t; 
    }
}
void Inserted_Sorted(int x){
    Node *t,*p,*q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL)first=t;
    else{
        p=new Node;
        p=first;
        while(p&&p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
void Delete(int index){
    int x=-1;
    Node *p,*q;
    if(index==1){
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else if (index>1&&index<=Count(first)){
        p=first;
        q=NULL;
        for(int i=0;i<index-1&&p;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            delete p;
        }

    }
    else return;
    cout<<x<<" deleted"<<endl;
}
bool isSorted(Node *p){
    int x=INT32_MIN;
    while(p){
        if(p->data<x) return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
    
        
}
void Remove_Dup(Node *p){

    Node *q=first->next;
    while(q){
        if(p->data!=q->data){
            p=p->next;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
void Reversing_Elements(Node *p){
    int *A,i=0;
    A=new int[Count(p)];
    while(p){
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;i--;
    while(p){
        p->data=A[i];
        p=p->next;
        i--;
    }
    delete[] A;

}
void Reversing_Links(Node *p){
    Node *r=NULL,*q=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void Countrint(Node *p,Node *q){
    third=p;
    while(p->next){
        p=p->next;
    }
    p->next=q;
    q=NULL;
}
void Margring(Node *p,Node *q){
    Node *last;
    if(p->data<=q->data){
        third =p;
        last=third;
        p=p->next;
        last->next=NULL;
    }
    else{
        third=q;
        q=q->next;
        last->next=NULL;
    } 
    while(p&&q){
        if(p->data<=q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
            
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
    
    
}
int main(){
    //int A[]={10,20,30,40,50};
    //int B[]={15,35,65};
    //creat_list(A,5);
    //creat_list2(B,3);
    //Margring(first,second);
    //Display(third);
    //cout<<endl;
    //Display(first);
    Insert_Last(10);
    Insert_Last(100);
    Display(first);
    cout<<endl;
    Insert(1,200);
    Display(first);
    cout<<endl;
    Insert_Last(300);
    Display(first);
    
    return 0;
}