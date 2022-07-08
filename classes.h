#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<iomanip>
#include<fstream>
class voiture
{
string marque;
string modele;
float prix;
int emplacement;
public:
int matricule;
string etat;
voiture*suivant;
voiture(int=0,string ="", string="", float=0.0, int=0, string="");
~voiture();
friend ostream& operator<< (ostream&, voiture&);
friend istream& operator>> (istream&, voiture&);
};
class demande_de_reservation{
string date_de_reservation;
string fin_de_reservation;
voiture voiture_demande;
public:
demande_de_reservation*suivant;
int id_demande;
~demande_de_reservation();
friend ostream& operator<< (ostream&, demande_de_reservation&);
friend istream& operator>> (istream&, demande_de_reservation&);
};
class reservation{
    demande_de_reservation*premier;
    demande_de_reservation*courant;
    public:
    reservation(void);
    ~reservation();
    static void creer(fstream&);
    void inserer_reserv(demande_de_reservation*);
    void supprimer_reserv(int);
    void supprimer();
    friend ostream& operator<< (ostream&, reservation&);
    friend istream& operator>> (istream&, reservation&);
};
class parcVoiture
{
voiture*premier;
voiture*courant;
public:
parcVoiture(void);
~parcVoiture(void);
static void creer(fstream&);
void inserer(voiture*);
void supprimer();
void supprimer_voiture();
void consulter_voiture(int);
friend ostream& operator<< (ostream&, parcVoiture&);
friend istream& operator>> (istream&, parcVoiture&);
friend istream& operator>> (istream&, parcVoiture*);};
