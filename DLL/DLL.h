#include "../STD_TYPES_H.h"
#ifndef DLL
#define DLL

////////Data type Declaration

typedef struct book{
    u8 book_name[50];
    u8 book_author[50];
    f32 book_price;
    u32 book_id;
    struct node*next;
    struct node*prev;
};

typedef struct List{
    struct book*head;
    u32 size;
};
struct List L1;
u32 choice,choice2;
u8 o_pass[50],pass[50];
u8 name[50],author[50],delete_name[50];
f32 price;
u32 id,delete_id;


/////Function Declaration
void main_menu();
void createlist(struct List* pBook);
u32 list_size(struct List* pList);
void addbook(struct List* pList, u8 name[], u8 author[], f32 price, u32 id ,u32 pos);
void delete_book_by_name(struct List* pList, u8 name[]);
void delete_book_by_id(struct List* pList,u32 id);
u32 check_id(struct List* pList,u32 id);
u32 check_name(struct List* pList,u8 name[]);
void author_works(struct List*pList);
void sortlist(struct List*pList);
void printlist(struct List*pList);
void app();
#endif // DLL
