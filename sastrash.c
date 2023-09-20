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

int indice, G_ID = 1001;
ToDo task[200];

void add();
void add_more();
void show(int a);
void swap( int a, int b);
//void modify();

int main(){
    int choix;
    again:
    printf("choix");
    scanf("%d", &choix);
    switch (choix){
    case 1:  printf("%d\n",indice);
        add();
        printf("%d\n",indice);
        goto again;
        break;
    case 2: printf("%d\n",indice);
        add_more();
        printf("%d\n", indice);
        break;
    case 3: for (int i = 0; i < indice; i++){show(i);}
        break;
    case 4: // void modify
        break;
    default:
        break;
    }
    return 0;
}

void show(int a){
        printf("\nIdentifiant (ID): %d\n", task[a].ID);
        printf("Titre de tache: %s\n", task[a].titre);
        printf("Description: %s\n", task[a].descri);
        printf("Deadline: %d/%d/%d\n", task[a].de_li.jour, task[a].de_li.mois, task[a].de_li.annee);
        printf("statut: %s\n\n", task[a].status);
    }

void add(){

    printf("Entrez le nom de la tache:");
    scanf("%s", task[indice].titre);

    printf("donner une decription (optional & 150 charactere max):");
    scanf(" %[^\n]", task[indice].descri);

    printf("ajouter une deadline (JJ/MM/AA):");
    scanf("%d/%d/%d", &task[indice].de_li.jour, &task[indice].de_li.mois, &task[indice].de_li.annee);
    
    printf("entrer le statut de votre tache (todo, doing, done):");
    scanf("%s", task[indice].status);

    task[indice].ID = G_ID;
    printf("tache ajouté avec succès!\n (ID de ce tache: %d)\n", G_ID);
    G_ID++;
    indice++;
}

void add_more(){
    int a,i,b = indice;
    printf("combien de tache voulez vous ajoutez? :");
    scanf("%d", &a);
    for ( i = b; i < b + a ; i++){
        add();
    }
}

void swap( int i, int j){
    ToDo temp;
    temp.ID = task[i].ID;
    task[i].ID = task[j].ID;
    task[j].ID = temp.ID;
    
    temp.de_li.jour = task[i].de_li.jour;
    task[i].de_li.jour = task[j].de_li.jour;
    task[j].de_li.jour = temp.de_li.jour;

    temp.de_li.mois = task[i].de_li.mois;
    task[i].de_li.mois = task[j].de_li.mois;
    task[j].de_li.mois = temp.de_li.mois;

    temp.de_li.annee = task[i].de_li.annee;
    task[i].de_li.annee = task[j].de_li.annee;
    task[j].de_li.annee = temp.de_li.annee;

    strcpy(temp.titre,task[i].titre);
    strcpy(task[i].titre,task[j].titre);
    strcpy(task[j].titre,temp.titre);

    strcpy(temp.descri,task[i].descri);
    strcpy(task[i].descri,task[j].descri);
    strcpy(task[j].descri,temp.descri);

    strcpy(temp.status,task[i].status);
    strcpy(task[i].status,task[j].status);
    strcpy(task[j].status,temp.status);
}
//void modify(ToDo task[]){}