#include "produit.h"



Produit :: Produit(){};
bool Produit :: operator==(Produit& a){
    if(this->identifiant==a.identifiant)
        return true;
    else
        return false;
}
void Produit :: Affichage(){
    cout<<"-----------------------"<<endl;
    cout<<"identifiant : "<<identifiant<<endl;
    cout<<"Le nom : "<<nom<<endl;
    cout<<"Description : "<<description<<endl;
    cout<<"Prix unitaire : "<<prixunitaire << " DH"<<endl;
    cout<<"Quantite : "<<quantite<<endl;
    cout<<"-----------------------"<<endl;
}

void Produit :: Modification(){

    cout<<"Le nom : "<<endl;
    cin >> nom;
    cout<<"Description : "<<endl;
    cin >> description;
    cout<<"Prix unitaire : "<<endl;
    cin >> prixunitaire;
    cout<<"Quantite : "<<endl;
    cin >>quantite;
}
