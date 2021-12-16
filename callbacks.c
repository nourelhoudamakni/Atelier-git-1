#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "user.h"
#include "user.c"
#include <stdlib.h>
#include <string.h>

///////////////////////////// Deconnexion ///////////////////////////////////////
void
on_MN_deconnexion_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* MNaccueil;
GtkWidget* MNauthentification;


MNaccueil=lookup_widget(button,"MNaccueil");
gtk_widget_destroy(MNaccueil);
MNauthentification=lookup_widget(button,"MNauthentification");
MNauthentification=create_MNauthentification();
gtk_widget_show(MNauthentification);
}


/////////////////////////// Tache ajout /////////////////////////////////////////

void
on_MNajouter_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* MNaccueil;
MNaccueil=lookup_widget(button,"MNaccueil");
gtk_widget_destroy(MNaccueil);
GtkWidget* MNajout;
MNajout=create_MNajout();
gtk_widget_show(MNajout);
}
////////////////////////////////////////////////////////////////////
int MNx;
void
on_MN_validerajout_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
   users u;
   GtkWidget *nom;
   GtkWidget *prenom;
   GtkWidget *sexe;
   GtkWidget *cin;
   GtkWidget *jour;
   GtkWidget *mois;
   GtkWidget *annee;
   GtkWidget *username;
   GtkWidget *password;
   GtkWidget *rolecombobox;
   GtkWidget *adresse;
   GtkWidget *mail;
   GtkWidget *numtelephone;
GtkWidget *outputMsg;
GtkWidget *outputMsg1;
GtkWidget *outputMsg2;
GtkWidget *outputMsg3;
GtkWidget *outputMsg4;
GtkWidget *outputMsg5;
GtkWidget *outputMsg6;
GtkWidget *outputMsg7;
GtkWidget *outputMsg8;
GtkWidget *outputMsg9;
GtkWidget *outputMsg10;


 int test;
 char text[200]; char text1[200]; char text2[200]; char text3[200]; char text4[200];char text5[200]; char text6[200]; char text7[200]; char text8[200];
char text9[200];char text10[200];

   //char fich[200];




nom = lookup_widget(GTK_WIDGET(button), "MNentry_nom");
prenom = lookup_widget(GTK_WIDGET(button), "MNentry_prenom");
cin = lookup_widget(GTK_WIDGET(button), "MN_entrycin");
jour = lookup_widget(GTK_WIDGET(button), "MN_spinbuttonjour");
mois = lookup_widget(GTK_WIDGET(button), "MN_spinbuttonmois");
annee = lookup_widget(GTK_WIDGET(button), "MN_spinbuttonannee");
username = lookup_widget(GTK_WIDGET(button), "MNentry_id");
password = lookup_widget(GTK_WIDGET(button), "MNentry_pass");
rolecombobox= lookup_widget(GTK_WIDGET(button), "MN_comboboxrole");
adresse = lookup_widget(GTK_WIDGET(button), "MN_entryadresse");
mail = lookup_widget(GTK_WIDGET(button), "MN_entry");
numtelephone = lookup_widget(GTK_WIDGET(button), "MN_entrytel");

