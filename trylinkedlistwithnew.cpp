#include<bits/stdc++.h>
using namespace std;
struct node{
    int capa;
    char id;
    int npas;
    node* poiNext;   //hmm what does this pointer point into?
};
struct LList{
    node* poiHead;
    int Size;
};
//implement functions: init, display, isEmpty, push/add, filter
void initLL(LList& LL){
    LL.poiHead = nullptr;
    LL.Size = 0;
}
node initNode(int c, char i, int n){
    node* node1 = new node;
    node1->capa=c;
    node1->id=i;
    node1->npas=n;

    node1->poiNext=nullptr;
    return *node1;
}
bool LLempty(const LList& LL){
    return LL.Size==0;
}
void addLL(LList& LL, node& node1){
    if (LLempty(LL)){
        LL.poiHead = &node1;
    }
    else{
        node* p=LL.poiHead;    //u use poi: not a copy!! dont wori
        while (p->poiNext!=nullptr){ //2. not the end, just last node
            p=p->poiNext;
        }
        p->poiNext=&node1;
    }
    node1.poiNext=nullptr;
    LL.Size++;
}

void displayLL(LList LL){
    node* p=LL.poiHead;
    while (p!=nullptr){     //1. go to the end of LL
        cout<<"Car id - "<<p->id<<": has ";
        cout<<p->npas<<"/"<<p->capa<<" passengers.\n";
        p=p->poiNext;
    }
    cout<<"Maintenant, train has "<<LL.Size<<" cars.\n\n";
}

void insertNode(LList& LL, node& node1, int pos){
    if (pos>LL.Size+1){
        cout<<"Cannot insert!!";
        cout<<"\nInvalid position: "<<pos;
        cout<<", because train has only "<<LL.Size<<" cars.\n";
        return;
    }
    cout<<"Inserting car (id "<<node1.id<<") at position "<<pos<<".\n";
    pos--;
    if (pos==0){
        node1.poiNext=LL.poiHead;
        LL.poiHead=&node1;
    }
    else{
        int i=0;
        node* prv=nullptr;
        node* nxt=LL.poiHead;
        while (i<pos){
            prv=nxt;
            nxt=nxt->poiNext;
            i++;
        }
        prv->poiNext=&node1;
        node1.poiNext=nxt;
    }
    LL.Size++;
}

void filterNode(LList& LL){
    node* prv=nullptr;
    node* crr=LL.poiHead;
    while(crr!=nullptr){
        if (crr->npas==0){
            if (crr==LL.poiHead){ //if crr points first node
                LL.poiHead=crr->poiNext;
            }
            else{
                prv->poiNext=crr->poiNext;
            }
            LL.Size--;
        }
        else{
            prv=crr;
        }
        crr=crr->poiNext;
    }
}
int main(){
    LList chain;
    initLL(chain);
    int n=6;
    node car[6];
    for (int i=0; i<6; i++){
        car[i]=initNode((i+1)*10, i+65, i);
        addLL(chain,car[i]);
    }
    cout<<"Initial train:\n";
    displayLL(chain);

    node car1,car2,car3,car4;
    car1=initNode(5,76,3);
    car2=initNode(58,77,0);
    car3=initNode(85,78,33);
    car4=initNode(13,81,0);

    insertNode(chain,car1,2);
    insertNode(chain,car4,8);
    insertNode(chain,car2,6);
    insertNode(chain,car3,6);
    cout<<"Train after inserting:\n";
    displayLL(chain);

    cout<<"Filtering cars that don't have any passengers...\n";
    filterNode(chain);
    displayLL(chain);

    insertNode(chain,car4,10);
    insertNode(chain,car2,8);
    return 0;
}
