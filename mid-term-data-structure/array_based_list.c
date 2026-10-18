//CAUTION: USING << List* li >> THEN << &li >> BUT NOT List WHEN BUILDING FUNCTIONS
//if you want to know why: POINTER


/*Đây là template tham khảo của CTDL List xây dựng dựa ARRAY
vì dùng ARRAY nên nó phải xác định: giới hạn CAPACITY khi khai báo mảng

=> có hạn chế: không tự điều chỉnh size /resize/ đc nếu đã đạt capacity -> full
(muốn tự điều chỉnh thì array 0 đủ đô -> malloc() cho C hoặc lệnh new cho C++)

Lưu ý nha để nắm rõ mà sử dụng
*/
#include<stdio.h>
#define capa 1000           //capacity

struct _List{
    int size;
    int data[capa];         //key:      ARRAY
};
typedef struct _List List;



//(1) to INITIALIZE new LIST
void initList(List* li){    // trước và sau khi chạy hàm: thông tin list có thay đổi nên LƯU Ý về (&)
    // pass by reference
    li->size = 0;
}
//(2) to CHECK is LIST empty    <optional>
int listEmpty(List* li){
    return li->size==0;
}
//(3) to ADD new element to LIST // like .append(x) in python
void addList(List* li, int x){
    if (li->size == capa){
        printf("FULL\n");
        return;
    }

    li->data[li->size] = x;
    li->size ++;
}
//(bonus)  to Delete element which has index [ind]
//reminder: Index of List = from 0 to size-1
void deleteList(List* li, int ind){
    if (ind<0 || ind>=li->size){
        printf("Invalid index\n");
        return;
    }

    for (int i=0; i< li->size - 1; i++){
        if (i>=ind){
            li->data[i]=li->data[i+1];
        }
    }
    li->size--;
}
//(4) to DISPLAY all the content of LIST
void display(List li){
    for (int i=0; i< li.size; i++)
        printf("%d ", li.data[i]);
// why in this procedure, can use dot << . >> but cant use arrow -> !?
}



// MAIN - where USING LIST
int main(){
    List li;
    initList(&li);

    int t=10;
    while (t--){
        addList(&li,t);
    }
    printf("List be4 change: ");
    display(li);

    deleteList(&li,0);   //delete first ele, aka which has index [0]
    printf("\nList after change: ");
    display(li);
    return 0;
}