#include<bits/stdc++.h>
using namespace std;
#define capa 10

struct item{
    string na;
    int qu;
    float pr;
};
struct customer{
    string na;
    int idit;
    int wannabuy;
};
//in C langue: teacher use * in parameters => not local val
//then in C++: we use &
/*array-based queue = no dynamic: no malloc(), no new
init()
display()
isEmpty()
length()
enqueue()
dequeue()
*/

struct Queue{
    //int - ordinary
    customer data[capa];
    int qfront, qback;
};
void initQueue(Queue& q){
    q.qfront=0;
    q.qback=0;
}
bool qEmpty(Queue& q){
    return (q.qback == 0);
}
int qLength(Queue& q){
    return (q.qback - q.qfront);
}
//if enter the queue succeed -> 1, if not -> 0
bool enQueueu(Queue& q, customer newData){
    if (qLength(q)==capa){
        cout<<"Queue data fetch failed. Queue is full!\n";
        return 0;
    }
    if (qEmpty(q)){
        q.data[0]=newData;
    }
    else{
        int ind=q.qback;
        q.data[ind]=newData;
    }
    q.qback++;
    return 1;
}
//if pop front ele succeed -> 1, if not -> 0
bool deQueue(Queue& q){
    if (qEmpty(q)){
        cout<<"Queue has already been empty!\n";
        return 0;
    }
    int n=qLength(q);
    if (n>1){
        for (int i=1; i<n; i++)
            q.data[i-1]=q.data[i];
    }
    q.qback --;    // if n==1: q->back = 0; then qEmpty(q)==1
    return 1;
}
void displayQ(Queue c, item it){
    while (!qEmpty(c)){
        customer x=c.data[c.qfront];
        cout<<x.na<<" wanna buy "<<x.wannabuy<<" "<<it.na<<"\n";
        deQueue(c);
    }
}
int main(){
    item items[5];
    items[0]={"Fami canxi", 6, 27.4};
    items[1]={"Kimchi", 3, 48.3};
    items[2]={"Dumpling", 18, 15.9};
    items[3]={"Choco pie", 11, 33.5};
    items[4]={"Pringles",  166, 30.0};

    customer cuss[10];
    cuss[0]={"Hailey", 4, 3};
    cuss[1]={"Baley", 4, 5};
    cuss[2]={"Bonley", 4, 7};
    cuss[3]={"Namley", 4, 1};
    cuss[4]={"Sauley", 4, 4};
    cuss[5]={"Bayley", 4, 6};
    cuss[6]={"Tamley", 4, 2};
    cuss[7]={"Chinley", 4, 8};
    cuss[8]={"Muoiley", 4, 9};
    cuss[9]={"Motley", 4, 11};

    Queue c;
    initQueue(c);
    int i=0;
    while (items[4].qu>=0){
        enQueueu(c,cuss[i]);

        //cout<<"THE QUEUE RIGHT NOW\n";
        //displayQ(c,items[4]);

        customer x = c.data[c.qfront];

        items[x.idit].qu-=x.wannabuy;
        if (items[x.idit].qu<0){
            cout<<"Sold out!\n";
            break;
        }
        else{
            cout<<x.wannabuy<<" "<<items[x.idit].na<<" purchased!\n";
            cout<<items[x.idit].na<<" remaining: "<<items[x.idit].qu<<"\n";
        }

        deQueue(c);

        if (i<9) i++;
        else i=0;

        cout<<"-------------------------\n";
    }

    cout<<"\nCustomer remaining:\n";
    displayQ(c, items[4]);

    return 0;
}
