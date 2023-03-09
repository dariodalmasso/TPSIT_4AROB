#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define L_STR 21
#define TIME_SLICE 30
#define MIN_TIME 1
#define MAX_TIME 250

typedef char* String;
typedef struct node {
    int pid;
    String stato;
    int time;
    struct node* next;
} Node;

void sleep(int millsec) {
    clock_t start = clock();
    while(start + millsec < clock());
}

int isEmpty(Node* list) {
    return list == NULL;
}

void enqueue(Node** head, Node** tail, Node* el) {
    if(isEmpty(*head))
        *head = el;
    else
        (*tail)->next = el;
    *tail = el;
}

Node* dequeue(Node** head, Node** tail) {
    Node* ret = *head;
    if(isEmpty(*head))
        return NULL;
    *head = ret->next;
    if(isEmpty(*head))
        *tail = NULL;
    return ret;
}

void setNL(Node** head, Node** tail) {
    bool cont = true;
    int cPid = 0;

    while(cont) {
        int risp;
        printf("vuoi continuare? (0 se no) ");
        scanf("%d", &risp);
        if(risp == 0) {
            cont = false;
            continue;
        }

        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->stato = (String) malloc(sizeof(char) * L_STR);
        int tempo;
        do {
            printf("tempo del processo con pid = %d: (da %d a %d) ", cPid, MIN_TIME, MAX_TIME);
            scanf("%d", &tempo);
        } while (tempo < MIN_TIME || tempo > MAX_TIME);
        newNode->pid = cPid ++;
        newNode->stato = "NL";
        newNode->time = tempo;
        newNode->next = NULL;

        enqueue(head, tail, newNode);
    }
}

void printQueue(Node* queue) {
    if(isEmpty(queue))
        return;
    printf("%d %s %d   ", queue->pid, queue->stato, queue->time);
    if(queue->next != NULL)
        printQueue(queue->next);
}

void freeQueue(Node* queue) {
    if(queue->next != NULL)
        freeQueue(queue->next);
    free(queue);
}

int main() {
    Node* headNL = NULL;
    Node* tailNL = NULL;
    Node* headRL = NULL;
    Node* tailRL = NULL;
    Node* headTL = NULL;
    Node* tailTL = NULL;

    setNL(&headNL, &tailNL);
    printf("ok\n");
    printQueue(headNL);
    printf("ok\n");

    while(!isEmpty(headNL)) {
        Node* t = dequeue(&headNL, &tailNL);
        //t->stato = "RL";
        enqueue(&headRL, &tailRL, t);
    }

    printQueue(headRL);
    printf("vdsv\n");
    while(!isEmpty(headRL)) {
        Node* proc = dequeue(&headRL, &tailRL);
        proc->time -= TIME_SLICE;
        if(proc->time < 0) {
            sleep(TIME_SLICE + proc->time);
            proc->time = 0;
        } else
            sleep(TIME_SLICE);

        if(proc->time <= 0) {
            proc->stato = "TL";
            enqueue(&headTL, &tailTL, proc);
        } else
            enqueue(&headRL, &tailRL, proc);
    }

    printf("\nNL: ");
    printQueue(headNL);
    printf("\nRL: ");
    printQueue(headRL);
    printf("\nTL: ");
    printQueue(headTL);

    freeQueue(headTL);
    tailTL = NULL;
    return 0;
}