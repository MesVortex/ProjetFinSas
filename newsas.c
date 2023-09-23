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
    char titre[25];
    char descri[150];
    char status[10];
    deadline de_li;
}ToDo;

int indice, G_ID = 1001;
ToDo task[200];

time_t temps(int a);
void add();
void add_more();
void show(int a);
void swap( int a, int b);
void tri_alpha();
void tri_de_li();
void days_3();
void supp(int a);
void modify(int i);
void menu();
void search_tit(char tit[]);
void days_left();
void done();
int search(int id);
int menu_tri();
int to_days(time_t a);


int main(){
    char empty[25];
    int choix,id,var;
    while(1){
        out:
        menu();
        printf("choisissez une option:");
        scanf("%d", &choix);
        switch (choix){
            case 1:
                add();
                break;
            case 2:
                add_more();
                break;
            case 3:
                printf("\n\nvoilà la liste de toutes les tâches:\n");
                for (int i = 0; i < indice; i++){show(i);}
                err_tri:
                var = menu_tri();
                switch (var){
                    case 1:
                        tri_alpha();
                        printf("\ntrier avec succès!!\n\n");
                        goto out;
                    case 2:
                        tri_de_li();
                        printf("\ntrier avec succès!!\n\n");
                        goto out;
                    case 3:
                        days_3();
                        goto out;
                    case 4:
                        goto out;
                    default:
                        printf("\nchoisissez une option parmi ces 4 svp!!\n\n");
                        goto err_tri;
                }
            case 4:
                printf("donner le ID de la tâche à modifier:");
                scanf("%d",&id);
                var = search(id);
                if (var >= 0){
                    modify(var);
                }
                break;
            case 5:
                printf("donner le ID de la tâche à Supprimer:");
                scanf("%d",&id);
                var = search(id);
                if (var >= 0){
                    supp(var);
                    printf("\ntâche supprimée !\n\n");
                }
                break;
            case 6:
                err_rech:
                printf("1.Rechercher une tâche par son Identifiant\n2.Rechercher une tâche par son Titre\n3.Retourner au menu principale.");
                printf("\nchoisissez une option:");
                scanf("%d", &choix);
                switch (choix){
                    case 1:
                        printf("donner l'ID de cette tâche:");
                        scanf("%d", &id);
                        var = search(id);
                        if (var >= 0){
                            show(var);
                        }
                        goto out;
                    case 2:
                        printf("donner le titre de cette tâche:");
                        scanf(" %[^\n]", empty);
                        search_tit(empty);
                        goto out;
                    case 3:
                        goto out;
                    default:
                        printf("\nchoisissez une option parmi celles affichées svp!!\n\n");
                        goto err_rech;
                }
            case 7:
                err_stat:
                printf("1.Afficher le nombre total des tâches.\n2.Afficher le nombre de tâches complètes et incomplètes.\n");
                printf("3.Afficher le nombre de jours restants jusqu'au délai de chaque tâche\n4.Retourner au menu principale.\n");
                printf("choisissez une option:");
                scanf("%d", &choix);
                switch (choix){
                    case 1:
                        printf("\nle nombre total des tâches est :%d\n", indice);
                        goto out;
                    case 2:
                        done();
                        goto out;
                    case 3:
                        days_left();
                        goto out;
                    case 4:
                        goto out;
                    default:
                        printf("\nchoisissez une option parmi celles affichées svp!!\n\n");
                        goto err_stat;
                }
            case 0:
                exit(0);
            default:
                printf("\nchoisissez une option parmi celles affichées svp!!\n\n");
                break;
        }
    }
    return 0;
}

int menu_tri(){
    int choice;
    printf("voulez vous:\n");
    printf("1.Triez les tâches par ordre alphabétique.\n2.Triez les tâches par deadline.\n");
    printf("3.Affichez les tâches dont le deadline est dans 3 jours ou moins.\n4.Retournez au menu principale.\n");
    printf("\nchoisissez une option:");
    scanf("%d",&choice);
    return choice;
}

void menu(){
        printf("\n***********************Gestion de Tâches / ToDo list***********************\n\n");
        printf("1.Ajouter une nouvelle tâche.\n");
        printf("2.Ajouter plusieurs nouvelles tâches.\n");
        printf("3.Afficher la liste de toutes les tâches.\n");
        printf("4.Modifier une tâche.\n");
        printf("5.Supprimer une tâche.\n");
        printf("6.Rechercher une tâche.\n");
        printf("7.Statistiques.\n");
        printf("0.exit.\n\n");
        printf("Commencez à enregistrer et à manipuler vos tâches librement ^_^\n\n");
        printf("\n***************************************************************************\n\n");
}

void show(int a){
    printf("\nIdentifiant (ID): %d\n", task[a].ID);
    printf("Titre de tâche: %s\n", task[a].titre);
    printf("Description: %s\n", task[a].descri);
    printf("Deadline: %d/%d/%d\n", task[a].de_li.jour, task[a].de_li.mois, task[a].de_li.annee);
    printf("statut: %s\n\n\n", task[a].status);
}