int mnverif=0;
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
u.date_naissance.jour =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
u.date_naissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
u.date_naissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(u.username,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(u.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(rolecombobox)));
strcpy(u.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(u.mail,gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(u.numtelephone,gtk_entry_get_text(GTK_ENTRY(numtelephone)));

strcpy(u.sexe,"Femelle");
if(MNx==1)
{strcpy(u.sexe,"Femelle");}

if(MNx==2)
{strcpy(u.sexe,"Male");}

test=test_utilisateur(u.username);
switch (test)
{
     case 1:
    { strcpy (text,"Identifiant déja existe ! veuillez utiliser un autre identifiant");
    outputMsg=lookup_widget(button,("MN_messageajout"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
    break;

    case 0:
    { if (MNverifier_lettre (u.nom)==0 ||(strcmp(u.nom,"")==0))
        {mnverif=1;
         strcpy (text1,"Verifier votre nom !");
         outputMsg1=lookup_widget(button,("MN_verifnom"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg1,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg1),text1);
        }
     
      if (MNverifier_lettre (u.prenom)==0 ||(strcmp(u.prenom,"")==0))
        {mnverif=1;
         strcpy (text2,"Verifier votre prenom !");
         outputMsg2=lookup_widget(button,("MN_verifprenom"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg2,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg2),text2);
        }

      if (MNverifier_cin (u.cin)==0 || (strcmp(u.cin,"")==0)) 
        {mnverif=1;
         strcpy (text3,"Verifier le numero cin  !");
         outputMsg3=lookup_widget(button,("MN_verifcin"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg3,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg3),text3);
        }

      if (MNverifier_passiden (u.username)==0 || (strcmp(u.username,"")==0))
        {mnverif=1;
         strcpy (text4,"Verifier l'identifiant !");
         outputMsg4=lookup_widget(button,("MN_verifident"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg4,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg4),text4);
        }

     if (MNverifier_passiden (u.password)==0 || (strcmp(u.password,"")==0))
        {mnverif=1;
         strcpy (text5,"le mot de passe doive contenir 5 carecteres des lettres et des chiffres !");
         outputMsg5=lookup_widget(button,("MN_verifpassword"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg5,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg5),text5);
        }

     if ( (strcmp(u.role,"")==0))
        {mnverif=1;
         strcpy (text6," veuillez choisir un role !");
         outputMsg6=lookup_widget(button,("MN_verifrole"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg6,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg6),text6);
        }

     if ( (strcmp(u.adresse,"")==0))
        {mnverif=1;
         strcpy (text7," Verifier l'adresse !");
         outputMsg7=lookup_widget(button,("MN_verifadresse"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg7,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg7),text7);
        }

    if (MNverifier_email (u.mail)==0 || (strcmp(u.mail,"")==0))
        {mnverif=1;
         strcpy (text8," Verifier le mail !");
         outputMsg8=lookup_widget(button,("MN_verifmail"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg8,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg8),text8);
        }


    if (MNverifier_cin (u.numtelephone)==0 || (strcmp(u.numtelephone,"")==0)) 
        {mnverif=1;
         strcpy (text9,"Verifier le numero telephone  !");
         outputMsg9=lookup_widget(button,("MN_veriftel"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg9,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg9),text9);
        }

    if (mnverif==0)
    {
    ajouter_utilisateur(u);
    strcpy (text10,"Ajout Réussi");
    outputMsg10=lookup_widget(button,("MN_validajoutt"));
    GdkColor color;
    gdk_color_parse("green",&color);
    gtk_widget_modify_fg(outputMsg10,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg10),text10);
    }
     
    }
    break;
    break;
} 
  
}

////////////////////////////////////////////////////////////////////
void
on_MNradio_femelle_toggled             (GtkToggleButton *toggle_button,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(toggle_button)))
{
MNx=1;
}
}

////////////////////////////////////////////////////////////////////
void
on_MNradio_male_toggled                (GtkToggleButton *toggle_button,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(toggle_button)))
{
MNx=2;
}
}


//////////////////////////////////////
void
on_MN_retourajout_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* MNaccueil;
GtkWidget* MNajout;
GtkWidget* MNtreeview1;

MNajout=lookup_widget(button,"MNajout");
gtk_widget_destroy(MNajout);
MNaccueil=lookup_widget(button,"MNaccueil");
MNaccueil=create_MNaccueil();
gtk_widget_show(MNaccueil);
MNtreeview1=lookup_widget(MNaccueil,"MNtreeview1");
afficher_utilisateur(MNtreeview1);

}





///////////////////////// Tache modification ///////////////////////////////////////////
void
on_MNmodifier_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
int MN_index=0;
char text[100];
GtkWidget *outputMsg;
GtkWidget *MNaccueil;
GtkWidget *MNmodif;
GtkWidget *MNtreeview1;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
	gchar *username;
	gchar *nom;
	gchar *prenom; 
	gchar *sexe; 
	gchar *cin;
 	gchar *password;
	gchar *jour; 
        gchar *mois;
        gchar *annee;
	gchar *role; 
        gchar *adresse;
        gchar *mail;
	gchar *numtelephone;
        users u;
      
	
GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input7;
GtkWidget*input8;
GtkWidget*input9;
GtkWidget*input10;
GtkWidget*input11;
GtkWidget*input12;
GtkWidget*input13;
GtkWidget *MNradiofemelle;
GtkWidget *MNradiomale;
GtkWidget *output;

