#include<bits/stdc++.h>
using namespace std;
#define capa 10
struct web{
    string url;
    string tt;

};
struct Stack{
    web data[capa];
    int stEnd;
};
/*array-based stack
init()
display()
push()
pop()
*/
void initStack(Stack& st){
    st.stEnd=-1;
}
bool stEmpty(Stack& st){
    return (st.stEnd<0);
}
int stLength(Stack& st){
    return (st.stEnd+1);
}
void stPush(Stack& st, web w){
    if (stLength(st)==capa){
        cout<<"Too many websites!!\n";
    }
    else{
        st.stEnd++;
        st.data[st.stEnd]=w;
    }
}
void stPop(Stack& st){
    if (stEmpty(st)){
        cout<<"No website yet!!\n";
    }
    else{
        st.stEnd--;
    }
}
void displaySt(Stack st){
    int i=stLength(st);
    while (!stEmpty(st)){
        web x=st.data[st.stEnd];
        cout<<"Accessing website: "<<i<<". "<<x.tt<<"\n";
        stPop(st);
        i--;
    }
}
bool Return(Stack& bck, Stack& frt){
    if (stLength(bck)<2){
        cout<<"No previous page.\n";
        return 0;
    }
    else{
        web x=bck.data[bck.stEnd];
        stPop(bck);
        stPush(frt,x);

        cout<<"Returning to the previous website:\n";
        cout<<bck.data[bck.stEnd].tt<<"\n";
        cout<<"------------------------------------\n";

        return 1;
    }
}
void Forward(Stack& bck, Stack& frt){
    if (stEmpty(frt)){
        cout<<"No next page.\n";
    }
    else{
        web x=frt.data[frt.stEnd];
        stPop(frt);
        stPush(bck,x);

        cout<<"Fowarding to the next website:\n";
        cout<<x.tt<<"\n";
        cout<<"------------------------------------\n";
    }
}
int main(){
    web www[11];
    www[0]={"a","Wikipedia"};
    www[1]={"b","Youtube"};
    www[2]={"c","Messenger"};
    www[3]={"d","Zalo"};
    www[4]={"y","Yahoo"};
    www[5]={"f","BigHit Entertainment"};
    www[6]={"j","blog28tech"};
    www[7]={"h","Vnoi"};
    www[8]={"i","LQDOJ"};
    www[9]={"j","geeksforgeeks"};
    www[10]={"k","Cocoon"};

    Stack bck, frt;
    initStack(bck), initStack(frt);

    stPop(bck);
    cout<<"---------- Browing History ----------\n";
    for (int i=0; i<11; i++){
        stPush(bck,www[i]);
    }
    displaySt(bck);
    cout<<"\n";
    while (Return(bck,frt)){}

    Return(bck,frt);
    cout<<"\n";
    while (!stEmpty(frt)){
        Forward(bck,frt);
    }
    Forward(bck,frt);

    return 0;
}
