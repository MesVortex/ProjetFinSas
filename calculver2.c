#include <stdio.h>
#include <stdlib.h>

float divise(float a,float b);
float power(float a,float b);

int main(){
    float a,b,i;
    char c;
    do{
        printf("donner l\'operation (exp:'+' '-' '*' '/' '^') ou (press x to exit):");
        scanf("%s", &c);
        if(c == 'x')
            exit(0);
        printf("donner le 1er nbr:");
        scanf("%f", &a);
        printf("donner le 2eme nbr:");
        scanf("%f", &b);
        again:
            switch(c){
                case '+': i = (a+b);
                    break;
                case '-': i = (a-b);
                    break;
                case '*': i = (a*b);
                    break;
                case '/': i = divise(a,b);
                    break;
                case '^': i = power(a,b);
                    break;
                case 'x': exit(0);
                default :
                    printf("svp donne une operation valid! (exp:'+' '-' '*' '/' '^') ou (press x o exit):");
                    scanf("%s", &c);
                    goto again;
            }
        printf("le resultat est: %.1f \n",i);
    }while(c != 'x');
    return 0;
}


float divise(float a,float b){
    while (b==0){
        printf("impossible de diviser par 0!!\n donner une autre valeur:");
        scanf("%f", &b);
    }
    return (a/b);
}
float power(float a,float b){
    int p=1;
    for (int i = 0; i < b; i++){
        p = p * a;
    }
    return p;
}