MNaccueil=lookup_widget(button,"MNaccueil");
MNtreeview1=lookup_widget(MNaccueil,"MNtreeview1");

selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(MNtreeview1));

if(gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&username,1,&nom,2,&prenom,3,&sexe,4,&cin,5,&password,6,&jour,7,&mois,8,&annee,9,&role,10,&adresse,11,&mail,12,&numtelephone,-1);
	
	strcpy(u.username,username);
	strcpy(u.nom,nom);
	strcpy(u.prenom,prenom);
	strcpy(u.sexe,sexe);
	strcpy(u.cin,cin);
	strcpy(u.password,password);
        u.date_naissance.jour=jour;
        u.date_naissance.mois=mois;
        u.date_naissance.annee=annee; 
	strcpy(u.role,role);
        strcpy(u.adresse,adresse);
	strcpy(u.mail,mail);
        strcpy(u.numtelephone,numtelephone);

gtk_widget_hide(MNaccueil);
MNmodif=create_MNmodif();
gtk_widget_show(MNmodif);
input1=lookup_widget(MNmodif,"MN_modifentrynom");
input2=lookup_widget(MNmodif,"MN_modifentryprenom");
input3=lookup_widget(MNmodif,"MN_entrymodifcin");
input4=lookup_widget(MNmodif,"MN_modifjourspin");
input5=lookup_widget(MNmodif,"MN_modifmoisspin");
input6=lookup_widget(MNmodif,"MN_modifanneespin");
input7=lookup_widget(MNmodif,"MN_entrymodifid");
input8=lookup_widget(MNmodif,"MN_modifentrypass");
input9=lookup_widget(MNmodif,"MN_comboboxmodif");
input10=lookup_widget(MNmodif,"MN_adresseentrymodif");
input11=lookup_widget(MNmodif,"MN_mailmodifentry");
input12=lookup_widget(MNmodif,"MN_numtelmodifentry");
MNradiofemelle=lookup_widget(MNmodif,"MN_radiofemellemodif");
MNradiomale=lookup_widget(MNmodif,"MN_radiomalemodif");

if (strcmp(role,"Agent_de _foyer")==0){
   MN_index=0;
}    
if (strcmp(role,"Agent_de_reclamation")==0){
   MN_index=1;
} 
if (strcmp(role,"Nutrisionniste")==0){
   MN_index=2;
}
if (strcmp(role,"Technicien")==0){
   MN_index=3;
}    
if (strcmp(role,"Etudiant")==0){
   MN_index=4;
}
if (strcmp(role,"Agent_de_club")==0){
   MN_index=5;
}    
if (strcmp(role,"Agent_de_stock")==0){
   MN_index=6;
}
if (strcmp(role,"Administrateur")==0){
   MN_index=7;
}
             		
gtk_combo_box_set_active(GTK_ENTRY(lookup_widget(MNmodif,"MN_comboboxmodif")),MN_index);
gtk_entry_set_text (GTK_ENTRY(input1),u.nom);
gtk_entry_set_text (GTK_ENTRY(input2),u.prenom);
gtk_entry_set_text (GTK_ENTRY(input3),u.cin);
gtk_entry_set_text (GTK_ENTRY(input7),u.username);
gtk_entry_set_text (GTK_ENTRY(input8),u.password);

gtk_entry_set_text (GTK_ENTRY(input10),u.adresse);
gtk_entry_set_text (GTK_ENTRY(input11),u.mail);
gtk_entry_set_text (GTK_ENTRY(input12),u.numtelephone);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),u.date_naissance.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),u.date_naissance.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),u.date_naissance.annee);

