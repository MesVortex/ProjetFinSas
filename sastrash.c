#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int b, G_ID = 1001;
ToDo task[200];

time_t temps(int a);
void add();
void add_more();
void show(int a);
void swap( int a, int b);
void tri_alpha();
void tri_de_li();
void set_start_date(struct tm date[]);
void days_3();
void supp(int a);
int search(int id);
void modifier(int b);

int main(){
    int choia,id;
    again:
    printf("choia");
    scanf("%d", &choia);
    switch (choia){
    case 1: add();
        goto again;
        break;
    case 2: add_more();
        break;
    case 3: for (int i = 0; i < b; i++){show(i);}
        break;
    case 4: tri_alpha(); // void modify
        goto again;
        break;
    case 5: tri_de_li();
        goto again;
        break;
    case 6: days_3();
        break;
    case 7: printf("donner le ID de la tache a supp:");
        scanf("%d",&id);
        printf("\n%d\n",b);
        supp(search(id));
        printf("\n%d\n",b);
        goto again;
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
    scanf("%s", task[b].titre);

    printf("donner une decription (optional & 150 charactere maa):");
    scanf(" %[^\n]", task[b].descri);

    printf("ajouter une deadline (JJ/MM/AA):");
    scanf("%d/%d/%d", &task[b].de_li.jour, &task[b].de_li.mois, &task[b].de_li.annee);
    
    printf("entrer le statut de votre tache (todo, doing, done):");
    scanf("%s", task[b].status);

    task[b].ID = G_ID;
    printf("tache ajouté avec succès!\n (ID de ce tache: %d)\n", G_ID);
    G_ID++;
    b++;
}

void add_more(){
    int a,i,b = b;
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

void tri_alpha(){
    for(int i = 0 ;i < b ; i++){
        for(int j = i+1 ;j < b ; j++){
            if(strcmp(task[i].titre, task[j].titre)>0){
                swap(i,j);
            }
        }
    }
}

void tri_de_li(){
    for(int i = 0 ;i < b ; i++){
        for(int j = i+1 ;j < b ; j++){
            if(temps(i) > temps(j)){
                swap(i,j);
            }
        }
    }
}

void days_3(){
    const int three_D = 86400 * 3;
    for (int i = 0; i < b; i++){
        if (temps(i) <= three_D){
            show(i);
        }
    }
}

time_t temps(int a){
    struct tm date[1];
    time_t NOW;
    time_t NOW_sec;

    date[0].tm_mday = task[a].de_li.jour;
    date[0].tm_mon = task[a].de_li.mois;
    date[0].tm_year = task[a].de_li.annee;
    
    time(&NOW);
    set_start_date(&date[0]);

    NOW_sec = mktime(&date[0]);
    return difftime(NOW_sec, NOW);
}

void set_start_date(struct tm date[]){
    date[0].tm_mon -= 1;
    date[0].tm_year -= 1900;
    date[0].tm_hour = 0;
    date[0].tm_min = 0;
    date[0].tm_sec = 0;
    date[0].tm_wday = 0;
    date[0].tm_yday = 0;
    date[0].tm_isdst = 0;
}

void supp(int a){
    for (int i = a; i < b; i++){
        swap(i,i+1);
    }
    b--;
}

int search(int id){
        for(int i = 0 ; i < b ; i++){
            if (task[i].ID == id){
                return(i);
            }
        }
}

void modifier(int b){
    char descri_modi[150],status_modi[10];
    int a;

    printf("1.Modifier la description\n2.Modifier le statut\n3.Modifier le deadline\n");
    printf("Taper l'option : ");
    scanf("%d", &a);

    switch(a){
        case 1: 
            printf("Entrer la nouvelle description : ");
            scanf("%[^\n]", descri_modi);
            strcpy(task[b].descri, descri_modi);
            break;
        case 2: 
            printf("Entrer le nouvelle statut : ");
            scanf("%s", status_modi);
            strcpy(task[b].status, status_modi);
            break;
        case 3: 
            printf("Entrer le nouvelle deadline (jj/mm/aaaa) :");
            scanf("%d/%d/%d",  &task[b].de_li.jour, &task[b].de_li.mois, &task[b].de_li.annee);
            break;
        default:
            printf("Invalid option !");
            break;
    }
}