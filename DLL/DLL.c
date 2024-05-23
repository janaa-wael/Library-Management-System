#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../STD_TYPES_H.h"
#include "DLL.h"
void main_menu(){
    printf("%c\n1-Add Book\n2-Delete Book\n3-View Books\n4-Search for Author Works\n5-Exit",7);

}


void createlist(struct List* pBook){
	pBook->head = NULL;
	pBook->size = 0;
}

u32 list_size(struct List* pList){
    return pList->size;
}

void addbook(struct List* pList, u8 name[], u8 author[], f32 price, u32 id ,u32 pos){
struct book*temp = (struct book*)malloc(sizeof(struct book));
if (temp == NULL){
    printf("No space available");
}
strcpy(temp->book_name,strlwr(name)); //Node initialization
strcpy(temp->book_author,strlwr(author));
temp->book_id = id;
temp->book_price = price;

temp->next = NULL;
if(pos == 0){ //INSERT AT THE BEGINNING
temp->next = pList->head;
pList->head = temp;
temp->prev = pList->head;
}
else if(pos == pList->size){
   struct book* temp1 = pList->head;

    while(temp1->next != NULL){
        temp1 = temp1->next;


    }
    temp1->next = temp;
    temp->prev = temp1;
    temp->next = NULL;

}
else if(pos>0 && pos<pList->size){
    struct book* temp1 = pList->head;

    for(int i = 0;i<pos-1; i++){
        temp1 = temp1 -> next;
    }
   temp->next = temp1->next;
   temp1->next = temp;
   temp->prev = temp1;
   temp1 = temp->next;
   temp1->prev = temp;

}
pList->size ++;
printf("\nNo. of current books available in the library : %d",pList->size);
}

void delete_book_by_name(struct List*pList, u8 name[]){
u32 pos=0;
struct book* temp1 = pList->head;
u32 x = strcmp(temp1->book_name,strlwr(name));
while(x!=0){
    temp1 = temp1->next;
    pos++;
    if(temp1== NULL){
        printf("\nBook doesn't exist in library");
        break;
    }
    x = strcmp(temp1->book_name,name);
}
    if(pList->head == NULL){
        printf("\nLibrary is empty!");
    }
    else if(pos == 0){
        temp1 = pList->head;
        pList->head = temp1->next;
        free(temp1);
        pList->size --;
    }
    else if(pos>0 && pos<((pList->size)-1)){
        struct book* temp2 = temp1->prev;
        temp1 = temp1->next;
        temp1->prev = temp2;
        temp1 = temp2->next;
        temp2->next = temp1->next;
        free(temp1);
        pList->size --;
    }
    else if(pos == (pList->size -1)){
        struct book* temp2 = temp1->prev;
        temp2->next = NULL;
        free(temp1);
        pList->size --;
    }

    printf("\nNo. of books available in the library : %d",pList->size);
}


void delete_book_by_id(struct List* pList,u32 id){
    u32 pos=0;
    struct book* temp1 = pList->head;
    while(temp1->book_id != id ){
        temp1 = temp1->next;
        pos++;
        if(temp1== NULL){
            printf("\nBook doesn't exist in library");
            break;
        }
    }
    if(pList->head == NULL){
        printf("\nLibrary is empty!");
    }
    else if(pos == 0){
        temp1 = pList->head;
        pList->head = temp1->next;
        free(temp1);
    }
    else if(pos>0 && pos<((pList->size)-1)){
        struct book* temp2 = temp1->prev;
        temp1 = temp1->next;
        temp1->prev = temp2;
        temp1 = temp2->next;
        temp2->next = temp1->next;
        free(temp1);
        }
        else if(pos == (pList->size -1)){
            struct book* temp2 = temp1->prev;
            temp2->next = NULL;
            free(temp1);
        }
        pList->size --;
        printf("\nNo. of books available in the library : %d",pList->size);
}

u32 check_id(struct List* pList,u32 id){
    struct book* temp = pList->head;
    u32 counter=0;
    while(temp!=NULL){
        if(temp->book_id== id){
            counter=1;
            return 1;
            break;
        }
        temp=temp->next;
    }
    return 0;
}