if (strcmp(sexe,"Femelle")==0)
{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (MNradiofemelle),TRUE );
	gtk_label_set_text(GTK_LABEL(output),"");
}
else if (strcmp(sexe,"Male")==0)
{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (MNradiomale),TRUE );
	gtk_label_set_text(GTK_LABEL(output),"");
}


}
else
{
         strcpy (text,"veuillez selectionner l'utilisateur à modifier !");
         outputMsg=lookup_widget(button,("MN_selection"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
}
////////////////////////////////////////////////////////////////////
int xMN;
void
on_MN_validermodif_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
   users u;
   GtkWidget *nom;
   GtkWidget *prenom;
   GtkWidget *sexe;
   GtkWidget *cin;
   GtkWidget *jour;
   GtkWidget *mois;
   GtkWidget *annee;
   GtkWidget *username;
   GtkWidget *password;
   GtkWidget *rolecombobox;
   GtkWidget *adresse;
   GtkWidget *mail;
   GtkWidget *numtelephone;

   GtkWidget *MNmodif;
GtkWidget *outputMsg;
GtkWidget *outputMsg1;
GtkWidget *outputMsg2;
GtkWidget *outputMsg3;
GtkWidget *outputMsg4;
GtkWidget *outputMsg5;
GtkWidget *outputMsg6;
GtkWidget *outputMsg7;
GtkWidget *outputMsg8;
GtkWidget *outputMsg9;
GtkWidget *outputMsg10;

char text[100];char text1[200]; char text2[200]; char text3[200]; char text4[200];char text5[200]; char text6[200]; char text7[200]; char text8[200];
char text9[200];char text10[200];

  
MNmodif=lookup_widget(button,"MNmodif");
//////////
nom = lookup_widget(button, "MN_modifentrynom");
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
//////////
prenom = lookup_widget(button, "MN_modifentryprenom");
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
//////////
cin = lookup_widget(button, "MN_entrymodifcin");
strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
//////////
jour = lookup_widget(button, "MN_modifjourspin");
mois = lookup_widget(button, "MN_modifmoisspin");
annee = lookup_widget(button, "MN_modifanneespin");
u.date_naissance.jour =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
u.date_naissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
u.date_naissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
//////////
username = lookup_widget(button, "MN_entrymodifid");
strcpy(u.username,gtk_entry_get_text(GTK_ENTRY(username)));
//////////
password = lookup_widget(button, "MN_modifentrypass");
strcpy(u.password,gtk_entry_get_text(GTK_ENTRY(password)));
//////////
rolecombobox= lookup_widget(button, "MN_comboboxmodif");
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(rolecombobox)));
//////////
adresse = lookup_widget(button, "MN_adresseentrymodif");
strcpy(u.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
//////////
mail = lookup_widget(button, "MN_mailmodifentry");
strcpy(u.mail,gtk_entry_get_text(GTK_ENTRY(mail)));
//////////
numtelephone = lookup_widget(button, "MN_numtelmodifentry");
strcpy(u.numtelephone,gtk_entry_get_text(GTK_ENTRY(numtelephone)));
/////////
strcpy(u.sexe,"Femelle");
if(xMN==1)
{strcpy(u.sexe,"Femelle");}
else
if(xMN==2)
{strcpy(u.sexe,"Male");}
int mnverifmodif=0;

 if (MNverifier_lettre (u.nom)==0 ||(strcmp(u.nom,"")==0))
        {mnverifmodif=1;
         strcpy (text1,"Verifier votre nom !");
         outputMsg1=lookup_widget(button,("MN_verifmodifnom"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg1,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg1),text1);
        }
     
      if (MNverifier_lettre (u.prenom)==0 ||(strcmp(u.prenom,"")==0))
        {mnverifmodif=1;
         strcpy (text2,"Verifier votre prenom !");
         outputMsg2=lookup_widget(button,("MN_verifmodifprenom"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg2,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg2),text2);
        }

      if (MNverifier_cin (u.cin)==0 || (strcmp(u.cin,"")==0)) 
        {mnverifmodif=1;
         strcpy (text3,"Verifier le numero cin  !");
         outputMsg3=lookup_widget(button,("MN_verifmodifcin"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg3,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg3),text3);
        }

      

     if (MNverifier_passiden (u.password)==0 || (strcmp(u.password,"")==0))
        {mnverifmodif=1;
         strcpy (text5,"le mot de passe doive contenir 5 carecteres des lettres et des chiffres !");
         outputMsg5=lookup_widget(button,("MN_verifmodifpass"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg5,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg5),text5);
        }

     

     if ( (strcmp(u.adresse,"")==0))
        {mnverifmodif=1;
         strcpy (text7," Verifier l'adresse !");
         outputMsg7=lookup_widget(button,("MN_verifmodifadresse"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg7,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg7),text7);
        }

    if (MNverifier_email (u.mail)==0 || (strcmp(u.mail,"")==0))
        {mnverifmodif=1;
         strcpy (text8," Verifier le mail !");
         outputMsg8=lookup_widget(button,("MN_verifmodifmail"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg8,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg8),text8);
        }


    if (MNverifier_cin (u.numtelephone)==0 || (strcmp(u.numtelephone,"")==0)) 
        {mnverifmodif=1;
         strcpy (text9,"Verifier le numero telephone  !");
         outputMsg9=lookup_widget(button,("MN_verifmodifnumero"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg9,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg9),text9);
        }

    if (mnverifmodif==0)
    {
    modifier_utilisateur(u);
    strcpy(text,"Modification effectué avec succes");
    outputMsg=lookup_widget(button,("MN_reumodif"));
    GdkColor color;
    gdk_color_parse("green",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }

} 
////////////////////////////////////////////////////////////////////
void
on_MN_retourmodifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *MNaccueil;
GtkWidget *MNmodif;
GtkWidget *MNtreeview1;

MNmodif=lookup_widget(button,"MNmodif");
gtk_widget_destroy(MNmodif);
MNaccueil=lookup_widget(button,"MNaccueil");
MNaccueil=create_MNaccueil();
gtk_widget_show(MNaccueil);
MNtreeview1=lookup_widget(MNaccueil,"MNtreeview1");
afficher_utilisateur(MNtreeview1);
gtk_widget_destroy(MNmodif);
}


