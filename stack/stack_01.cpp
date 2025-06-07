/*

[ 문제 1 ] 스택 ADT를 배열로 구현하고 테스트하는 프로그램을 작성하시오.
◦ 원소 : 영문자
◦ 다음 연산을 지원해야 함.
- push(stack, ‘c’) : stack의 top에 원소를 추가한다. stack이 이미 꽉 차있으면 해당 데이터는
스택에 저장하지 않고 “Stack FULL”을 출력한다.
- pop(stack) : stack의 top에 있는 원소를 반환하고 stack에서 제거한다. stack이 비어 있으면
“Stack Empty”를 출력한다.
- peek(stack) : stack의 top에 있는 원소를 화면에 출력한다. stack은 변화하지 않는다.
stack이 비어 있으면 “Stack Empty”를 출력한다.
- duplicate(stack) : stack의 top에 있는 원소를 pop해서 두 번 push한다. stack이 이미 꽉
차 있으면 “Stack FULL”을 출력한다.
- upRotate(stack, n) : stack의 맨 위 n개의 원소를 회전시킨다. 예를 들어 n이 3이고
stack의 top에서부터 elem1, elem2, elem3, .... 이 저장되어 있으면
원소를 하나씩 위쪽으로 이동시킨다. 맨 위쪽(top)의 std1은 n-1번
아래쪽으로 이동해서 스택의 내용은 elem2, elem3, elem1, ... 이 된다.
- downRotate(stack, n) : stack의 맨 위 n개의 원소를 회전시킨다. 예를 들어 n이 3이고
stack의 top에서부터 elem1, elem2, elem3, .... 이 저장되어 있으면
원소를 하나씩 아래쪽으로 이동시킨다. top에서부터 n번째의
원소를 top으로 이동해서 스택의 내용은 elem3, elem1, elem2, ...
이 된다.
- print(stack) : stack의 모든 원소를 top에서부터 순서대로 공간없이 출력한다.
◦ 입력에 대한 설명 (아래 입출력 예시 참조)
- 한 라인에 하나의 연산이 입력되고, 라인에는 연산의 종류와 그에 필요한 인자가 주어진다.
- 연산의 종류 : 각 연산 이름은 POP, PUSH , PEEK, DUP, UpR, DownR, PRINT로 주어진다.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct
{
    char *data;
    int top;
    int capacity;
} Stack;

void init(Stack *s, int size)
{
    s->data = (char *)malloc(sizeof(char) * size);
    s->top = -1;
    s->capacity = size;
}

void push(Stack *s, char c)
{
    if (s->top == s->capacity - 1)
    {
        printf("Stack FULL\n");
        return;
    }
    s->data[++(s->top)] = c;
}

void pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Empty\n");
        return;
    }
    s->top--;
}

void peek(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n", s->data[s->top]);
}

void duplicate(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Empty\n");
        return;
    }
    if (s->top >= s->capacity - 1)
    {
        printf("Stack FULL\n");
        return;
    }
    char topVal = s->data[s->top];
    s->data[++(s->top)] = topVal;
}

void upRotate(Stack *s, int n)
{
    if (n <= 0 || s->top + 1 < n)
        return;
    int top = s->top;
    char temp = s->data[top];
    for (int i = 0; i < n - 1; i++)
    {
        s->data[top - i] = s->data[top - i - 1];
    }
    s->data[top - n + 1] = temp;
}

void downRotate(Stack *s, int n)
{
    if (n <= 0 || s->top + 1 < n)
        return;
    int top = s->top;
    char temp = s->data[top - n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        s->data[top - n + 1 + i] = s->data[top - n + 2 + i];
    }
    s->data[top] = temp;
}

void print(Stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c", s->data[i]);
    }
    printf("\n");
}

int main()
{
    int size, ops;
    scanf("%d", &size);
    scanf("%d", &ops);

    Stack s;
    init(&s, size);

    char command[20];
    for (int i = 0; i < ops; i++)
    {
        scanf("%s", command);

        if (strcmp(command, "PUSH") == 0)
        {
            char c;
            scanf(" %c", &c);
            push(&s, c);
        }
        else if (strcmp(command, "POP") == 0)
        {
            pop(&s);
        }
        else if (strcmp(command, "PEEK") == 0)
        {
            peek(&s);
        }
        else if (strcmp(command, "DUP") == 0)
        {
            duplicate(&s);
        }
        else if (strcmp(command, "UpR") == 0)
        {
            int n;
            scanf("%d", &n);
            upRotate(&s, n);
        }
        else if (strcmp(command, "DownR") == 0)
        {
            int n;
            scanf("%d", &n);
            downRotate(&s, n);
        }
        else if (strcmp(command, "PRINT") == 0)
        {
            print(&s);
        }
    }

    free(s.data);
    return 0;
}
