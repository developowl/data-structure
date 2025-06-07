/*

[ 문제 2 ] 스택 응용으로, 키보드로부터 입력된 한 라인의 수식 문장 내 괄호 쌍의 대칭성을
검사하는 프로그램을 작성하세요. 괄호 쌍은 { }, [ ] , ( ), 세 종류가 있다.
※ 주의: 한 개의 수식 문장은 1000개를 넘지 않는 문자로 이루어진다. 수식 문장은 공백문자를
포함할 수 있다. 검사 결과 대칭이 아니면 ‘Wrong_N’을, 대칭이면 ‘OK_N’를 출력한다.
여기서 N은 문장 내 괄호의 개수다.

*/

#include <stdio.h>

int main()
{
    char line[1005];
    int len = 0;

    // 한 줄 입력받기 (개행 전까지)
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n')
    {
        line[len++] = ch;
    }

    // 널 문자로 문자열 종료
    line[len] = '\0';

    // 1) 괄호 개수 세기
    int bracketCount = 0;
    for (int i = 0; i < len; i++)
    {
        char c = line[i];
        if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
        {
            bracketCount++;
        }
    }

    // 2) 스택 이용하여 대칭성 검사
    char stack[1000];
    int top = -1;
    int ok = 1; // 1==OK, 0==Wrong

    for (int i = 0; i < len; i++)
    {
        char c = line[i];
        if (c == '(' || c == '[' || c == '{')
        {
            // 여는 괄호 푸시
            if (top < 999)
            {
                stack[++top] = c;
            }
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            // 닫는 괄호
            if (top < 0)
            {
                ok = 0; // 스택이 비어있는데 닫는 괄호 등장
                break;
            }
            char open = stack[top--];
            if (!((open == '(' && c == ')') || (open == '[' && c == ']') || (open == '{' && c == '}')))
            {
                ok = 0; // 괄호 쌍이 맞지 않음
                break;
            }
        }
    }

    // 스택에 남은 괄호가 있다면 오류
    if (ok && top != -1)
    {
        ok = 0;
    }

    // 3) 결과 출력
    if (ok)
    {
        printf("OK_%d\n", bracketCount);
    }
    else
    {
        printf("Wrong_%d\n", bracketCount);
    }

    return 0;
}
