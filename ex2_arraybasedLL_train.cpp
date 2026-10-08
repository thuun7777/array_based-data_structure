#include<bits/stdc++.h>
using namespace std;
struct node{
    int capa;
    char id;
    int pas;
    node* poiNext;
};
struct LinkedList{
    node* poiHead;
    int Size;
};
void LLinit(LinkedList& L){
    L.poiHead=nullptr;
    L.Size=0;
}

void filter(LinkedList& L, int& n){
    node* p_current = L.poiHead;
    node* p_previous = nullptr;
    while (p_current != nullptr){
        if (p_current->pas==0){
            if (p_previous==nullptr){   //case: remove head
                L.poiHead=p_current->poiNext; //change CURR, prev nothin
            }
            else{                       //other cases
                p_previous->poiNext=p_current->poiNext;
            }
            n--;
        }
        else{
            p_previous = p_current;
        }
        p_current=p_current->poiNext;
    }
}
void display(const LinkedList& L, const int& n){
    int cnt=0;
    node* p_current = L.poiHead;
    while (p_current != nullptr){
        cnt++;
        cout<<"Car "<<cnt<<" (id: "<<p_current->id<<") has ";
        cout<<p_current->pas<<'/'<<p_current->capa<<" passengers\n";
        p_current = p_current->poiNext;
    }
    cout<<"The length of the train: "<<n<<"\n\n";
}

int main(){
    LinkedList chain;
    LLinit(chain);

    int n=6;    //should be less than 100
    node car1,car2,car3,car4,car5,car6;

    car1.capa=10; car2.capa=2; car3.capa=30;
    car4.capa=40; car5.capa=60; car6.capa=50;

    car1.id='O'; car2.id='T'; car3.id='E';
    car4.id='F'; car5.id='I'; car6.id='S';

    car1.pas=0; car2.pas=1; car3.pas=2;
    car4.pas=9; car5.pas=4; car6.pas=0;

    car1.poiNext=&car2;
    car2.poiNext=&car3;
    car3.poiNext=&car4;
    car4.poiNext=&car5;
    car5.poiNext=&car6;
    car6.poiNext=nullptr;

    chain.poiHead=&car1;
    cout<<"Before changes:\n";
    display(chain,n);

    int pos=4;
    node newcar;
    newcar.capa=8; newcar.id='N'; newcar.pas=7;
    newcar.poiNext=&car4; car3.poiNext=&newcar;
    cout<<"A new car whose id is "<<newcar.id<<" was added at position "<<pos;
    n++;
    pos=7;
    node newcar1;
    newcar1.capa=80; newcar1.id='C'; newcar1.pas=0;
    newcar1.poiNext=&car6; car5.poiNext=&newcar1;
    cout<<"\nA new car whose id is "<<newcar1.id<<" was added at position "<<pos;
    n++;
    cout<<"\nAfter insertion:\n";
    display(chain,n);

    cout<<"\nFiltering cars that don't have any passengers...\n";
    filter(chain,n);

    display(chain,n);
    return 0;
}
