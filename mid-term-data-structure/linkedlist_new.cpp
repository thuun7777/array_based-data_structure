#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node * poiNext;
};
struct Linkedlist{
    int size;
    Node * poiHead;
};
//(1) to INITIALIZE Node
Node * initNode(int val){
    Node * p = new Node;
    p->val=val; p->poiNext=nullptr;
    return p;
}
//(2) to INITIALIZE Linkedlist
void initLinkedlist(Linkedlist& li){
    li.size=0; li.poiHead=nullptr;
}
//(3) to CHECK is LList epmty
bool isEmpty(Linkedlist li){
    return li.size == 0;
}
//(4) to PUSH a value in LList
void pushBack(Linkedlist& li, int val){
    Node * newNode = initNode(val);

    if (isEmpty(li)){
        li.poiHead = newNode;
    }
    else{
        Node * p = li.poiHead;
        while (p->poiNext != nullptr){
            p=p->poiNext;
        }
        p->poiNext = newNode;
    }
    li.size++;
}
//(5) to DISPLAY all the content of LList
void display(Linkedlist li){
    Node * p = li.poiHead;
    while (p != nullptr){
        cout<<p->val<<' ';
        p = p->poiNext;
    }
}
//(bonus 1) to INSERT a Node
void insertNode(Linkedlist& li, int val, int pos){
    if (pos<1 || pos>li.size+1){
        cout<<"Invalid position\n";
        return;
    }

    Node * newNode = initNode(val);

    int cnt=1;
    Node * poiCurrent = li.poiHead;
    Node * poiPrevious = nullptr;
    while (cnt<pos){
        poiPrevious = poiCurrent;
        poiCurrent = poiCurrent->poiNext;

        cnt++;
    }
    if (poiPrevious == nullptr){              //i.e. that pos==cnt==1:    put newNode at first pos
        newNode->poiNext = li.poiHead;
        li.poiHead = newNode;
    }

    else{
        poiPrevious->poiNext = newNode;
        newNode->poiNext = poiCurrent;
    }

    li.size++;
}
//(bonus 2) to DELETE a Node has postion: pos
void deleteNode(Linkedlist& li, int pos){
    if (isEmpty(li)){
        cout<<"List is empty\n"; return;
    }
    if (pos<1 || pos>li.size){
        cout<<"Invalid position\n"; return;
    }

    Node * poiCurrent = li.poiHead;
    Node * poiPrevious = nullptr;

    int cnt=1;
    while (cnt<pos){
        poiPrevious = poiCurrent;
        poiCurrent = poiCurrent->poiNext;
        cnt++;
    }
    if (poiPrevious == nullptr){                 // i.e. pos==cnt==1: delete the first one
        li.poiHead = li.poiHead->poiNext; 
    }
    else{
        poiPrevious->poiNext = poiCurrent->poiNext;
    }
    li.size--;
}

int main(){
    Linkedlist li;    
    initLinkedlist(li);

    for (int i=1; i<=17; i+=2){
        pushBack(li, i);
    }
    cout<<"BEFORE CHANGE: ";
    display(li);

    insertNode(li, 2, 2);
    insertNode(li, 8, 4);
    insertNode(li, 2, 4);
    insertNode(li, 6, 6);

    //insertNode(li, 10, 15);       for case Invalid position
    cout<<"\nAFTER INSERT: ";
    display(li);

    cout<<"\n"<<li.size<<" this line (to mark ;}} )\n";

    deleteNode(li, 13);
    deleteNode(li, 2);
    deleteNode(li, 2);

    cout<<"AFTER DELETE: ";
    display(li);
    return 0;
}