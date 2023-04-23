#include <iostream>
#include <math.h>


using namespace std;


class Client{
      int identifiant;
      string nom;
      string prenom;
      string adresse;

      public:
      Client();
      bool operator==(Client& a);
      Client(int identifiant,string nom,string prenom,string adresse)
      :identifiant(identifiant),nom(nom),prenom(prenom),adresse(adresse){};
      void setNom(string nom);
      void setPrenom(string prenom);
      void setAdresse(string adresse);
      void setId(int identifiant);
      int getId();
      string getNom();
      string getPrenom();
      string getAdresse();
      void afficher();
      void modifier();
};
