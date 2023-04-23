#include "date.h"
#include "client.h"
#include "produit.h"
#include "facture.h"

extern int indiceall;
extern Facture* allfactures;

Facture :: Facture(int code,Client client,bool etat=false):code(code),client(client),etat(etat){allfactures=this;indiceall++;};
Facture :: Facture(int code,Client client,bool etat=false,string datecreation="10/10/1990"){
     this->code = code;
     this->client = client;
     this->etat = etat;
     this->datecreation = datecreation;
     allfactures=this;indiceall++;
};

Facture :: Facture(int code,Client client,Produit produit,bool etat=false,string datecreation="10/10/1990"){
     this->code = code;
     this->client = client;
     this->etat = etat;
     this->datecreation = datecreation;
     this->addproduct(produit);
     allfactures=this;indiceall++;
};

void Facture :: editProduitbyIndex(int indice){
    produits[indice].Modification();
}

string Facture :: getDatecreation(){return datecreation;};

void Facture :: setEtat(bool etat){this->etat = etat;};

Facture :: Facture(){};
bool Facture :: operator==(Facture& a){
    if(this->code==a.code)
        return true;
    else
        return false;
}

void Facture :: setstate(){
    if(etat){ etat = false;}else{etat=true;};
    cout << "Etat a ete change"<<endl;
}

void Facture :: changestate(Facture factures[],int& indice){
    if(etat){ etat = false;}else{etat=true;};
    cout << "Etat a ete change"<<endl;
}

void Facture :: ajouterautableau(Facture factures[],int& indice){
   factures[indice] = *this;
   indice++;
}

bool Facture :: searchfacturetableau(Facture factures[],int& indice){
  for(unsigned int i=0;i<=indice;i++){
    if(factures[i]==*this){
        return true;
    }
  }
    return false;
}


Client Facture :: getClient(){
    return client;
}

void Facture :: editClient(){
   client.modifier();
}
void Facture :: Affichage(){
    cout<<"------------------------------"<<endl;
    cout<<"Le code de la facture : "<<code<<endl;
    cout<<"Statut de la facture : ";
    if(etat)
        cout<<"paid"<<endl;
    else
        cout<<"unpaid"<<endl;
    cout<<"Le client : ";
    client.afficher();
    cout<<"Les produits : "<<endl;
    for(int i=0;i<produits.size();i++){
        produits[i].Affichage();
    }
    cout<<"Le montant total a payer est : "<< Total()<< " DH"<<endl;
    cout<<"------------------------------"<<endl;
}

bool Facture :: testclient(Client& c){
    if(client.getId() == c.getId())
        return true;
    else
        return false;
}


void Facture :: addproduct(Produit a){
        produits.push_back(a);
}

void Facture :: addtotable(Facture factures[],int& indice){
   factures[indice] = *this;
}

void Facture :: editproduct(){
    int i = -1;
     do{
     cout<< "Quel est le produit que vous voulez modifier ? "<<endl;
     showproducts();
     cin >>i;
     }while(i > produits.size());

     if(i != -1){
        produits[i].Modification();
        showproducts();
     }

}

void Facture :: editclient(){
   cout << "Modifier le client : "<<endl;
   client.modifier();
}



void Facture :: showproducts(){
    for(unsigned int i = 0; i < produits.size(); i++)
    {
        cout<<"Produit N*"<<i<< " : "<<endl;
        produits[i].Affichage();
    }
}

int Facture :: searchproduct(Produit& a){
       int indice;
       bool exist = false;
    for(unsigned int i = 0; i < produits.size(); i++)
    {
        if(produits[i]==a){indice=i;exist=true;break;};
    }
    if(exist){return indice;}
    else return -1;
}

void Facture :: deleteproduct(Produit& a){
  if(searchproduct(a) != -1){
    int indice = searchproduct(a);
     produits.erase (produits.begin()+indice);
  }
}

float Facture :: Total(){
    float total=0;
 for(unsigned int i = 0; i < produits.size(); i++)
    {
        total=total+produits[i].getPrixunitaire();
    }
    return total;
}

vector <Produit> Facture :: getProduits(){
   return produits;
}



