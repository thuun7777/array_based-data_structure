//NEED TO UNDERSTAND WHY USING List& BUT NOT List WHEN CODING FUNCTIONS

/*Đây là template tham khảo của CTDL List xây dựng dựa ARRAY
vì dùng ARRAY nên nó phải xác định: giới hạn CAPACITY khi khai báo mảng

=> có hạn chế: không tự điều chỉnh size /resize/ đc nếu đã đạt capacity -> full
(muốn tự điều chỉnh thì array 0 đủ đô -> malloc() cho C hoặc lệnh new cho C++)

Lưu ý nha để nắm rõ mà sử dụng
*/

#include<bits/stdc++.h>
using namespace std;
#define capa 1000           //capacity
struct List{
    int size;
    int data[capa];         //key:      ARRAY
};
//(1) to INITIALIZE new LIST
void initList(List& li){    // trước và sau khi chạy hàm: thông tin list có thay đổi nên LƯU Ý về (&)
    // pass by reference
    li.size = 0;
}
//(2) to CHECK is LIST empty    <optional>
bool listEmpty(List li){
    return li.size==0;
}
//(3) to ADD new element to LIST // like .append(x) in python
void addList(List& li, int x){
    if (li.size == capa){
        cout<<"FULL\n";
        return;
    }

    li.data[li.size] = x;
    li.size ++;
}
//(bonus)  to Delete element which has index [ind]
//reminder: Index of List = from 0 to size-1
void deleteList(List& li, int ind){
    if (ind<0 || ind>=li.size){
        cout<<"Invalid index\n";
        return;
    }

    for (int i=0; i< li.size - 1; i++){
        if (i>=ind){
            li.data[i]=li.data[i+1];
        }
    }
    li.size--;
}
//(4) to DISPLAY all the content of LIST
void display(List li){
    for (int i=0; i< li.size; i++)
        cout<<li.data[i]<<" ";
}
// MAIN - where USING LIST
int main(){
    List li;
    initList(li);

    int t=10;
    while (t--){
        addList(li,t);
    }
    cout<<"List be4 change: ";
    display(li);

    deleteList(li,9);   //delete last ele, aka which has index [size-1] = [9]
    cout<<"\nList after change: ";
    display(li);
    return 0;
}