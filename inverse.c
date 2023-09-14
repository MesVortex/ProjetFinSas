#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i;
    printf("donner la taille du nbr\n (exp: 1234 est de taille 4)");
    scanf("%d", &n);
    char nbr[n],inver[n];
    printf("donner votre nbr:");
    scanf("%s", nbr);
    for(i=0;i<n;i++){
        inver[(n-1)-i]=nbr[i];
    }
    for(i=0;i<n;i++){
        printf("voila votre nbr inverse: %s\n",inver);
    return 0;
    }
}