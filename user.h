#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <gtk/gtk.h>



typedef struct{
int jour;
int mois;
int annee;
}date;


////////////////////////

typedef struct{
char nom[200];
char prenom[200];
char sexe[10];
char cin[100];

date date_naissance;

char username[20];
char password[20];

char role[20];
char adresse[200];
char mail[300];
char numtelephone[100];
}users;

////////////////////////////
/////////Tache 2////////////
typedef struct debit
{
    int jourpanne;
    int heure;
    int etage;
    char valeur[10];

}debit;


void ajouter_utilisateur(users U);
void modifier_utilisateur(users u);
int  test_utilisateur(char *id);
void supprimer_utilisateur(char username[]);
void rechercher_utilisateur(GtkWidget *liste,char ID[]);
void afficher_utilisateur(GtkWidget *liste);
void etage_debit(GtkWidget*liste);
int verif_authen(char *log[], char *pw[], char *rl[]);


#endif

