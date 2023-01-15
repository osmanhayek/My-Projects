#include <iostream>
#include <vector>
using namespace std;
class String{
private:
  char *A;
  int size;
public:
  String(){
    size=10;
    
  }
  String(int sz){
    size=sz;
  }
  void Upper();
  void Intsh(char *);
  void Lower();
  void Changing_Case();
  int Words();
  int Valid();
  void Reverse();
  void Compiring(char *B);
  int Palindrome();
  void Duplicate_Hash();
  int Anagram_Hash(char *);
};
void String::Intsh(char *B){
  A=B;
}
void String::Upper(){
  for(int i=0;A[i]!='\0';i++){
    if(A[i]>='a'&&A[i]<='z'){
      A[i]-=32;
    }
  }
  cout<<A;
}
void String::Lower(){
    for(int i=0;A[i]!='\0';i++){
        if(A[i]>='A'&&A[i]<='Z'){
            A[i]+=32;
        }
    }
    cout<<A;
}
void String::Changing_Case(){
    for(int i=0;A[i]!='\0';i++){
        if(A[i]>='A'&&A[i]<='Z'){
            A[i]+=32;
        }
        else if(A[i]>='a'&&A[i]<='z'){
            A[i]-=32;
        }
    }
    cout<<A;
}
int String::Words(){
    int words=0;
    for(int i=0;A[i]!='\0';i++){
        if(A[i]==' '&&A[i-1]!=' ') words++;
    }
    return words+1;
}
int String::Valid(){//0=48 9=57
    for(int i=0;A[i]!='\0';i++){
        if(!(A[i]>='A'&&A[i]<='Z')&&!(A[i]>='a'&&A[i]<='z')&&!(A[i]>=48&&A[i]<=57)){
            return 0;
        }
    }
    return 1;
}
void String::Reverse(){
    char t;
    int j;
    for(j=0;A[j]!='\0';j++);
    j--;
    for(int i=0;i<j;i++,j--){
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    cout<<A;

}
void String::Compiring(char *B){
  int i,j;
  for(i=0,j=0;A[i]!='\0'&&B[j]!='\0';j++,i++){
      if(A[i]>='A'&&A[i]<='Z'){
        if(A[i]!=B[j]&&A[i]+32!=B[j]) break;
      }
      else if (A[i]>='a'&&A[i]<='z'){
        if(A[i]!=B[j]&&A[i]!=B[j]+32) break;
      }
      else{
        if(A[i]!=B[j]) break;
      }
  }
  if(A[i]==B[j]) cout<<"They are same!"<<endl;
  else cout<<"They are not the same!"<<endl;
}
int String::Palindrome(){
  //counting the length
  int l,i,j;
  for(l=0;A[l]!='\0';l++);
  l--;
  j=l;
  i=0;
  while(i<j){
    if(A[i]>='A';A[i]<='Z'){
        if(A[i]!=A[j]&&A[i]+32!=A[j]){
          break;
        }
    }
    else if(A[i]>='a';A[i]<='z'){
        if(A[i]!=A[j]&&A[i]!=A[j]+32) break;
    }
    else{
      if(A[i]!=A[j]) break;
    }
    i++;j--;
  }
  if(i>=j) return 1;
  return 0;
}
void String::Duplicate_Hash(){
  int H[26]={0},n=0;
  for(int i=0;A[i]!='\0';i++) {
    if(A[i]>='A'&&A[i]<'Z'){
      H[A[i]-65]++;
      n=1;
    }
    else if(A[i]>='a'&&A[i]<='z'){
      H[A[i]-97]++;
      n=0;
    }
  }
  for(int i=0;i<26;i++){
    if(H[i]>1&&n==0){
      cout<<char(i+97)<<" "<<H[i]<<" time"<<endl;
    }
    else if(H[i]>1&&n==1){
        cout<<char(i+65)<<" "<<H[i]<<" time"<<endl;
    }
  }
}
int String::Anagram_Hash(char *B){
  int H[26]={0};
  for(int i=0;A[i]!='\0';i++) {
    H[A[i]-97]++;
  }
  for(int i=0;B[i]!='\0';i++) {
    H[B[i]-97]--;
    if(H[B[i]-97]<0) return 0;
  }
  return 1;
}
int main() {
    char B[]="mmmal";
    char C[]="almmm";
    String str(100);
    str.Intsh(B);
    str.Duplicate_Hash();
  }