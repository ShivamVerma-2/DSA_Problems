// #include<bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int data;
//     node *next;

//     node(int data1,node*next1){
//         data = data1;
//         next = next1;
//     }
//    public:
//     node(int data1){
//         data = data1;
    
//     }
// };
// int main(){
// vector<int>arr={2,3,4,6};
// node y=node(arr[3],nullptr);
// cout<<y.next;

// }
//------------------------------!!!!!!!!!!!!--------------------------------------------

//HOW TO CONVERT AN ARRAY TO LL


#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int data1,node*next1){
        data = data1;
        next = next1;
    }
   public:
    node(int data1){
        data = data1;
        next=nullptr;
}
};
node* convertARR2LL(vector<int>&arr){
    node* head=new node(arr[2]);
    node* mover=head;
    for(int i=0;i<arr.size();i++){
        node * temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;

    }
    return mover;
};
int main(){
vector<int>arr={2,3,4,6};
node *head=(convertARR2LL(arr));
cout<<head->data;

}


