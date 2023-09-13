#include <stdio.h>
#include <stdlib.h>

float add(float a,float b);
float multiply(float a,float b);
float divise(float a,float b);
float subs(float a,float b);

int main(){
    float a,b;
    char c;
    printf("donner le 1er nbr:");
    scanf("%f", &a);
    printf("donner le 2eme nbr:");
    scanf("%f", &b);
    printf("donner l\'operation:");
    scanf("%c", c);
    again:
        switch(c){
            case '+': add(a,b);
                break;
            case '-': subs(a,b);
                break;
            case '*': multiply(a,b);
                break;
            case '/': divise(a,b);
                break;
            default : printf("svp donne une operation valid! (exp:'+' '-' '*' '/')");   
    }
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