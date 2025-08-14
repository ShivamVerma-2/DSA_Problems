#include<iostream>
using namespace std;
void backtrack(int i,int n){
if(i>n){
    return;
}
backtrack(i+1,n);
cout<<i<<endl;

}
int  main(){
int n;
cout<<"enetr the number"<<endl;
cin>>n;
backtrack(1,n);
return 0;

}

