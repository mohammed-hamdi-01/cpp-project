#include "classes.h"
int main()
{              
int choix_admin;
string retour;
parcVoiture p;
reservation demande; 
fstream f;
p.creer(f);
demande.creer(f);
LOOP: cout<<"//////session Admin//////"<<endl;
cout<<"\n menu des fonctionnalités pour l'admin:"<<endl;
cout<<"\n 1-saisir et enregistrer les voitures du parking"<<endl;
cout<<"\n 2-supprimer les voitures accidentées"<<endl;
cout<<"\n 3-saisir et enregistrer une reservation"<<endl;
cout<<"\n 4-supprimer une reservation"<<endl;
cout<<"\nveuillez ecrire le numéro de la fonctionnalité"<<endl;
cin>>choix_admin;
if (choix_admin==1)
{
    int nombre_voitures;
    cin>>nombre_voitures;
    for (int i=0;i<nombre_voitures;i++){
      cin>>p;
      f<<p<<endl;
    }
    f.seekg(0);
    while(1){
        f>>p;
        if (f.eof()) break;    
        cout<<p;}
    f.close();
}
else if (choix_admin==2)
{   p.supprimer_voiture();
    cout<<p;
    cout<<"\nles voitures accidentées ont étés supprimées\n"<<endl;
}
else if (choix_admin==3)
{
    int nombre_des_demandes;
    cin>>nombre_des_demandes;
    for (int i;i<nombre_des_demandes;i++){
    cin>>demande;
    f<<demande<<endl;
    }
    cin>>demande;
    f<<demande<<endl;
    f.seekg(0);
    while(1){
    f>>demande;
    if (f.eof()) break;    
    cout<<demande;}
    f.close();
}

else if (choix_admin==4)
{ int ident_reserv;
  cin>>ident_reserv;
  demande.supprimer_reserv(ident_reserv);
  cout<<demande;
}
cout<<"\n pour retourner au menu des fonctionnalités admin tapez oui, sinon tapez non\n"<<endl;
cin>>retour;
if(retour=="oui"){
    goto LOOP;
}
else{ 
int choix;
MENU_UTILISATEUR:cout<<"\n se connecter comme :"<<endl;
cout<<"\n 1-chauffeur"<<endl;
cout<<"\n 2-fonctionnaire"<<endl;
cout<<"Veuillez ecrire le numéro de votre choix de connexion"<<endl;
cin>>choix;
if (choix==1){
    
    LOOP_CHAUFFEUR: cout<<"\n menu des fonctionnalités pour les chauffeurs et les fonctionnaires n'yant pas de voitures de fonction:"<<endl;
    cout<<"\n 1-reserver une voiture"<<endl;
    cout<<"\n 2-consulter une voiture"<<endl;
    cout<<"\n 3-consulter la liste des voitures dans le parking"<<endl;
    cout<<"\nveuillez ecrire le numéro de la fonctionnalité"<<endl;
    int choix_chauffeur;
    cin>>choix_chauffeur;
    if(choix_chauffeur==1){
        cin>>demande;
        cout<<" demande enregistrée "<<endl;
        cout<<demande;
        /*f<<demande<<endl;
        f.seekg(0);
        while(1){
        f>>demande;
        if (f.eof()) break;    
        cout<<demande;}
        f.close();*/
    }
    else if (choix_chauffeur==2)
    { int mat;
      cout<<"ecrire le numero de la matricule"<<endl;
      cin>>mat;
      p.consulter_voiture(mat);
    }
    else if (choix_chauffeur==3)
    {
        cout<<p<<endl;
    }
    string retour_menu;
    cout<<"\n pour retourner au menu des fonctionnalités chauffeur tapez oui, si vous voulez deconnecter, tapez deconnexion\n"<<endl;
    cin>>retour_menu;
    if(retour_menu=="oui"){
        goto LOOP_CHAUFFEUR;
    }
    else if (retour_menu=="deconnexion")
    {
        goto MENU_UTILISATEUR;
    }
}
else if (choix==2)
{   int choix_fonctionnaire;
    LOOP_fct:cout<<"\n avez vous une voiture de fonction ou avez vous besoin de reserver une voiture ?"<<endl;
    cout<<"\n 1-reserver une voiture pour une courte durée"<<endl;
    cout<<"\n 2-j'ai deja une voiture de fonction"<<endl;
    cout<<"\nveuillez ecrire le numéro de votre choix"<<endl;
    cin>>choix_fonctionnaire;
    if(choix_fonctionnaire==1){
       goto LOOP_CHAUFFEUR;
    }
    else if (choix_fonctionnaire==2)
    { cout<<"\n 2-consulter une voiture"<<endl;
      cout<<"\n 3-consulter la liste des voitures dans le parking"<<endl;
    }
    string retour_menu;
    cout<<"\n pour retourner au menu des types de fonctionnaires tapez oui, si vous voulez deconnecter, tapez deconnexion\n"<<endl;
    cin>>retour_menu;
    if(retour_menu=="oui"){
        goto LOOP_fct;
    }
    else if (retour_menu=="deconnexion")
    {
        goto MENU_UTILISATEUR;
    }
}    
}

}