u32 check_name(struct List* pList,u8 name[]){
    struct book* temp = pList->head;
    u32 counter=0;
    while(temp!=NULL){
        u32 x = strcmp(temp->book_name,strlwr(name));
        if(x==0){
            counter=1;
            return 1;
            break;
        }
        temp=temp->next;
    }
    return 0;
}

void author_works(struct List*pList){
    struct book*temp = pList->head;
    u8 author[50];
    u32 counter = 0;
    printf("\nEnter author name : ");
    scanf(" %[^\n]s",&author);
    printf("\nBOOKS BY %s :\n",strupr(author));
    while(temp!= NULL){
            u32 x = strcmp(temp->book_author,strlwr(author));
        if(x==0){
            counter++;
            printf("\nBook %d : ",counter);
            printf("\nName : %s",temp->book_name);
            printf("\nID : %d",temp->book_id);
            printf("\nPrice : %.2f",temp->book_price);
            printf("\n-----------------------------");
        }
        temp = temp->next;
    }
    printf("\nNo. of books by %s available in the library : %d",author,counter);
}


void printlist(struct List*pList){
    struct book* temp = pList->head;
    if(pList->head == NULL){
        printf("\nEmpty list!");
    }
    else{
        for(u32 i = 0; i<pList->size; i++){
            printf("\nBook %d : ",i+1);
            printf("\nName : %s",temp->book_name);
            printf("\nAuthor : %s",temp->book_author);
            printf("\nID : %d",temp->book_id);
            printf("\nPrice : %.2f",temp->book_price);
            printf("\n-----------------------------");
            temp=temp->next;
        }
    }
}


void app(){
    createlist(&L1);
    do{

        main_menu();
        printf("\nEnter your choice (1-4) :\n");
        scanf("%d",&choice);
        while(1){
            printf("\nEnter your password to proceed :\n");
            scanf(" %[^\n]s",&pass);
            u32 x = strcmp(pass,o_pass);
            if( x!= 0){
                printf("Incorrect password, please try again\n");
            }
            else if(x==0){
                break;
            }
        }


        switch(choice){
            case 1 :

                printf("Enter a book name : ");
                scanf(" %[^\n]s",&name);
                u32 z = check_name(&L1,name);
                if(z!=0){
                    do{
                        printf("\nBook name already exists, please enter another book name : ");
                        scanf(" %[^\n]s",&name);
                    }while(check_name(&L1,name));
                }
                printf("\nEnter a book author : ");
                scanf(" %[^\n]s",&author);
                printf("\nEnter a book ID : ");
                scanf("%d",&id);
                u32 y = check_id(&L1,id);
                if(y!=0){
                    do{
                        printf("\nID already exists, please enter another ID");
                        scanf("%d",&id);
                    }while(check_id(&L1,id));
                }
                printf("\nEnter a book price :");
                scanf("%f",&price);
                u32 size = list_size(&L1);
                addbook(&L1,name,author,price,id,size);
                break;
            case 2 :
                printf("\nWould you like to delete the book by \n1)name \n2)ID?\n");
                scanf("%d",&choice2);
                if(choice2 == 1){
                    printf("Enter the name of the book to be deleted : ");
                    scanf(" %[^\n]s",&delete_name);
                    //size = list_size(&L1);
                    delete_book_by_name(&L1,delete_name);
                }
                else if(choice2 ==2){
                printf("Enter the ID of the book to be deleted : ");
                scanf("%d",&delete_id);
                //size = list_size(&L1);
                delete_book_by_id(&L1,delete_id);
                }
                else{
                    printf("\nInvalid input!");
                }
                break;
            case 3 :
                printlist(&L1);
                break;
            case 4 :
                author_works(&L1);
                break;
            case 5 :
                printf("\nExiting program..\n");
                exit(0);
                break;
            default :
                printf("\nInvalid input");
                break;

        }

    }while(choice!=5);

}
