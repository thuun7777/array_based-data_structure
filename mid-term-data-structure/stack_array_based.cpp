/*Đây là template tham khảo của STACK xây dựng dựa ARRAY
vì dùng ARRAY nên nó phải xác định: giới hạn CAPACITY khi khai báo mảng

=> có lưu ý: initStack thì initialize << st.end  == -1 >>
(tư duy: khi thêm 1 phần tử đầu tiên -> st.end++
    + tức nó - phần tử đầu tiên - mang chỉ số [0] trong mảng data[ ]
    + và tính số lượng ptu trong Stack aka SIZE = st.end+1
) 

=> khi gọi hàm popStack, không thực sự xóa đi phần tử cuối cùng đc thêm
mà LÙI chỉ số index END--, để chỉ vào thằng thêm trước nó, làm việc với STACK từ đó

Lưu ý nha để nắm rõ mà sử dụng
*/

#include<bits/stdc++.h>
using namespace std;
#define capa 100        //capacity
struct Stack{
    int data[capa];     //  key:    ARRAY
    int end;
};


//1. to INITALIZE new STACK - involve with ARRAY
void initStack(Stack& st){
    st.end=-1;          //ONLY STACK - initial index set << -1 >>
}


//2. to CHECK is STACK empty    <optional>
bool isEmpty(Stack st){
    return st.end==-1;
}



//3. to ADD to STACK aka   ARRAY data[ ]   at the end/ top
void pushStack(Stack& st, int x){
    if (st.end+1 == capa){
        cout<<"Cannot push more. Stack is full!!\n";
        return;
    }

    st.end++;
    st.data[st.end]=x;
}


//4. to POP OUT the first element/ head of    ARRAY data[ ]
void popStack(Stack& st){
    if (!isEmpty(st)){
        st.end--;
    }
    else{
        cout<<"Nothing to pop. Stack is empty!!\n";
    }
}

//5. to DISPLAY all the content of QUEUE
//because of LIFO, we only summon the END aka top of STACK
void display(Stack st){
    while(!isEmpty(st)){
        cout<<st.data[st.end]<<' ';
        popStack(st);
    }
} 
//MAIN - where USING STACK
int main(){
    Stack st;
    initStack(st);
    popStack(st);

    for (int i=1; i<=18; i++){
        pushStack(st,i);
    }
    display(st);

    cout<<"\nThe number of elements in Stack is: "<<st.end+1;
    cout<<"\nTop of Stack is: "<<st.data[st.end];

    popStack(st);
    cout<<"\nTop of Stack is: "<<st.data[st.end];

    return 0;
}