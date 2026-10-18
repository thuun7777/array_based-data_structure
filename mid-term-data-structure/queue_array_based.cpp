/*Đây là template tham khảo của QUEUE xây dựng dựa ARRAY
vì dùng ARRAY nên nó phải xác định: giới hạn CAPACITY khi khai báo mảng

=> có hạn chế: số phần tử tăng lên khi enQueue (thêm mới vào cuối hàng đợi)
nhưng khi deQueue (chặt đầu) chỉ DỊCH index HEAD++, không thật sự xóa data[HEAD] khỏi array

Lưu ý nha để nắm rõ mà sử dụng
*/

#include<bits/stdc++.h>
using namespace std;
#define capa 100        //  capacity
struct Queue{
    int data[capa];     //  key:  ARRAY
    int head;
    int end; 
};



//1. to INITALIZE new QUEUE - involve with ARRAY
void initQueue(Queue& q){
    q.head=0;           //then      size of queue = q.end - q.head
    q.end=0;
}


//2. to CHECK is QUEUE empty    <optional>
bool isEmpty(Queue q){
    return q.end - q.head == 0;
}



//3. to ADD to QUEUE aka   ARRAY data[ ]   at the tail/ rear/ end
void enQueue(Queue& q, int x){
    if (q.end - q.head == capa){
        cout<<"Cannot push more. Queue is full\n";
        return;
    }
    // if not full add value x at the end of  ARRAY data[ ]
    q.data[q.end]=x;
    q.end++;
}


//4. to POP OUT the first element/ head of    ARRAY data[ ]
void deQueue(Queue& q){
    if (!isEmpty(q)){
        q.head++;
    }
    else{
        cout<<"Nothing to pop. Queue is empty\n";
    }
}


//5. to DISPLAY all the content of QUEUE
//because of FIFO, we only summon the HEAD aka top of QUEUE 
int topQueue(Queue q){
    return q.data[q.head];
}

void display(Queue q){
    while(!isEmpty(q)){
        cout<<topQueue(q)<<' ';
        deQueue(q);
    }
}
// MAIN - where USING QUEUE
int main(){
    Queue q;
    initQueue(q);
    deQueue(q);

    for (int i=67; i<81; i++){
        enQueue(q,i);
    }
    // checkpoint1
    display(q);
    cout<<"\nNumber of Elements in QUEUE: "<<q.end-q.head;
    cout<<"\n";

    //checkpoint2
    while(!isEmpty(q)){
        cout<<topQueue(q)<<' ';
        deQueue(q);
    }
    cout<<"\nNumber of Elements in QUEUE: "<<q.end-q.head;

    return 0;
}
/* miniQuest to test:
1) why before checkpoint2, size == 14 but after that size == 0?
2) what so different between:
    - the display(q) at checkpoint1
    - the code at checkpoint2 
*/