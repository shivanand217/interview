#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_back(struct node **head, int data) {
    if(*head == NULL) {
        *head=(struct node *)malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    struct node *tmp = *head;
    while(tmp->next != NULL) {
        tmp=tmp->next;
    }
    tmp->next = (struct node *)malloc(sizeof(struct node));
    tmp = tmp->next;
    tmp->data=data;
    tmp->next=NULL;
    return;
}
void insert_front(struct node **head, int data) {
    if(*head == NULL) {
        *head=(struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next = (*head);
    *head = tmp;
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
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
void nth_node(struct node **head, int n) {
    if(*head == NULL) {
       printf("list is empty\n");
       return;
    }
    int cnt = 0;
    struct node *tmp = *head;
    while(tmp != NULL) {
        cnt++;
        if(cnt == n) {
            printf("%dth node =  %d\n", n , tmp->data);
            break;
        }
        tmp=tmp->next;
    }
    if(tmp == NULL) {
        printf("%dth node does not exist in this linked list\n", n);
    }
}
int main() {
    struct node *head = NULL;
    insert_front(&head,12);
    insert_front(&head,14);
    insert_front(&head,16);
    insert_front(&head,20);

    nth_node(&head,3);
    display(&head);

    delete_last(&head);
    display(&head);

    delete_front(&head);
    display(&head);

    return 0;
}
