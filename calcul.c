#include <stdio.h>
#include <stdlib.h>

float add(float a,float b);
float multiply(float a,float b);
float divise(float a,float b);
float subs(float a,float b);

int main(){
    float a,b,i;
    char c;
    printf("donner le 1er nbr:");
    scanf("%f", &a);
    printf("donner le 2eme nbr:");
    scanf("%f", &b);
    printf("donner l\'operation:\n");
    scanf("%s", &c);
    again:
        switch(c){
            case '+': i=add(a,b);
                break;
            case '-': i=subs(a,b);
                break;
            case '*': i=multiply(a,b);
                break;
            case '/': i=divise(a,b);
                break;
            default : 
                printf("svp donne une operation valid! (exp:'+' '-' '*' '/')");
                scanf("%s", &c);
                goto again;
    }
    printf("le resultat est: %.2f \n",i);
    return 0;
}
float add(float a,float b){
        return (a+b);
}
float multiply(float a,float b){
        return (a*b);
}
float subs(float a,float b){
        return (a-b);
}
float divise(float a,float b){
        return (a/b);
}
