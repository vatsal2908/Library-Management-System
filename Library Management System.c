#include<stdlib.h>
#include <stdio.h>

struct Node {
  char* Book_name;
  char* Author_name;
  int Pages;
  int Price;
  int Id;
  struct Node* next;
  struct Node* Prev;
};
void reset () {
  printf("\033[0m");
}



struct Node* ADD_BOOK(struct Node* ptr,char B_name[],char A_name[],int PAGES, int PRICE,int ID){
    struct Node* newnode,*temp;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->Book_name=B_name;
    newnode->Author_name=A_name;
    newnode->Pages=PAGES;
    newnode->Price=PRICE;
    newnode->Id=ID;
    temp = ptr;
    if(ptr==NULL){
        newnode->next=NULL;
    return newnode;
    }
    else{
    while(temp->next!=NULL){
        temp=temp->next;
    }
      temp->next=newnode;
      newnode->Prev=temp;
      newnode->next=NULL;
      return ptr;
    }
    
}

void VIEW_BOOKS(struct Node* ptr){
    struct Node* t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t=ptr->next;
    if(t==NULL){
        printf("\033[1;33m");
        printf("\n\t\t\t\t\t\t\t\t\t      No Books are purches");
        printf("\033[0;37m");
    }
    else{
       
       
    while(t!=NULL){
       
        printf("\n\t\t\t\t\t\t\t\t      Book-Name : %s",t->Book_name);
        printf("\n\t\t\t\t\t\t\t\t      Author-Name : %s",t->Author_name);
        printf("\n\t\t\t\t\t\t\t\t      Pages : %d",t->Pages);
        printf("\n\t\t\t\t\t\t\t\t      Price : %d",t->Price);
        printf("\n\t\t\t\t\t\t\t\t      Id : %d",t->Id);
        
        t=t->next;
    }
    }
}