void add(){

    printf("Entrer le nom de la tâche:");
    scanf(" %[^\n]", task[indice].titre);

    printf("donner une decription (150 caractère max):");
    scanf(" %[^\n]", task[indice].descri);

    printf("ajouter une deadline (JJ/MM/AA):");
    scanf("%d/%d/%d", &task[indice].de_li.jour, &task[indice].de_li.mois, &task[indice].de_li.annee);

    printf("entrer le statut de votre tache (todo, doing, done):");
    scanf("%s", task[indice].status);

    task[indice].ID = G_ID;
    printf("\ntâche ajoutée avec succès!\n(ID de ce tache: %d)\n\n\n", G_ID);
    G_ID++;
    indice++;
}

void add_more(){
    int a,i,b = indice;
    printf("combien de tâche voulez vous ajoutez? :");
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

    strcpy(temp.titre,task[i].titre);
    strcpy(task[i].titre,task[j].titre);
    strcpy(task[j].titre,temp.titre);

    strcpy(temp.descri,task[i].descri);
    strcpy(task[i].descri,task[j].descri);
    strcpy(task[j].descri,temp.descri);

    strcpy(temp.status,task[i].status);
    strcpy(task[i].status,task[j].status);
    strcpy(task[j].status,temp.status);

    temp.de_li.jour = task[i].de_li.jour;
    task[i].de_li.jour = task[j].de_li.jour;
    task[j].de_li.jour = temp.de_li.jour;

    temp.de_li.mois = task[i].de_li.mois;
    task[i].de_li.mois = task[j].de_li.mois;
    task[j].de_li.mois = temp.de_li.mois;

    temp.de_li.annee = task[i].de_li.annee;
    task[i].de_li.annee = task[j].de_li.annee;
    task[j].de_li.annee = temp.de_li.annee;
}

void tri_alpha(){
    for(int i = 0 ;i < indice ; i++){
        for(int j = i+1 ;j < indice ; j++){
            if(strcasecmp(task[i].titre, task[j].titre)>0){
                swap(i,j);
            }
        }
    }
}

void tri_de_li(){
    for(int i = 0 ;i < indice ; i++){
        for(int j = i+1 ;j < indice ; j++){
            if(temps(i) > temps(j)){
                swap(i,j);
            }
        }
    }
}

void days_3(){
    int cmpt;
    const int three_D = 86400 * 3;
    for (int i = 0; i < indice; i++){
        if (temps(i) <= three_D){
            show(i);
            cmpt++;
        }
    }
    if (cmpt == 0){
        printf("\naucun résultat trouvée!!\n\n");
    }
}

time_t temps(int a){
    struct tm date;
    time_t NOW;
    time_t deadline_sec;

    date.tm_mday = task[a].de_li.jour;
    date.tm_mon = task[a].de_li.mois - 1;
    date.tm_year = task[a].de_li.annee - 1900;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    
    time(&NOW);

    deadline_sec = mktime(&date);
    return difftime(deadline_sec, NOW);
}

void supp(int a){
    for (int i = a; i < indice; i++){
        swap(i,i+1);
    }
    indice--;
}

int search(int id){
    for(int i = 0 ; i < indice ; i++){
        if (task[i].ID == id){
            return(i);
        }
    }
    printf("\naucun résultat trouvée!!\nessayez un autre ID\n\n ");
    return -1;
}

void modify(int i){
    char descri_modi[150],status_modi[10];
    int a;

    printf("1.Modifier la description\n2.Modifier le statut\n3.Modifier le deadline\n4.Retourner au menu principale\n");
    printf("choisissez une option:");
    scanf("%d", &a);

    error:
    switch(a){
        case 1: 
            printf("Entrer la nouvelle description : ");
            scanf(" %[^\n]", descri_modi);
            strcpy(task[i].descri, descri_modi);
            printf("\nModification réussie!\n\n");
            break;
        case 2: 
            printf("Entrer le nouveau statut : ");
            scanf(" %s", status_modi);
            strcpy(task[i].status, status_modi);
            printf("\nModification réussie!\n\n");
            break;
        case 3: 
            printf("Entrer le nouveau deadline (JJ/MM/AAAA) :");
            scanf("%d/%d/%d",  &task[i].de_li.jour, &task[i].de_li.mois, &task[i].de_li.annee);
            printf("\nModification réussie!\n\n");
            break;
        case 4:
            break;
        default:
            printf("\nchoisissez une option parmi celles affichées svp!!\n\n");
            goto error;
    }
}

void search_tit(char tit[]){
    int cmpt;
    for(int i = 0 ; i < indice ; i++){
        if(strcasecmp(task[i].titre, tit) == 0){
            show(i);
            cmpt++;
        }
    }
    if (cmpt == 0){
        printf("\naucun résultat trouvée!!\n\n");
    }
}

void done(){
    int task_comp = 0 ,task_uncomp = 0;
    for (int i = 0; i < indice; i++){
        if (strcasecmp(task[i].status,"done") == 0){
            task_comp++;
        }else{
            task_uncomp++;
        }
    }
    printf("\nle nombre de tâches complètes est: %d\n", task_comp);
    printf("le nombre de tâches incomplètes est: %d\n\n", task_uncomp);
}


void days_left(){
    int a;
    for (int i = 0; i < indice; i++){
        a = to_days(temps(i));
        printf("\nle nombre de jours restants jusqu'au délai de ce tâche est :%d jour(s)\n\n", a);
        show(i);
    }
}

int to_days(time_t a){
    return (int)(a / (24 * 60 * 60)) + 1;
}