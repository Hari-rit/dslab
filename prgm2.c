#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node*head=NULL;
void display(){
        if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
        struct node*temp=head;
        while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void ins_beg(int item){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=head;
    head=newnode;
}
void ins_end(int item){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=item;
    if (head==NULL){
        head=newnode;
        return;
    }
    struct node*temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void ins_pos(int item,int pos){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    if (head == NULL) {
        printf("\nList is empty\n");
        free(newnode);
        return;
    }

    if (pos == 1) {
        ins_beg(item);
        return;
    }
    struct node* temp = head;
    while(pos!=2){
        temp=temp->next;
        pos--;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void del_beg(){
    struct node*temp=head;
    if(head==NULL){
        printf("\nList is empty\n");
        return;
    }
	if(head!=NULL)
    		head=temp->next;
	printf("%d is deleted",temp->data);
    	free(temp);
}
void del_end(){
    struct node*temp=head;
    struct node*prev=NULL;
    if(head==NULL){
        printf("\nList is empty\n");
        return;
    }
     if (temp->next==NULL) {
        printf("%d is deleted",temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("%d is deleted",temp->data);
    free(temp);
}
void del_pos(int pos) {
    struct node*temp=head;
    struct node*prev=NULL;
    if (pos < 1) {
        printf("\nInvalid position\n");
        return;
    }
    if (pos == 1) {
        del_beg();
        return;
    }
      while(pos!=1)
        {
            prev=temp;
            temp=temp->next;
            pos--;
        }
        prev->next=temp->next;
        free(temp);
        temp=NULL;
        printf("Node deleted.\n");
        return;
	if(head!=NULL)
        	prev->next = temp->next;
	free(temp);
}
void main(){
    int ch;
    while (1)
    {
        printf("\n1.INSERT AT BEG\n2.INSTERT AT END\n3.INSERT AT POS\n4.DELETE AT BEG\n5.DELETE AT END\n6.DELETE AT POS\n7.DISPLAY\n8.EXIT\n\nENTER YOUR CHOICE:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            int item;
            printf("\nEnter the element to be inserted");
            scanf("%d",&item);
            ins_beg(item);
            break;

            case 2:
            int item2;
            printf("\nEnter the element to be inserted");
            scanf("%d",&item2);
            ins_end(item2);
            break;

            case 3:
            int item3,pos2;
            printf("\nEnter the element to be inserted");
            scanf("%d",&item3);
            printf("\nEnter the position of element to be inserted");
            scanf("%d",&pos2);
            ins_pos(item3,pos2);
            break;

            case 4:
            del_beg();
            break;

            case 5:
            del_end();
            break;

            case 6:
            int pos;
            printf("\nEnter the element pos of element to be deleted:");
            scanf("%d",&pos);
            del_pos(pos);
            break;
            
            case 7:
            display();
            break;

            case 8:
            printf("\nExiting....");
            exit(0);
            break;

        default:
            printf("\nInvalid choice!");
            break;
        }
    }
}