////////////////////////////////////////////////////////////////////
void
on_MN_radiofemellemodif_toggled        (GtkToggleButton *toggle_button,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(toggle_button)))
{
xMN=1;
}
}

////////////////////////////////////////////////////////////////////
void
on_MN_radiomalemodif_toggled           (GtkToggleButton *toggle_button,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(toggle_button)))
{
xMN=2;
}
}






////////////////////  Tache suppression ////////////////////////////////////////////////

void
on_MNsupprimer_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
char text[100];
GtkWidget *outputMsg;
GtkWidget *MNaccueil;
GtkWidget *MNsupprime;
GtkWidget *MNtreeview1;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
	gchar *username;
	gchar *nom;
	gchar *prenom; 
	gchar *sexe; 
	gchar *cin;
 	gchar *password;
	gchar *jour; 
        gchar *mois;
        gchar *annee;
	gchar *role; 
        gchar *adresse;
        gchar *mail;
	gchar *numtelephone;
        users u;               
	

GtkWidget *input0;

MNaccueil=lookup_widget(button,"MNaccueil");
MNtreeview1=lookup_widget(MNaccueil,"MNtreeview1");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(MNtreeview1));

if(gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&username,1,&nom,2,&prenom,3,&sexe,4,&cin,5,&password,6,&jour,7,&mois,8,&annee,9,&role,10,&adresse,11,&mail,12,&numtelephone,-1);
	
	strcpy(u.username,username);
	strcpy(u.nom,nom);
	strcpy(u.prenom,prenom);
	strcpy(u.sexe,sexe);
	strcpy(u.cin,cin);
	strcpy(u.password,password);
        u.date_naissance.jour=jour;
        u.date_naissance.mois=mois;
        u.date_naissance.annee=annee; 
	strcpy(u.role,role);
        strcpy(u.adresse,adresse);
	strcpy(u.mail,mail);
        strcpy(u.numtelephone,numtelephone);

