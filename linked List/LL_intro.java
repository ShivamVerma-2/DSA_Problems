class node{
    int data;
    node next;
  node(int data1,node next){
    this.data=data1;
    this.next=next;

  }
}
public class LL_intro{
public static void main(String[] args){
int[] arr={2,4,5,6,8};
node y=new node(arr[1],null);
System.out.println(y.next);

}}
