#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;            //value
    Node* poiNext;      //pointer
};
struct LinkedList{
    int size;           //size
    Node* poiHead;      //pointer trỏ first node
};

// 1. ham initNode
Node * init_Node(int x){
   
    Node * p = new Node;
    // dùng   <new>   thì phải liên quan đến con trỏ p
   
    p->val=x;
    p->poiNext=nullptr;

    return p;
    // hàm này trả về 1 node chứ không phải 1 pointer
    //bad way, u lost your node's address :((((
}

// 2. ham initLinkedList
void init_LinkedList(LinkedList& li){
    li.poiHead=nullptr;
    li.size=0;
}

// 3. empty
bool isEmpty(LinkedList li){
    return (li.size==0);
}

// 4. ham add
void pushBack(LinkedList& li, int val){
    Node * node1 = init_Node(val);

    if (isEmpty(li)){
        li.poiHead = node1;
    }

    else{
        Node * p = li.poiHead;
        while (p->poiNext!=nullptr){

            p = p->poiNext;

        }
        p->poiNext = node1;
    }
    //node1->poiNext=nullptr;
    li.size++;
}

//5. ham display
void display(LinkedList li){
    Node * p = li.poiHead;
    while (p != nullptr){
        cout<<p->val<<" ";
        p = p->poiNext;
    }
}

int main(){
    LinkedList li;
    init_LinkedList(li);

    for (int i=1; i<=20; i+=3){
        pushBack(li, i);
    }

    display(li);
    return 0;
}
