#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_back(struct node **head,int data) {
    if(*head == NULL) {
        (*head) = (struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = *head;
    while(tmp->next != NULL) {
        tmp=tmp->next;
    }
    tmp->next=(struct node *)malloc(sizeof(struct node));
    tmp=tmp->next;
    tmp->data=data;
    tmp->next=NULL;
}
void insert_front(struct node **head,int data) {
    if(*head == NULL) {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=(*head);
    (*head)=tmp;
}
void delete_last(struct node **head) {
    if(*head == NULL) {
        return;
    }
    if( (*head)->next == NULL ) {
        struct node *tmp = *head;
        free(tmp);
        *head = NULL;
        return;
    }
    struct node *last = *head;
    struct node *prev_last;
    while( last->next != NULL ) {
        prev_last = last;
        last = last->next;
    }
    prev_last->next=NULL;
    free(last);
}
void delete_front(struct node **head) {
    if(*head == NULL) {
        return;
    }
    struct node *tmp = *head;
    if(tmp->next == NULL) {
        *head=NULL;
        free(tmp);
        return;
    }
    (*head) = tmp->next;
    free(tmp);
}
void display(struct node **head) {
    if( *head == NULL )
        return;
    struct node *tmp = *head;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
void nth_node(struct node **head,int n) {
    if(*head == NULL) {
        return;
    }
    int cnt = 0;
    struct node *tmp = *head;
    while(tmp != NULL) {
        cnt++;
        tmp=tmp->next;
    }
    int len = (cnt - n + 1);
    len--;
    tmp=(*head);
    while(len > 0) {
        len--;
        tmp=tmp->next;
    }
    printf("%dth node from end is %d\n",n,tmp->data);
}
int main() {
    struct node *head = NULL;

    insert_back(&head,18);
    insert_back(&head,12);
    insert_back(&head,17);
    insert_back(&head,20);
    insert_back(&head,25);
    insert_back(&head,28);
    insert_back(&head,30);

    display(&head);
    nth_node(&head,4);
    nth_node(&head,5);

    return 0;
}
