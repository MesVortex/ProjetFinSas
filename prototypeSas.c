#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int G;

typedef struct{
    char nom[20];
    float note;
} etudiant;
etudiant classe[G];

void add();
void modify();

int main(){
    add();
    modify();
    return 0;
}

void add(){
        
    printf("Entrez le nom de l'étudiant:");
    scanf("%s", classe[G].nom);
    printf("Entrez la note de l'étudiant:");
    scanf("%f", &classe[G].note);
    printf("Étudiant ajouté avec succès!\n");
    G++;
}

void modify(){
    etudiant search;
    int search_res;
    float new_note;
    printf("donner le nom d\'etudiant:");
    scanf("%s", search.nom);
    printf("donner une nouveau note:")
    scanf("%f", &new_note);
    for (int i = 0; i < G; i++){
        searhc_res = strcasecmp(classe[i].nom,search.nom);
        if (search_res == 0)
        {
            classe[i].note = new_note;
            printf("modification reussie!!");
            break;
        }
        else 
            cmpt++;
    }
    if (cmpt == i)
         printf("il n'y a pas d\'etudiant avec ce nom");
}