typedef struct _LNode{
    int k;
    struct _LNode * next;
    struct _LNode * prev;
} LNode;

typedef struct _List{
    LNode * h; //Head pointer
    LNode * t; //Tail pointer
    int n; //Number of item in list
} List;

void printList(List l){
    LNode * c = l.h;
    printf("List: ");
    while(c != NULL){
        printf("%d ",c->k);
        c = c->next;
    }
}

int main(){
    List q;q.h = NULL;q.t=NULL;q.n=0;
    int x;
    do{
        scanf("%d",&x);
        if(x != 0){
            if(x == -1) printf("Following elememnts removed: %d\n",headRemove(&q));
            else//Add element
                tailInsert(&q,x);
            printList(q);
        }
        printf("\n");
    }while(x != 0);
    return 0;
}
