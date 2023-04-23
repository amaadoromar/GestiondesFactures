#include <iostream>
#include <math.h>

using namespace std;



class Produit{
    int identifiant;
    string nom;
    string description;
    float prixunitaire;
    int quantite;

    public:
    Produit();
    bool operator==(Produit& a);
    Produit(int identifiant,string nom,string description,float prixunitaire,int quantite)
    :identifiant(identifiant),nom(nom),description(description),prixunitaire(prixunitaire),quantite(quantite){};
    void Affichage();
    void Modification();
    int getQuantite(){return quantite;};
    float getPrixunitaire(){return prixunitaire;};
    float getTotal(){return prixunitaire*quantite;};
};