_Bool DELETE_FIRST_BOOK(struct Node* ptr,int ID){
    if(ptr->Id==ID){
        return 1;
    }
    else{
        return 0;
    }
}
_Bool DELETE_LAST_BOOK(struct Node* ptr,int ID){
    struct Node* t;
    t=ptr;
    while(t->next!=NULL){
        t=t->next;
    }
    if(t->Id==ID){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* DELETE_BOOK(struct Node* ptr){
    struct Node* t,*temp1,*temp2,*t1;
    int ID;
    t=ptr;
    char ans[10];
    printf("\t\t\t\t\t\t\t\t      Enter the Id of Book : ");
    scanf("%d",&ID);
    if(DELETE_FIRST_BOOK(ptr,ID)){
        printf("\033[0;31m");
        printf("\n\t\t\t\t\t\t\t\t      %s Book has been Deleted....\n",ptr->Book_name);
        printf("\033[0;37m");
        ptr=ptr->next;
        return ptr;
    }
    else if(DELETE_LAST_BOOK(ptr,ID)){
        t=ptr;
        while(t->next!=NULL){
            t=t->next;
        }
         printf("\033[0;31m");
        printf("\n\t\t\t\t\t\t\t\t      %s Book has been Deleted....\n",t->Book_name);
        printf("\033[0;37m");
        t1=t->Prev;
        t1->next=NULL;
        return ptr;
    }
    else {
        t=ptr;
        while(t->Id!=ID){
            t=t->next;
        }
         printf("\033[0;31m");
        printf("\n\t\t\t\t\t\t\t\t      %s Book has been Deleted....\n",t->Book_name);
        printf("\033[0;37m");
        temp1=t->Prev;
        temp2=t->next;
        temp1->next=t->next;
        temp2->Prev=temp1;
        return ptr;
        
    }
}
struct Node* EDIT_BOOK(struct Node* ptr){
    struct Node* t;
    t=ptr;
    int ans;
    int ID,choice;
    printf("\t\t\t\t\t\t\t\t      Enter the Id of the Book you want to Edit : ");
    scanf("%d",&ID);
    do{
    while(t->Id!=ID){
        t=t->next;
    }
    printf("\t\t\t\t\t\t\t\t      What you want to Edit ? \n");
    printf("\t\t\t\t\t\t\t\t      1.BOOK-NAME\n");
    printf("\t\t\t\t\t\t\t\t      2.AUTHOR-NAME\n");
    printf("\t\t\t\t\t\t\t\t      3.PRICE\n");
    printf("\t\t\t\t\t\t\t\t      Enter your choice : ");
    scanf("%d",&choice);
    switch(choice){
        
        case 1:
        printf("\t\t\t\t\t\t\t\t      Enter Rename of Book : ");
        scanf("%s",t->Book_name);
        break;
        
        case 2:
        printf("\t\t\t\t\t\t\t\t      Enter Rename of Autor : ");
        scanf("%s",t->Author_name);
        break;
        
        case 3:
        printf("\t\t\t\t\t\t\t\t      Enter Price of Book : ");
        scanf("%d",&t->Price);
        break;
        
        default :
        printf("\t\t\t\t\t\t\t\t      you don't Edit Other Information ...Please select given Information for Editing : ");
        break;
    }
    printf("\t\t\t\t\t\t\t\t      Do you want to continue to Editing (Type 1 for yes or 0 for no) ? : ");
    scanf("%d",&ans);
    
    }while(ans!=0);
    return ptr;
    
    
}

void SEARCH_BOOK(struct Node* ptr,int ID){
    struct Node* t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t=ptr;
    
    while(ID!=t->Id){
        t=t->next;
    }
    
        printf("\n\t\t\t\t\t\t\t\t      Book-Name : %s",t->Book_name);
        printf("\n\t\t\t\t\t\t\t\t      Author-Name : %s",t->Author_name);
        printf("\n\t\t\t\t\t\t\t\t      Pages : %d",t->Pages);
        printf("\n\t\t\t\t\t\t\t\t      Price : %d",t->Price);
        printf("\n\t\t\t\t\t\t\t\t      Id : %d",t->Id);
    
}

int main()
{
  int n;
  struct Node* Library,*newnode;
  Library=(struct Node*)malloc(sizeof(struct Node));
  printf("\n\n");
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t      MAIN MENU:");
        printf("\n\t\t\t\t\t\t\t\t     1.ADD BOOKS");
        printf("\n\t\t\t\t\t\t\t\t     2.DELETE BOOKS");
        printf("\n\t\t\t\t\t\t\t\t     3.VIEW BOOKS");
        printf("\n\t\t\t\t\t\t\t\t     4.EDIT BOOKS");
        printf("\n\t\t\t\t\t\t\t\t     5.SEARCH BOOK");
        printf("\n\t\t\t\t\t\t\t\t     6.EXIT \n");
        
    
    int choice;
    do{
        
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\033[0;33m");
        printf("\n\t\t\t\t\t\t\t\t      Enter your choice: ");
        scanf("%d",&choice);
        printf("\033[0;37m");
        switch(choice){
            case 1:{
                //call the function to add books
                newnode=(struct Node*)malloc(sizeof(struct Node));
                newnode->Book_name=(char*)malloc(sizeof(char)*30);
                newnode->Author_name=(char*)malloc(sizeof(char)*30);
                printf("\n\t\t\t\t\t\t\t\t      Enter Book name : ");
                scanf("%s",newnode->Book_name);
                printf("\n\t\t\t\t\t\t\t\t      Enter Author name : ");
                scanf("%s",newnode->Author_name);
                printf("\n\t\t\t\t\t\t\t\t      Enter Pages : ");
                scanf("%d",&newnode->Pages);
                printf("\n\t\t\t\t\t\t\t\t      Enter Price : ");
                scanf("%d",&newnode->Price);
                printf("\n\t\t\t\t\t\t\t\t      Enter Id : ");
                scanf("%d",&newnode->Id);
                Library=ADD_BOOK(Library,newnode->Book_name,newnode->Author_name,newnode->Pages,newnode->Price,newnode->Id);
                
                break;
            }
            case 2:{
                //call the function to delete books
                Library=DELETE_BOOK(Library);
                
                break;
            }
            case 3:{
                VIEW_BOOKS(Library);
                break;
            }
            case 4:{
                //call the function to edit books
                Library=EDIT_BOOK(Library);
                break;
            }
            case 5:{
                printf("\t\t\t\t\t\t\t      Enter the Id of Book you want to Search : ");
                scanf("%d",&n);
                SEARCH_BOOK(Library,n);
                break;
            }
            case 6:{
                exit(1);
            }
            default:{
                printf("\n\t\t\t\t\t\t\t\t      ...Invalid Option!...\n");
                printf("\n\t\t\t\t\t\t\t\t      Press any key to try again: ");
               
            }
        }
    }while(choice!=6);


    

    return 0;
}
