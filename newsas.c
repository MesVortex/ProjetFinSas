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
void set_start_date(struct tm date[]);
void days_3();
void supp(int a);
void modify(int i);
void menu();
void done_undone();
void search_tit(char tit[]);
void days_left();
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
                printf("voila la liste de toutes les taches \n\n");
                for (int i = 0; i < indice; i++){show(i);}
                err_tri:
                var = menu_tri();
                switch (var){
                    case 1:
                        tri_alpha();
                        printf("trier avec succes!!\n\n");
                        goto out;
                    case 2:
                        tri_de_li();
                        printf("trier avec succes!!\n\n");
                        goto out;
                    case 3:
                        days_3();
                        goto out;
                    case 4:
                        goto out;
                    default:
                        printf("choisisser une option parmi ces 4 svp!!\n\n");
                        goto err_tri;
                }
            case 4:
                printf("donner le ID de la tache a modifier:");
                scanf("%d",&id);
                var = search(id);
                if (var >= 0){
                    modify(var);
                }
                break;
            case 5:
                printf("donner le ID de la tache a supp:");
                scanf("%d",&id);
                var = search(id);
                if (var >= 0){
                    supp(var);
                }
                break;
            case 6:
                err_rech:
                printf("1.Rechercher une tâche par son Identifiant\n2.Rechercher une tâche par son Titre\n3.Retournez au menu principale.");
                printf("choisissez une option:");
                scanf("%d", &choix);
                switch (choix){
                    case 1:
                        printf("donner l'ID de cet tache:");
                        scanf("%d", &id);
                        var = search(id);
                        if (var >= 0){
                            show(var);
                        }
                        goto out;
                    case 2:
                        printf("donner le titre de cet tache:");
                        scanf("%s", empty);
                        search_tit(empty);
                        goto out;
                    case 3:
                        goto out;
                    default:
                        printf("choisisser une option parmi ces 3 svp!!\n\n");
                        goto err_rech;
                }
            case 7:
                err_stat:
                printf("1.Afficher le nombre total des tâches.\n2.Afficher le nombre de tâches complètes et incomplètes.\n");
                printf("3.Afficher le nombre de jours restants jusqu'au délai de chaque tâche\n4.Retournez au menu principale.\n");
                printf("choisissez une option:");
                scanf("%d", &choix);
                switch (choix){
                    case 1:
                        printf("le nombre total des tâches est :%d", indice);
                        goto out;
                    case 2:
                        done_undone();
                        goto out;
                    case 3:
                        days_left();
                        goto out;
                    case 4:
                        goto out;
                    default:
                        printf("choisisser une option parmi ces 4 svp!!\n\n");
                        goto err_stat;
                }
            case 0:
                exit(0);
            default:
                break;
        }
    }
    return 0;
}

int menu_tri(){
    int choice;
    printf("voulez vous:\n");
    printf("1.Trier les tâches par ordre alphabétique.\n2.Trier les tâches par deadline.\n");
    printf("3.Afficher les tâches dont le deadline est dans 3 jours ou moins.\n4.Retournez au menu principale.\n");
    printf("choisissez une option:");
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
    printf("Titre de tache: %s\n", task[a].titre);
    printf("Description: %s\n", task[a].descri);
    printf("Deadline: %d/%d/%d\n", task[a].de_li.jour, task[a].de_li.mois, task[a].de_li.annee);
    printf("statut: %s\n\n\n", task[a].status);
}

void add(){

    printf("Entrez le nom de la tache:");
    scanf("%s", task[indice].titre);

    printf("donner une decription (optional & 150 charactere maa):");
    scanf(" %[^\n]", task[indice].descri);

    printf("ajouter une deadline (JJ/MM/AA):");
    scanf("%d/%d/%d", &task[indice].de_li.jour, &task[indice].de_li.mois, &task[indice].de_li.annee);

    printf("entrer le statut de votre tache (todo, doing, done):");
    scanf("%s", task[indice].status);

    task[indice].ID = G_ID;
    printf("tache ajouté avec succès!\n(ID de ce tache: %d)\n\n\n", G_ID);
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

void tri_alpha(){
    for(int i = 0 ;i < indice ; i++){
        for(int j = i+1 ;j < indice ; j++){
            if(strcmp(task[i].titre, task[j].titre)>0){
                swap(i,j);
            }
        }
    }
}

void tri_de_li(){
    for(int i = 0 ;i < indice ; i++){
        for(int j = i+1 ;j < indice ; j++){
            if(temps(i) < temps(j)){
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
        printf("aucun resultat trouvee!!\n\n");
    }
}

time_t temps(int a){
    struct tm date[1];
    time_t NOW;
    time_t deadline_sec;

    date[0].tm_mday = task[a].de_li.jour;
    date[0].tm_mon = task[a].de_li.mois;
    date[0].tm_year = task[a].de_li.annee;
    
    time(&NOW);
    set_start_date(&date[0]);

    deadline_sec = mktime(&date[0]);
    return difftime(deadline_sec, NOW);
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
    printf("aucun resultat trouvee!!\nessayez un autre ID\n\n ");
    return -1;
}

void modify(int i){
    char descri_modi[150],status_modi[10];
    int a;

    printf("1.Modifier la description\n2.Modifier le statut\n3.Modifier le deadline\n4.Retournez au menu principale\n");
    printf("Taper le numero de votre choix :");
    scanf("%d", &a);

    error:
    switch(a){
        case 1: 
            printf("Entrer la nouvelle description : ");
            scanf(" %[^\n]", descri_modi);
            strcpy(task[i].descri, descri_modi);
            break;
        case 2: 
            printf("Entrer le nouveau statut : ");
            scanf(" %s", status_modi);
            strcpy(task[i].status, status_modi);
            break;
        case 3: 
            printf("Entrer le nouveau deadline (JJ/MM/AAAA) :");
            scanf("%d/%d/%d",  &task[i].de_li.jour, &task[i].de_li.mois, &task[i].de_li.annee);
            break;
        case 4:
            break;
        default:
            printf("choisisser une option parmi ces 4 svp!!\n\n");
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
        printf("aucun resultat trouvee!!\n\n");
    }
}

void done_undone(){
    int cmpt1,cmpt2;
    for (int i = 0; i < indice; i++){
        if (strcasecmp(task[i].status,"done") == 0){
            cmpt1++;
        }else
            cmpt2++;
    }
    printf("le nombre de tâches complètes est : %d\n",cmpt1);
    printf("le nombre de tâches incomplètes est : %d\n\n",cmpt2);
}

void days_left(){
    int a;
    for (int i = 0; i < indice; i++){
        show(i);
        a = to_days(temps(i));
        printf("le nombre de jours restants jusqu'au délai de tâcheest :%d jour(s)\n\n", a);
    }
}

int to_days(time_t a){
    return (int)(a / (24 * 60 * 60)) + 1;
}