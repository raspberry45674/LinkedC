#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int count = 0;
#define UP 1
#define DOWN 2
void staticCount(int set)
{
    if (set == UP)
    {
        ++count;
    }
    if (DOWN == set)
    {
        --count;
    }
}
typedef struct ListNode
{
    char data[20];
    struct ListNode *link;
} listNode;

typedef struct
{
    listNode *head;
} linkedList_h;

linkedList_h *createLinkedList_h(void)
{
    linkedList_h *L;
    L = (linkedList_h *)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

void freeLinkedList_h(linkedList_h *L)
{
    listNode *p;
    while (L->head != NULL)
    {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

void insertFirstNode(linkedList_h *L, char *str)
{
    listNode *p = (listNode *)malloc(sizeof(listNode));
    strcpy(p->data, str);
    p->link = NULL;
    L->head = p;
    staticCount(UP);
}
void insertLastNode(linkedList_h *L, char *str)
{
    listNode *p = (listNode *)malloc(sizeof(listNode));
    strcpy(p->data, str);
    p->link = NULL;
    linkedList_h *start = L;

    while (L->head != NULL)
    {
        L->head = L->head->link;
    }
    L->head = p;
    L = start;
    staticCount(UP);
}

//strcpy(목표저장소, "내용"); 스트링카피 메소드
void printList(linkedList_h *L)
{
    linkedList_h *start = L;

    while (L->head != NULL)
    {
        printf("노드 값 : %s\n", L->head->data);
        L->head = L->head->link;
    }
    L = start;
}
listNode *searchNode(linkedList_h *L, char *str)
{
    listNode *p = NULL;
    linkedList_h *start = L;
    while (L->head != NULL)
    {
        if (strcmp(L->head->data, str))
        {
            L->head = L->head->link;
        }
        else
        {
            p = L->head;
            break;
        }
    }
    L = start;
    return p;
}
void insertMiddleNode(linkedList_h * L, listNode * node, char * str) {
    linkedList_h * start = L;
    listNode *createNode = (listNode *)malloc(sizeof(listNode));
    listNode * p;
    char * b = "banana";
    while (L->head != NULL)
    {
        if (strcmp(L->head->data, b))
        {
            createNode->link =L->head->link;
            L->head->link = createNode;
            strcpy(createNode->data, str);
            break;
        }
        else
        {
            L->head = L->head->link;
        }
    }
    L = start;
    staticCount(UP);
}
void deleteNode(linkedList_h *L, listNode *node)
{
    listNode *p = NULL;
    listNode *save = node->link;
 
    linkedList_h *start = L;

    while (L->head != NULL)
    {
        if ((L->head->link) == node)
        {
            p = L->head->link;
            free(p);
            L->head->link = save;
            
            break;
        } 
        else if ((L->head) == node)
        {
            p = L->head;
            free(p);
            L->head = NULL;
            break;
        }
        else
        {
            L->head = L->head->link;
        }
    }
    staticCount(DOWN);
    L = start;
}
int main()
{
    linkedList_h *L;
    listNode *p;
    L = createLinkedList_h();
    printf("공백리스트 생성\n");
    printList(L);
    printf("리스트에 삽입\n");
    insertFirstNode(L, "apple");
    printList(L);
    printf("마지막에 삽입\n");
    insertLastNode(L, "banana");
    printList(L);
    printf("마지막에 삽입\n");
    insertLastNode(L, "grape");
    printList(L);
    printf("마지막에 삽입\n");
    insertLastNode(L, "Galaxy");
    printList(L);
    // printf("마지막에 삭제\n");
    // deleteLastNode(L, &count);
    // printList(L,&count);

    printf("리스트에서 \"banana \" 찾기 \n");
    p = searchNode(L, "banana");
    if (p == NULL)
        printf("찾는 데이터가 없습니다.\n");
    else
    {
        printf("%s 를 찾았습니다.\n", p->data);
    }
    printf("banana 뒤에 orange 삽입하기\n");
    insertMiddleNode(L, p, "orange");
    printList(L);

    printf("banana 삭제하기\n");
    p = searchNode(L, "banana");
    deleteNode(L, p);
    printList(L);

    printf("공간 해제\n");
    freeLinkedList_h(L);
    printList(L);
    return 0;
}