gtk_widget_destroy(MNaccueil);
MNsupprime=create_MNsupprime();
gtk_widget_show(MNsupprime);
input0=lookup_widget(MNsupprime,"MN_idensuppentry");
gtk_entry_set_text (GTK_ENTRY(input0),u.username);
}
else
{
         strcpy (text,"veuillez selectionner l'utilisateur à supprimer !");
         outputMsg=lookup_widget(button,("MN_selection"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
}

////////////////////////////////////////////////////////////////////
int MNconf=0;
int *MNr=&MNconf;
void
on_MN_buttonsupprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
users u;
GtkWidget *MNsupprime;
GtkWidget *MNaccueil;
GtkWidget *MNtreeview1;
GtkWidget *outputMsg;
GtkWidget *input1;
char ident[20];
char text[200];
MNsupprime=lookup_widget(button,"MNsupprime");
input1=lookup_widget(button,"MN_idensuppentry");   
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));
if(MNconf)
{
supprimer_utilisateur(ident);
strcpy (text,"utilisateur supprimé avec succès");
outputMsg=lookup_widget(button,("MN_msgsupp"));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
else
{
strcpy (text,"La confirmation est obligatoire!");
outputMsg=lookup_widget(button,("MN_msgsupp"));
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
}
////////////////////////////////////////////////////////////////////
void
on_MN_retoursupprimer_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *MNsupprime;
GtkWidget *MNtreeview1;
GtkWidget *MNaccueil;

MNsupprime=lookup_widget(button,"MNsupprime");
gtk_widget_destroy(MNsupprime);
MNaccueil=create_MNaccueil();
gtk_widget_show(MNaccueil);
MNtreeview1=lookup_widget(MNaccueil,"MNtreeview1");
afficher_utilisateur(MNtreeview1);
}
//////////////////////////////////////////////////////////////////////
void
on_MN_checkconfirm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
*MNr=1;
else
*MNr=0;
}






/////////////////////// Tache recherche /////////////////////////////////////////////
void
on_MN_rechercheracc_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* MNaccueil;
MNaccueil=lookup_widget(button,"MNaccueil");
gtk_widget_destroy(MNaccueil);
GtkWidget* MNcherche;
MNcherche=create_MNcherche();
gtk_widget_show(MNcherche);
}
////////////////////////////////////////////////////////////////////
void
on_MN_chercherbutton_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *MNcherche;
   GtkWidget *ident;
   GtkWidget *MNtreeview2;
   GtkWidget *output;
   int verif;
   char text[200];
   char id[20];
   
MNcherche=lookup_widget(button,"MNcherche");
ident=lookup_widget(button,"MN_entryidchercher");
MNtreeview2=lookup_widget(button,"MNtreeview2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(ident)));
verif=test_utilisateur(id);

switch(verif)
    
{
    case 0:  
    { strcpy (text,"utilisateur n'existe pas");
    output=lookup_widget(button,("MN_textrechercher"));
    gtk_label_set_text(GTK_LABEL(output),text);
    }
    break;
    case 1:
  
    {  rechercher_utilisateur(MNtreeview2, id);
       remove(MNtreeview2);
       strcpy (text,"utilisateur existe");
       output=lookup_widget(button,("MN_textrechercher"));
       gtk_label_set_text(GTK_LABEL(output),text);
      }
    break; 
    break;
}

}
////////////////////////////////////////////////////////////////////
void
on_MN_retourchercher_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* MNcherche;
MNcherche=lookup_widget(button,"MNcherche");
gtk_widget_destroy(MNcherche);
GtkWidget* MNaccueil;
MNaccueil=create_MNaccueil();
gtk_widget_show(MNaccueil);
}




///////////////////////// MN treeview1 ///////////////////////////////////////////
void
on_MNtreeview1_row_activated           (GtkTreeView     *tree_view,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *username;
	gchar *nom;
	gchar *prenom; 
	gchar *sexe; 
	gchar *cin;
 	gchar *password;
	gchar *jour; 
        gchar *mois;
        gchar *annee;
	gchar *role; 
        gchar *adresse;
        gchar *mail;
	gchar *numtelephone;
        users u;                                 
	FILE *f=NULL;


	GtkTreeModel *tree_model = gtk_tree_view_get_model(tree_view);
	if (gtk_tree_model_get_iter(tree_model,&iter,path))
	{gtk_tree_model_get (GTK_LIST_STORE(tree_model),&iter,0,&username,1,&nom,2,&prenom,3,&sexe,4,&cin,5,&password,6,&jour,7,&mois,8,&annee,9,&role,10,&adresse,11,&mail,12,&numtelephone,-1);

	strcpy(u.username,username);
	strcpy(u.nom,nom);
	strcpy(u.prenom,prenom);
	strcpy(u.sexe,sexe);
	strcpy(u.cin,cin);
	strcpy(u.password,password);
        u.date_naissance.jour=jour;
        u.date_naissance.mois=mois;
        u.date_naissance.annee=annee; 
	strcpy(u.role,role);
        strcpy(u.adresse,adresse);
	strcpy(u.mail,mail);
        strcpy(u.numtelephone,numtelephone);
        afficher_utilisateur(tree_view);
}
}
/////////////////////////// MN treeview2 /////////////////////////////////////////
void
on_MNtreeview2_row_activated           (GtkTreeView     *tree_view,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *username;
	gchar *nom;
	gchar *prenom; 
	gchar *sexe; 
	gchar *cin;
 	gchar *password;
	gchar *jour; 
        gchar *mois;
        gchar *annee;
	gchar *role; 
        gchar *adresse;
        gchar *mail;
	gchar *numtelephone;
        users u;                              
	FILE *f=NULL;



	GtkTreeModel *tree_model = gtk_tree_view_get_model(tree_view);

	if (gtk_tree_model_get_iter(tree_model,&iter,path))
	{gtk_tree_model_get (GTK_LIST_STORE(tree_model),&iter,0,&username,1,&nom,2,&prenom,3,&sexe,4,&cin,5,&password,6,&jour,7,&mois,8,&annee,9,&role,10,&adresse,11,&mail,12,&numtelephone,-1);

	strcpy(u.username,username);
	strcpy(u.nom,nom);
	strcpy(u.prenom,prenom);
	strcpy(u.sexe,sexe);
	strcpy(u.cin,cin);
	strcpy(u.password,password);
        u.date_naissance.jour=jour;
        u.date_naissance.mois=mois;
        u.date_naissance.annee=annee; 
	strcpy(u.role,role);
        strcpy(u.adresse,adresse);
	strcpy(u.mail,mail);
        strcpy(u.numtelephone,numtelephone);
        afficher_utilisateur(tree_view);
}

}


