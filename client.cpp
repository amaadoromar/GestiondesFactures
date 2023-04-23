
#include "client.h"


Client :: Client(){};
bool Client :: operator==(Client& a){
    if(this->identifiant==a.identifiant)
        return true;
    else
        return false;
}
void Client :: setNom(string nom){this->nom=nom;};
void Client :: setPrenom(string prenom){this->prenom=prenom;};
void Client :: setAdresse(string adresse){this->adresse=adresse;};
void Client :: setId(int identifiant){this->identifiant = identifiant;};

int Client :: getId(){return identifiant;};
string Client :: getNom(){return nom;};
string Client :: getPrenom(){return prenom;};
string Client :: getAdresse(){return adresse;};

void Client :: afficher(){cout << this->identifiant << "-" << this->nom << "-" << this->prenom << "-" << this->adresse << endl;};
void Client :: modifier(){
    cout << "Nom :" <<endl;
    cin >> nom;
    cout << "Prenom :" <<endl;
    cin >> prenom;
    cout << "Adresse :" <<endl;
    cin >> adresse;};
