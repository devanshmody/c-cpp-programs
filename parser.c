#include <stdio.h>
#include <string.h>

char input[10];
int i=0;

int identifier(char);
void S();
void C();
void Cdash();
void L();
void E();
void Edash();
void Sdash();
void invalid();

int identifier(char c)
{
    if(c>='a' && c<='z')
        return 1;
    else
        return 0;
}

void S()
{
    if(identifier((input[0]))) {
        i++;
        printf("S->iCtLS'\n");
        C();
    } else
        invalid();
}

void C()
{
    if(identifier(input[i])) {
        i++;
        printf("C->dC'\n");
        Cdash();
    } else
        invalid();
}

void Cdash()
{
    if(input[i]=='&') {
        i++;
        printf("C'->&CC'\n");
        C();
    }
    else {
        i++;
        if(identifier(input[i])) {
            //i++;
            printf("C'->epsilon\n");
            L();
        } else
            invalid();
    }
}

void L()
{
    if(identifier(input[i])) {
        i++;
        printf("L->d\n");
        if(input[i]=='=') {
            printf("L->d=E\n");
            i++;
            E();
        }
    } else
        invalid();
}

void E()
{
    if(identifier(input[i])) {
        i++;
        printf("E->dE'\n");
        Edash();
    } else
        invalid();
}

void Edash()
{
    if(input[i]=='+'){
        i++;
        printf("E'->+EE'\n");
        E();
    } else if(input[i]=='-'){
        i++;
        printf("E'->-EE'\n");
        E();
    } else {
        i++;
        if(identifier(input[i])) {
            printf("E'->epsilon\n");
            Sdash();
        } else if(input[i]=='\0')
            Sdash();
        else
            invalid();
    }
}

void Sdash()
{
    if(input[i]=='\0') {
        printf("S'->epsilon\n");
        printf("Parsing complete.\n");
    } else if(identifier(input[i])) {
        i++;
        printf("S'->eL\n");
        L();
    } else
        invalid();
}

void invalid()
{
    printf("Invalid string!\n\n");
    return;
}

int main()
{

    printf("Enter string\n");
    gets(input);
    S();
    return 0;
}
