#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


class Facture{
     int code;
     Client client;
     vector <Produit> produits;
     string datecreation;
     bool etat;

      public:
      Facture();
      Facture(int code,Client client,bool etat);
      Facture(int code,Client client,bool etat,string datecreation);
      Facture(int code,Client client,Produit produit,bool etat,string datecreation);
      void editClient();
      void addtotable(Facture factures[],int& indice);
      void editProduitbyIndex(int indice);
      bool operator==(Facture& a);
      Client getClient();
      string getDatecreation();
      void Affichage();
      void addproduct(Produit a);
      void editproduct();
      void editclient();
      void showproducts();
      void ajouterautableau(Facture factures[],int& indice);
      bool searchfacturetableau(Facture factures[],int& indice);
      void changestate(Facture factures[],int& indice);
      void setstate();
      void setEtat(bool etat);
      bool getEtat(){return etat;};
      int searchproduct(Produit& a);
      bool testclient(Client& c);
      vector <Produit> getProduits();
      void deleteproduct(Produit& a);
      float Total();

};
