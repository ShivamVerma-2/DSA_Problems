#include<iostream>
using namespace std;
bool powerof4(int n){
  if(n<=0) return false;
  for(int i=1;i<=n;i*=3){
    if(i==n) return true;

  }
return false;
}


int main(){
    cout<<"Enter the number";
    int n;
    cin>>n;
    if(powerof4(n)==true){
        cout<<"the number "<<n<<" is the power of 3";
    }
    else{
              cout<<"the number "<<n<<" is not the power of 3";
    }
    return 0;

}