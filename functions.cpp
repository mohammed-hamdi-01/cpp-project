#include "classes.h"
////////////////methodes de la classe voiture//////////////////
voiture::voiture(int mat, string ma, string mo, float p, int emp, string et )
{
matricule=mat;    
marque=ma;
modele=mo;
prix=p;
emplacement=emp;
etat=et;
suivant=NULL;
}
voiture::~voiture(void)
{ }
ostream& operator<< (ostream& out, voiture& v)
{
out<<"\n la marque de la voiture: \n"<<setw(10)<<v.marque<<"\n le modele de la voiture: \n"<<setw(10)<<v.modele<<"\n le prix de la voiture: \n"<<setw(10)<<v.prix<<"\n l'emplacement de la voiture dans le parking: \n"<<setw(10)<<v.emplacement<<"\n l'etat de la voiture: \n"<<setw(10)<<v.etat<<"\n la matricule de la voiture: \n"<<setw(10)<<v.matricule;
return out;
}
istream& operator>> (istream& in, voiture& v)
{
cout<<"\necrire le numero de la matricule\n" <<endl;  
in>>v.matricule;
cout<<"\necrire la marque de la voiture\n" <<endl;    
in>>v.marque;
cout<<"\necrire le modele de la voiture\n" <<endl;
in>>v.modele;
cout<<"\necrire le prix de la voiture\n" <<endl;
in>>v.prix;
cout<<"\necrire l'emplacement de la voiture\n" <<endl;
in>>v.emplacement;
cout<<"\necrire l'etat de la voiture\n" <<endl;
in>>v.etat;
return in;
}
///////////////methodes de la classe parcvoiture/////////////
parcVoiture::parcVoiture(void)
{
premier=NULL;
courant=NULL;
}
parcVoiture::~parcVoiture(void)
{
while(premier!=NULL)
supprimer();
}
void parcVoiture::inserer(voiture *v)
{
v->suivant=premier;
premier=v;
}
void parcVoiture::supprimer_voiture(){
courant=premier;    
while (courant!=NULL){
if (courant->etat=="accidentée"){
 delete courant;
}
else{
    courant=courant->suivant;
}
}
}
void parcVoiture::supprimer()
{
if(premier!=NULL)
{
courant=premier;
premier=premier->suivant;
delete courant;
}
}
void parcVoiture::consulter_voiture(int mat){
courant=premier;
bool test=true;    
while (test){
if (courant->matricule==mat){
  cout<<*courant;
}
else{
    courant=courant->suivant;
}
}
}
ostream& operator<< (ostream& out, parcVoiture& p)
{
p.courant=p.premier;
while(p.courant!=NULL)
{
out<<*p.courant<<endl;
p.courant=p.courant->suivant;
}
return out;
}
istream& operator>> (istream& in, parcVoiture& p)
{
voiture*v;
char rep;
v=new voiture;
in>>*v;
p.inserer(v);
cout<<"voiture ajoutée"<<endl;
return in;
}
istream& operator>> (istream& in, parcVoiture* p)
{
voiture*v;
char rep;
in.seekg(0);
while(1)
{
v=new voiture;
in>>*v;
if(in.eof()) break;
p->inserer(v);
}
return in;
}
void parcVoiture::creer(fstream& f)
{
f.open("d:\\parcVoitures.txt", ios::in |ios::out |ios::trunc);
if(! f.is_open()) exit(-1);
}
///////////////////methodes de la classe demande de reservation//////////////////
demande_de_reservation::~demande_de_reservation(void)
{ }
ostream& operator<< (ostream& out, demande_de_reservation& dem_reserv)
{
out<<"\n la date de debut de la reservation: \n"<<setw(10)<<dem_reserv.date_de_reservation<<"\n la date de fin de la reservation: \n"<<setw(10)<<dem_reserv.fin_de_reservation<<"\n les caractéristques de la voiture demandée: \n"<<setw(10)<<dem_reserv.voiture_demande<<"\n le code de votre demande: \n"<<setw(10)<<dem_reserv.id_demande;
return out;
}
istream& operator>> (istream& in, demande_de_reservation& dem_reserv )
{
cout<<"\necrire la date de debut de la reservation\n" <<endl;
in>>dem_reserv.date_de_reservation;
cout<<"\necrire la date de fin de la reservation\n" <<endl;
in>>dem_reserv.fin_de_reservation;
cout<<"\necrire les caractéristiques de la voiture\n" <<endl;
in>>dem_reserv.voiture_demande;
cout<<"\necrire un code unique pour votre reservation\n" <<endl;
in>>dem_reserv.id_demande;
return in;}
/////////////////////////methodes de la classe reservation/////////////////
reservation::reservation(void)
{
premier=NULL;
courant=NULL;
}
reservation::~reservation(void)
{
while(premier!=NULL)
supprimer();
}
void reservation::inserer_reserv(demande_de_reservation *dem_reserv)
{
dem_reserv->suivant=premier;
premier=dem_reserv;
}
void reservation::supprimer_reserv(int ident)
{
bool test=true;
courant=premier;
while (test){
if (courant->id_demande==ident){
cout<<*courant;    
delete courant;
test=false;
}
else{
    courant=courant->suivant;
}
}
}
void reservation::supprimer(){
    if(premier!=NULL)
{
courant=premier;
premier=premier->suivant;
delete courant;
}
}
ostream& operator<< (ostream& out, reservation& reserv)
{
reserv.courant=reserv.premier;
while(reserv.courant!=NULL)
{
out<<*reserv.courant<<endl;
reserv.courant=reserv.courant->suivant;
}
return out;
}
istream& operator>> (istream& in, reservation& reserv)
{
demande_de_reservation*dem_reserv;
dem_reserv=new demande_de_reservation;
in>>*dem_reserv;
reserv.inserer_reserv(dem_reserv);
cout<<"\n la demande a été ajoutée "<<endl;
return in;
}
istream& operator>> (istream& in, reservation* reserv)
{
demande_de_reservation*dem_reserv;
char rep;
in.seekg(0);
while(1)
{
dem_reserv=new demande_de_reservation;
in>>*dem_reserv;
if(in.eof()) break;
reserv->inserer_reserv(dem_reserv);
}
return in;
}
void reservation::creer(fstream& f)
{
f.open("d:\\reservations.txt", ios::in |ios::out |ios::trunc);
if(! f.is_open()) exit(-1);
}