////////////////////////////////////////////////////////////////////
void
on_MN_afficheraccu_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* MNtreeview1;
GtkWidget* MNaccueil;

MNaccueil=lookup_widget(button,"MNaccueil");
MNtreeview1=lookup_widget(MNaccueil,"MNtreeview1");
afficher_utilisateur(MNtreeview1);
}

///////////////////////  Tache 2 /////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void
on_MN_buttontache2_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *MNaccueil;
GtkWidget *MNetagepanne;
GtkWidget *MNtreeview3;

MNaccueil=lookup_widget(button,"MNaccueil");
gtk_widget_destroy(MNaccueil);
MNetagepanne=lookup_widget(button,"MNetagepanne");
MNetagepanne=create_MNetagepanne();
gtk_widget_show(MNetagepanne);
MNtreeview3=lookup_widget(MNetagepanne,"MNtreeview3");
etage_debit(MNtreeview3);
//afficher_etage(MNtreeview3);
remove(MNtreeview3);
gtk_widget_destroy(MNaccueil);
}
/////////////////////////////////////////////////////////////////////

void
on_MNtreeview3_row_activated           (GtkTreeView     *tree_view,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *jourpanne;
	gchar *heure;
	gchar *etage; 
	gchar *valeur; 
        debit d;                                 
	FILE *f=NULL;


	GtkTreeModel *tree_model = gtk_tree_view_get_model(tree_view);
	if (gtk_tree_model_get_iter(tree_model,&iter,path))
	{gtk_tree_model_get (GTK_LIST_STORE(tree_model),&iter,0,&jourpanne,1,&heure,2,&etage,3,&valeur,-1);


	d.etage=etage;
        d.jourpanne=jourpanne;
        d.heure=heure;
        strcpy(d.valeur,valeur);
	afficher_etage(tree_view);
}
}

/////////////////////////////////////////////////////////////////////

void
on_MN_retourtache2_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* MNetagepanne;
MNetagepanne=lookup_widget(button,"MNetagepanne");
gtk_widget_destroy(MNetagepanne);
GtkWidget* MNaccueil;
MNaccueil=create_MNaccueil();
gtk_widget_show(MNaccueil);
}


//////////////////////////// authentification ////////////////////////

void
on_MN_login_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *outputMsg;
GtkWidget *username;
GtkWidget *password;
GtkWidget *MN_role;

char text[100];
users u;
int MNtrouve;
char MNcompare[50];
char username1[50];
char password1[50];
char role1[50];

username = lookup_widget (button, "MN_authuser");
password = lookup_widget (button, "MN_authpass");
MN_role = lookup_widget (button, "MN_role");
strcpy(username1 ,gtk_entry_get_text ( GTK_ENTRY(username)));
strcpy(password1 ,gtk_entry_get_text ( GTK_ENTRY(password)));
strcpy(role1 ,gtk_entry_get_text ( GTK_ENTRY(MN_role)));
MNtrouve=verif_authen(username1,password1,role1);

