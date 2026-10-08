#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define capa 1000
struct List{
    int ele[capa+1];
    int sizee;
};

void init(List& L){
    L.sizee=0;
}
//calculate sum + display whole num. + add + remove

int sumdi(const List& L){
    int res=0;
    for (int i=1; i<L.sizee; i++)
        res+=L.ele[i];
    return res;
};

ll display(const List& L){
    int n=L.sizee - 1;
    int res=0;
    for (int i=1; i<=n; i++){
        res = res*10 + L.ele[i];
    }
    if (L.ele[0]==-1) return -res;
    else return res;
}

int insertt(List& L, int pos, int num){
    if (pos<1 || pos>=L.sizee){
        cout<<"\nIllegal Index!\n";
        return -1;
    }
    int ndigit=0;
    int a[100];
    while (num>0){
        a[ndigit]=num%10;
        num/=10;
        ndigit++;
    }
    int n=L.sizee+ndigit;

    if (n>capa){
        cout<<"\nCannot add: Exceeded the maximum limit\n";
        return -1;
    }
    int temp;
    for (int i=n-1; i>=pos; i--){
        if (i>=pos+ndigit){
            L.ele[i]=L.ele[i-ndigit];
            temp=i;
        }
        else{
            L.ele[i]=a[temp-(pos+ndigit)];
            ndigit--;
        }
    }
    L.sizee=n;
    return display(L);
};

int removee(List& L, int pos){
    if (L.sizee==0){
        cout<<"\nNothing to remove!\n";
        return -1;
    }
    if (pos<1 || pos>=L.sizee){
        cout<<"\nIllegal index!\n";
        return -1;
    }
    int n=L.sizee;
    for (int i=pos; i<L.sizee-1; i++){
            L.ele[i]=L.ele[i+1];
    }
    L.sizee--;
    return display(L);
};

int main(){
    List ui;        //unbounded int
    init(ui);
    ui.ele[0]=-1;
    ui.ele[1]=3;
    ui.ele[2]=2;
    ui.ele[3]=9;
    ui.ele[4]=8;

    ui.sizee=5;     //for 4-digit num -> 5 ele.s
    int pos_ins, pos_rem;
    cout<<"The initial number: "<<display(ui)<<"\n\n";

    pos_ins=3;
    cout<<"Enter the digits inserted in position "<<pos_ins<<": ";
    int ins=7416;
    cout<<ins;
    cout<<"\nAfter insertion: "<<insertt(ui,pos_ins,ins);

    pos_rem=5;
    cout<<"\nAfter removing a digit at position "<<pos_rem<<": ";
    cout<<removee(ui,pos_rem)<<"\n";

    cout<<"\nThe sum of all digits: "<<sumdi(ui);
    cout<<"\nThe unbounded integer: "<<display(ui);
    return 0;
}
