#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "user.h"
#include <stdlib.h>

/////////////////////////////////ajouter utilisateurs 
void ajouter_utilisateur(users U)
{
    FILE *g=NULL;
    g=fopen("utilisateur2.txt","a+");
    FILE *F=NULL;
    F=fopen("utilisateur1.txt","a+");
    if(F!=NULL)
    {
    fprintf(F," %s %s %s %s %s %s %d %d %d %s %s %s %s \n",U.username, U.nom, U.prenom, U.sexe, U.cin, U.password, U.date_naissance.jour,U.date_naissance.mois, U.date_naissance.annee,U.role, U.adresse, U.mail,U.numtelephone);
fprintf(g," %s %s %s \n",U.username,U.password,U.role);
    fclose(F);
    fclose(g);
}
}


////////////////////////////////tester si l'utilisateur existe ou non 
int test_utilisateur(char *id)
{
FILE*f=NULL;
users u;
f=fopen("utilisateur1.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %s \n",u.username,u.nom,u.prenom,u.sexe,u.cin,u.password,&u.date_naissance.jour,&u.date_naissance.mois, &u.date_naissance.annee,u.role,u.adresse,u.mail,u.numtelephone)!=EOF)
{
if(strcmp(u.username,id)==0)
return 1;  
}
fclose(f);
return 0;
}
////////////////////les fonctions verifiant les controles de saisie ////////////////

/////////////// champs contenant que des lettres /////////////
int MNverifier_lettre (char ch[20])
{
int i;
int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != 'a' && ch[i] != 'b' && ch[i] != 'c' && ch[i] != 'd' &&ch[i] != 'e' &&ch[i] != 'f' &&ch[i] != 'g' &&ch[i] != 'h' &&ch[i] != 'i' &&ch[i] != 'j' &&ch[i] != 'k'&&ch[i] != 'l'&&ch[i] != 'm'&&ch[i] != 'n'&&ch[i] != 'o'&&ch[i] != 'p'&&ch[i] != 'q'&&ch[i] != 'r'&&ch[i] != 's'&&ch[i] != 't'&&ch[i] != 'u'&&ch[i] != 'v'&&ch[i] != 'w'&&ch[i] != 'x'&&ch[i] != 'z'&&ch[i] != 'y'  )
    x = 1 ;}
   if ( x == 0 ) return 1;
    else return 0;
}

//////////////////////////// controle sur C.I.N //////////////////
int MNverifier_cin (char ch[20])
{int i;int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' &&ch[i] != '4' &&ch[i] != '5' &&ch[i] != '6' &&ch[i] != '7' &&ch[i] != '8' &&ch[i] != '9'  || strlen(ch)!=8 )
    x = 1 ;}
   if ( x == 0 ) return 1;
   else return 0;
}
////////////////////////////// controle mail ////////////////////////
int MNverifier_email (char ch[20])
{int i;int x = 0;int y = 0; int z = 0; int b = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] == '@' )
    x =x+ 1 ;
    if (ch[i] == '.' )
    b =b+ 1 ;
    if (ch[i] == ' ' )
    y = 1 ;}
    if (ch [0]=='@' || ch[strlen(ch)-1]=='@' || ch[strlen(ch)-1]=='.' )
        z =1;
   if ( x == 1 && y == 0 && z == 0 && b >0) return 1;
    else return 0;
}
////////////////////// controle password ////////////////////////////////////
int MNverifier_passiden (char ch[20])
{
int i;
int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != 'a' && ch[i] != 'b' && ch[i] != 'c' && ch[i] != 'd' &&ch[i] != 'e' &&ch[i] != 'f' &&ch[i] != 'g' &&ch[i] != 'h' &&ch[i] != 'i' &&ch[i] != 'j' &&ch[i] != 'k'&&ch[i] != 'l'&&ch[i] != 'm'&&ch[i] != 'n'&&ch[i] != 'o'&&ch[i] != 'p'&&ch[i] != 'q'&&ch[i] != 'r'&&ch[i] != 's'&&ch[i] != 't'&&ch[i] != 'u'&&ch[i] != 'v'&&ch[i] != 'w'&&ch[i] != 'x'&&ch[i] != 'z'&&ch[i] != 'y'&&ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' &&ch[i] != '4' &&ch[i] != '5' &&ch[i] != '6' &&ch[i] != '7' &&ch[i] != '8' &&ch[i] != '9'  || strlen(ch)!=5  )
    x = 1 ;}
   if ( x == 0 ) return 1;
    else return 0;
}