//strcpy(MNcompare,MN_authenrole(u.username,u.password));
if (MNtrouve==1)
{
/*if (strcmp(MNcompare,"Agent_de _foyer")==0)
{
GtkWidget *MNauthentification;
GtkWidget *            ;
GtkWidget *            ;

MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
...........=lookup_widget(button,".........");
..........=create_..........();
gtk_widget_show(.........);
............=lookup_widget(...........,"...........");
afficher_(...........); //fonction affichage    
}*/
//////////////////////////////////////////    
/*if (strcmp(MNcompare,"Agent_de_reclamation")==0)
{
GtkWidget *MNauthentification;
GtkWidget *            ;
GtkWidget *            ;

MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
...........=lookup_widget(button,".........");
..........=create_..........();
gtk_widget_show(.........);
............=lookup_widget(...........,"...........");
afficher_(...........); //fonction affichage    
}*/
//////////////////////////////////////////
/*if (strcmp(MNcompare,"Nutrisionniste")==0)
{
GtkWidget *MNauthentification;
GtkWidget *            ;
GtkWidget *            ;

MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
...........=lookup_widget(button,".........");
..........=create_..........();
gtk_widget_show(.........);
............=lookup_widget(...........,"...........");
afficher_(...........); //fonction affichage  
}*/
//////////////////////////////////////////
/*if (strcmp(MNcompare,"Technicien")==0)
{
GtkWidget *MNauthentification;
GtkWidget *            ;
GtkWidget *            ;

MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
...........=lookup_widget(button,".........");
..........=create_..........();
gtk_widget_show(.........);
............=lookup_widget(...........,"...........");
afficher_(...........); //fonction affichage    
} */
//////////////////////////////////////////  
/*if (strcmp(MNcompare,"Etudiant")==0)
{
GtkWidget *MNauthentification;
GtkWidget *            ;
GtkWidget *            ;

MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
...........=lookup_widget(button,".........");
..........=create_..........();
gtk_widget_show(.........);
............=lookup_widget(...........,"...........");
afficher_(...........); //fonction affichage    
}*/
//////////////////////////////////////////
/*if (strcmp(MNcompare,"Agent_de_club")==0)
{
GtkWidget *MNauthentification;
GtkWidget *            ;
GtkWidget *            ;

MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
...........=lookup_widget(button,".........");
..........=create_..........();
gtk_widget_show(.........);
............=lookup_widget(...........,"...........");
afficher_(...........); //fonction affichage      
} */
//////////////////////////////////////////  
/*if (strcmp(MNcompare,"Agent_de_stock")==0)
{
GtkWidget *MNauthentification;
GtkWidget *            ;
GtkWidget *            ;

MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
...........=lookup_widget(button,".........");
..........=create_..........();
gtk_widget_show(.........);
............=lookup_widget(...........,"...........");
afficher_(...........); //fonction affichage  
}*/
//////////////////////////////////////////
if ( strcmp(role1,"Administrateur")==0)
{
GtkWidget *MNauthentification;
GtkWidget *MNaccueil;
GtkWidget *MNtreeview1;

MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
MNaccueil=create_MNaccueil();
gtk_widget_show(MNaccueil);
MNtreeview1=lookup_widget(MNaccueil,"MNtreeview1");
afficher_utilisateur(MNtreeview1);
}
}


else
{
    strcpy (text,"Merci de verifier les informations");
    outputMsg=lookup_widget(button,("MN_erreur"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
}


}
////////////////////////// menu ///////////////////////////////////
void
on_MN_entrytdashbord_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_MN_entryauth_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* MNmenu;
MNmenu=lookup_widget(button,"MNmenu");
gtk_widget_destroy(MNmenu);
GtkWidget* MNauthentification;
MNauthentification=create_MNauthentification();
gtk_widget_show(MNauthentification);
}


void
on_MN_retourauthen_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* MNauthentification;
GtkWidget* MNmenu;


MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
MNmenu=lookup_widget(button,"MNmenu");
MNmenu=create_MNmenu();
gtk_widget_show(MNmenu);
}

