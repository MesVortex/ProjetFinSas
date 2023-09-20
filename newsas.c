#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int jour;
    int mois;
    int annee;
}deadline;
typedef struct{
    int ID;
    char titre[50];
    char descri[150];
    char status[10];
    deadline de_li;
}ToDo;

int G_ID = 1001;
ToDo task[200];

int add(int i);
int add_more(int indice);
void show(int a);
//void modify();

int main(){
    int i;
    i = add(i);
    show(i-1);
    
    return 0;
}

void show(int a){
    printf("Identifiant (ID): %d\n", task[a].ID);
    printf("Titre de tache: %s\n", task[a].titre);
    printf("Description: %s\n", task[a].descri);
    printf("Deadline: %d/%d/%d\n", task[a].de_li.jour, task[a].de_li.mois, task[a].de_li.annee);
    printf("statut: %s\n", task[a].status);
}

int add(int i){
    char yes_no;
    printf("Entrez le nom de la tache:");
    scanf("%s", task[i].titre);

    printf("voulez vous ajouter une decription? [y/n] :");
    scanf("%s", &yes_no);

    if (yes_no == 'y'){
        printf("donner une decription (150 charactere max):");
        scanf(" %[^\n]", task[i].descri);
    }

    printf("ajouter une deadline (JJ/MM/AA):");
    scanf("%d/%d/%d", &task[i].de_li.jour, &task[i].de_li.mois, &task[i].de_li.annee);
    
    printf("entrer le statut de votre tache (todo, doing, done):");
    scanf("%s", task[i].status);

    task[i].ID = G_ID;
    printf("tache ajouté avec succès!\n (ID de ce tache: %d)\n", G_ID);
    G_ID++;
    i++;
    return i;
}

int add_more(int indice){
    int a,b;
    printf("combien de tache voulez vous ajoutez? :");
    scanf("%d", &a);
    for (int i = indice; i < indice + a; i++){
        b = add(i);
    }
    return b;
}
//void modify(ToDo task[]){}