////////////////////////////////////////afficher utilisateur

enum
{
	EUSERNAME,
	ENOM,
	EPRENOM,
	ESEXE,
	ECIN,
	EPASSWORD,
	EJOUR,
	EMOIS,
	EANNEE,
	EROLE,
	EADRESSE,
	EMAIL,
	ENUMTELEPHONE,
	
 COLUMNS};
void afficher_utilisateur(GtkWidget  *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char username[20];
	char nom[20];
	char prenom[20];
	char sexe[20];
        char cin[20];
	char password[20];
	int  jour;
	int  mois;
        int  annee;
	char role[20];
        char adresse[20];
	char mail[20];
	char numtelephone[20];
	
        store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
        renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("username",renderer, "text",EUSERNAME,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text", EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" sexe",renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("password",renderer, "text",EPASSWORD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	
        renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("role",renderer, "text",EROLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("adresse",renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mail",renderer, "text",EMAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
        
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numtelephone",renderer, "text",ENUMTELEPHONE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("utilisateur1.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("utilisateur1.txt","a+");
	 	       while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %s \n",username,nom,prenom,sexe,cin,password,&jour,&mois,&annee,role,adresse,mail,numtelephone)!=EOF)	          						  
		 {
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EUSERNAME,username,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ECIN,cin,EPASSWORD,password,
			EJOUR,jour,EMOIS,mois,EANNEE,annee,EROLE,role,EADRESSE,adresse,EMAIL,mail,ENUMTELEPHONE,numtelephone,-1);
		 
}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}


///////////////////////////////////////////////// rechercher utilisateur
void rechercher_utilisateur(GtkWidget *liste,char ID[])

{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char username[20];
	char nom[20];
	char prenom[20];
	char sexe[20];
        char cin[20];
	char password[20];
	int  jour;
	int  mois;
        int  annee;
	char role[20];
        char adresse[20];
	char mail[20];
	char numtelephone[20];

	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("username",renderer, "text",EUSERNAME,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text", EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" sexe",renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("password",renderer, "text",EPASSWORD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	
        renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("role",renderer, "text",EROLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("adresse",renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mail",renderer, "text",EMAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
        
        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numtelephone",renderer, "text",ENUMTELEPHONE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	


	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("utilisateur1.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("utilisateur1.txt","a+");
	 	       while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %s \n",username,nom,prenom,sexe,cin,password,&jour,&mois,&annee,role,adresse,mail,numtelephone)!=EOF)	          						  
		{
            if(strcmp(username,ID)==0)                						  
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EUSERNAME,username,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ECIN,cin,EPASSWORD,password,
			EJOUR,jour,EMOIS,mois,EANNEE,annee,EROLE,role,EADRESSE,adresse,EMAIL,mail,ENUMTELEPHONE,numtelephone,-1);
		}
                 }
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
}

//////////////////////////////////////////////////// modifier utilisateur
void modifier_utilisateur(users u)
{
	char nom[20];
	char prenom[20];
	char sexe[20];
        char cin[20];
	char password[20];
	int  jour;
	int  mois;
        int  annee;
	char role[20];
        char adresse[20];
	char mail[20];
	char numtelephone[20];
        char id[20];
FILE *f=NULL;
FILE *tmp=NULL;

f=fopen("utilisateur1.txt","r");
tmp=fopen("utilis.txt","w+");

while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %s %s\n",id,nom,prenom,sexe,cin,password,&jour,&mois,&annee,role,adresse,mail,numtelephone)!=EOF)
{

if(strcmp(u.username,id)==0) 
{fprintf(tmp,"%s %s %s %s %s %s %d %d %d %s %s %s %s\n",u.username,u.nom,u.prenom,u.sexe,u.cin,u.password,u.date_naissance.jour,u.date_naissance.mois,u.date_naissance.annee,u.role,u.adresse, u.mail,u.numtelephone);
}
else
{
fprintf(tmp,"%s %s %s %s %s %s %d %d %d %s %s %s %s\n",id,nom,prenom,sexe,cin,password,jour,mois,annee,role,adresse,mail,numtelephone);
}
}

fclose(f);
fclose(tmp);
remove("utilisateur1.txt");
rename("utilis.txt","utilisateur1.txt");
}


///////////////////////////////////////////////////// supprimer utilisateur
void supprimer_utilisateur(char username[])
{
users u;
FILE *f;
FILE *tmp;
f=fopen("utilisateur1.txt","r");
tmp=fopen("tempo.txt","a+");

if (f!=NULL)
{
while(fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s %s \n" ,u.username,u.nom,u.prenom,u.sexe,u.cin,u.password,&u.date_naissance.jour,&u.date_naissance.mois,&u.date_naissance.annee,u.role,u.adresse, u.mail,u.numtelephone)!=EOF)
{
if(strcmp(u.username,username)!=0)
{
fprintf(tmp,"%s %s %s %s %s %s %d %d %d %s %s %s %s \n",u.username,u.nom,u.prenom,u.sexe,u.cin,u.password,u.date_naissance.jour,u.date_naissance.mois,u.date_naissance.annee,u.role,u.adresse, u.mail,u.numtelephone);
}
}
}
fclose(f);
fclose(tmp);
remove("utilisateur1.txt");
rename("tempo.txt","utilisateur1.txt");
}

///////////////////////  Tache 2 /////////////////////////////////////
//////////////////////////////////////////////////////////////////////
enum
{
	EJOURPANNE,
	EHEURE,
	EETAGE,
	EVALEUR,
 COLUMN};
void afficher_etage(GtkWidget  *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	int jourpanne;
        int heure;
        int etage;
        char valeur[10];

	
        store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{

        renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jourpanne",renderer, "text",EJOURPANNE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("heure",renderer,"text",EHEURE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etage",renderer, "text", EETAGE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" valeur",renderer, "text",EVALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	}

	store=gtk_list_store_new (COLUMN,G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
	f=fopen("debit.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("debit.txt","a+");
	 	       while(fscanf(f,"%d %d %d %s \n",&jourpanne,&heure,&etage,valeur)!=EOF)	          						  
		 {
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EJOURPANNE,jourpanne,EHEURE,heure,EETAGE,etage,EVALEUR,valeur,-1); 
}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
//////////////////////////////////////////////////////// affichage etage en panne
void etage_debit(GtkWidget*liste)

{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

    	int jourpanne;
        int heure;
        int etage;
        char valeur[10];
	float valeurf;


	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jourpanne",renderer, "text",EJOURPANNE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("heure",renderer,"text",EHEURE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etage",renderer, "text", EETAGE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" valeur",renderer, "text",EVALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	
	store=gtk_list_store_new (COLUMN,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);
	f=fopen("debit.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("debit.txt","a+");
	 	       while(fscanf(f,"%d %d %d %s\n",&jourpanne,&heure,&etage,valeur)!=EOF)	          						  
		{
            valeurf=atof(valeur);
            if((valeurf<0)||(valeurf>30))                						  
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EJOURPANNE,jourpanne,EHEURE,heure,EETAGE,etage,EVALEUR,valeur,-1); 
		}
                 }
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
}

//////////////////////// verifier identifiant et password dans authentification /////////////////////////////////

int verif_authen(char *log[], char *pw[], char *rl[])
{
int trouve=-1;
users u;
FILE *f=NULL;
f=fopen("utilisateur2.txt","r");
if (f!=NULL){
while (fscanf(f,"%s %s %s \n",u.username,u.password,u.role)!=EOF)
{if( (strcmp(u.username,log)==0) && (strcmp(u.password,pw)==0)&& (strcmp(u.role,rl)==0)){
trouve=1;}
}
}
fclose(f);
return trouve;
}



