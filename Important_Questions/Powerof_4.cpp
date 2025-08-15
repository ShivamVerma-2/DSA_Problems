#include<iostream>
using namespace std;
bool powerof4(int n){
    if(n<=0) return false;
    while(n!=1){
        if(n%4!=0) return false;
        n/=4;
    }    
  return true;

}


int main(){
    cout<<"Enter the number";
    int n;
    cin>>n;
    if(powerof4(n)==true){
        cout<<"the number "<<n<<" is the power of 4";
    }
    else{
              cout<<"the number "<<n<<" is not the power of 4";
    }
    return 0;

}