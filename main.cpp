#include <iostream>
//#include "date.h"
#include "client.h"
#include "produit.h"
#include "facture.h"
#include "ctime"


using namespace std;

int indiceall=0;
Facture* allfactures;


void menu(){
cout<<"1 - Ajouter un client"<<endl; //OK
cout<<"2 - Ajouter un produit"<<endl; //OK
cout<<"3 - Ajouter une facture"<<endl; //OK
cout<<"4 - Gerer les factures"<<endl; //OK
cout<<"5 - Gerer les clients"<<endl; //OK
cout<<"6 - Afficher les produits"<<endl; //OK
cout<<"7 - Afficher les factures d'aujourd'hui"<<endl; //OK
cout<<"8 - Afficher les clients qui ont passe des factures sans paiement"<<endl; //OK
cout<<"9 - Ajouter un produit a une facture"<<endl; //OK
cout<<"10 - Tester si un client a passe une facture"<<endl; //OK
cout<<"11 - Changer l'etat d'une facture"<<endl; //OK
cout<<"12 - Modifier un produit dans une facture"<<endl; //OK
cout<<"13 - Modifier les informations d'un client dans une facture"<<endl; //OK
cout<<"14 - Creer un nouveau tableau de Facture"<<endl; //OK
// A FAIRE : UN SOUS MENU ICI APRES LA CREATION DU TABLEAU
}

void submenu(){
cout<<"15 - Tester si une facture appartienne a un tableau"<<endl; //OK
cout<<"16 - Changer l'etat d'une facture tout en testant son existence dans un tableau"<<endl; //OK
cout<<"17 - Tester si un client a passe une facture dans un tableau"<<endl; //OK
cout<<"18 - Ajouter une facture a un tableau donne"<<endl; //OK
cout<<"19 - Supprimer une facture d'un tableau donne"<<endl; //OK
cout<<"20 - Afficher les elements du nouveau tableau facture"<<endl; //OK
}

void showclients(Client clients[],int indiceclients){
    cout<<"-----------------"<<endl;
    cout<<"Liste des clients :"<<endl;
    for(int i=0;i<indiceclients;i++){
    clients[i].afficher();
    };
    cout<<"-----------------"<<endl;
}


void showproduits(Produit produits[],int indiceproduits){
    cout<<"-----------------"<<endl;
    cout<<"Liste des produits :"<<endl;
    for(int i=0;i<indiceproduits;i++){
    produits[i].Affichage();
    };
    cout<<"-----------------"<<endl;
}

Facture addfacture(Client clients[],Produit produits[],int indiceproduits,int indiceclients){
     time_t now = time(0);
     tm *localTime = localtime(&now);
     char dateAujourdHui[11];
     sprintf(dateAujourdHui, "%02d/%02d/%04d", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
     int code;
     Client client;
     string datecreation = dateAujourdHui;
     bool etat = false;
     int choixclient;
     int choixproduit;

     cout<<"entrer un Code :"<<endl;
     cin >> code;


     cout<<"Choisir un client (ID) :"<<endl;
     showclients(clients,indiceclients);
     cin>>choixclient;
     choixclient--;

     cout<<"Choisir un produit (ID) :"<<endl;
     showproduits(produits,indiceproduits);
     cin>>choixproduit;
     choixproduit--;


     return Facture(code,clients[choixclient],produits[choixproduit],etat,datecreation);

}


Produit addproduit(){
    int identifiant;
    string nom;
    string description;
    float prixunitaire;
    int quantite;

    cout<<"-----------------"<<endl;
    cout<<"identifiant : "<<endl;
    cin >> identifiant;
    cout<<"Le nom : "<<endl;
    cin >> nom;
    cout<<"Description : "<<endl;
    cin >> description;
    cout<<"Prix Unitaire : "<<endl;
    cin >> prixunitaire;
    cout<<"Quantite : "<<endl;
    cin >> quantite;
    cout<<"-----------------"<<endl;
    return Produit(identifiant,nom,description,prixunitaire,quantite);
}


Client addclient(){
    int identifiant;
    string nom;
    string prenom;
    string adresse;

    cout<<"-----------------"<<endl;
    cout<<"identifiant : "<<endl;
    cin >> identifiant;
    cout<<"Le nom : "<<endl;
    cin >> nom;
    cout<<"Prenom : "<<endl;
    cin >> prenom;
    cout<<"Adresse : "<<endl;
    cin >> adresse;
    cout<<"-----------------"<<endl;
    return Client(identifiant,nom,prenom,adresse);
}
//Q13
void todayfactures(Facture allfactures[],int indiceall){
  time_t now = time(0);
  tm *localTime = localtime(&now);
  char dateAujourdHui[11];
  sprintf(dateAujourdHui, "%02d/%02d/%04d", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
  cout<<"-----------------"<<endl;
    cout<<"Les factures d'aujourd'hui sont : "<<endl;
    for(int i=0;i<indiceall;i++){
    if(allfactures[i].getDatecreation() == dateAujourdHui){allfactures[i].Affichage();};
    };
    cout<<"-----------------"<<endl;

}


//Q12
void showallunpaidfactures(Facture factures[],int indice){
    cout<<"-----------------"<<endl;
    for(int i=0;i<=indice;i++){
    if(factures[i].getEtat()==false){factures[i].getClient().afficher();};
    };
    cout<<"-----------------"<<endl;
}
//Q10
void showtablefactures(Facture* factures,int indice){
    cout<<"-----------------"<<endl;
    for(int i=0;i<indice;i++){
    factures[i].Affichage();
    };
    cout<<"-----------------"<<endl;
}

//Q8
bool searchclientbytablefacture(Client& client,Facture factures[],int& indice){
    cout<<"-----------------"<<endl;
  for(unsigned int i=0;i<=indice;i++){
       // factures[indice].Affichage();
    if(factures[i].getClient()==client){
        return true;
    }
  }
  cout<<"-----------------"<<endl;
    return false;
}

/*
//Q7
bool searchfacture(Facture& parameter){
  for(unsigned int i=0;i<=indice;i++){
       // factures[indice].Affichage();
    if(factures[i]==parameter){
        return true;
    }
  }
    return false;
}




void changestatefacture(Facture& parameter){

}
*/
//Q11
void showallfactures(){
    for(int i=indiceall-1;i>=0;i--){
    allfactures[i].Affichage();
    };
}
void addtotable(Facture F1,Facture factures[],int& indice){
   factures[indice] = F1;
   indice++;
}

void shownewfactures(Facture* factures,int indice){
      for(int i=0;i<indice;i++){
        factures[i].Affichage();
    }
}

void elementtodelete(Facture factures[],int& indice){
    int element;
    cout<<"Quel est l'element que vous voulez supprimer ?"<<endl;
    showtablefactures(factures,indice);
    cin >> element;
    element--;
    for(int i=element;i<indice-1;i++){
        factures[i] = factures[i+1];
    }
    indice--;
}


//Q14
void deletefromtablefacture(Facture factures[],int& indice){
    int element;
    cout<<"Quel est l'element que vous voulez supprimer ?"<<endl;
    showtablefactures(factures,indice);
    cin >> element;
    element--;
    for(int i=element;i<indice-1;i++){
        factures[i] = factures[i+1];
    }
    indice--;
    showtablefactures(factures,indice);
}

int main()
{
    cout<<"Bienvenue dans notre programme de gestion des factures"<<endl;

    Client omar(1,"AMAAR","OMOR","TESTING");
    Client omar2(2,"AMOR","OMIR","TESTING");
    Client omar5(4,"AMAADR","OMAR","TESTING");
    Client omar3(3,"AMAADOR","OMUR","TESTING");
    //Date date(10,10,2023);
    //Date date2(20,11,1994);
    Facture testing(1,omar,false,"04/01/2023");
    Facture testing2(2,omar2,false);
    Facture testing3(3,omar3,false);
    Facture testing4(4,omar3,true);
    Facture testing5(5,omar3,true);

    Produit pr1(1,"amaador","TESTING",30.50,300);
    Produit pr2(2,"amaado","TESTNG",62.5,120);
    Produit pr3(3,"amaado","TESTNG",62.27,120);

    Facture facturetest(20,omar,pr1,true,"01/01/1990");

    Facture factures[200];
    Facture nouvellesfactures[150];
    int indice=0;
    int indicefac=0;

    Client clients[200];
    int indiceclients=0;

    Produit produits[200];
    int indiceproduits=0;
    //omar.afficher();
    //date.showDate();
    testing.addproduct(pr1);
    testing2.addproduct(pr2);
    testing3.addproduct(pr3);
    testing4.addproduct(pr3);
    testing5.addproduct(pr3);

    int expression;
    do{
    menu();
    cin >> expression;
    switch(expression) {
  case 1:
      clients[indiceclients] = addclient();
      clients[indiceclients].afficher();
      indiceclients++;
      cout<<"-----------------"<<endl;
      cout << "le client a ete ajoute avec success"<<endl;
      cout<<"-----------------"<<endl;
      break;
    // code block
  case 2:
      produits[indiceproduits] = addproduit();
      produits[indiceproduits].Affichage();
      indiceproduits++;
      cout<<"-----------------"<<endl;
      cout << "le produit a ete ajoute avec success"<<endl;
      cout<<"-----------------"<<endl;
      break;
  case 3:
      factures[indice] = addfacture(clients,produits,indiceproduits,indiceclients);
      factures[indice].Affichage();
      indice++;
      cout<<"-----------------"<<endl;
      cout << "la facture a ete cree avec success"<<endl;
      cout<<"-----------------"<<endl;
      break;
  case 4:
      showtablefactures(factures,indice);
      break;
  case 5:
      showclients(clients,indiceclients);
    break;
  case 6:
      showproduits(produits,indiceproduits);
    break;
  case 7:
      todayfactures(factures,indice);
      break;
  case 8:
      showallunpaidfactures(factures,indice);
    break;
  case 9:
    int choixfacture;
    int choixproduit;

    cout<<"Choisir une facture :"<<endl;
    showtablefactures(factures,indice);
    cin>>choixfacture;
    choixfacture--;

    cout<<"Choisir un produit :"<<endl;
    showproduits(produits,indiceproduits);
    cin>>choixproduit;
    choixproduit--;

    factures[choixfacture].addproduct(produits[choixproduit]);

    cout<<"Verification d'ajout :"<<endl;

    factures[choixfacture].Affichage();
    break;
  case 10:
      int choixclient;

      cout<<"Choisir un client :"<<endl;
      showclients(clients,indiceclients);
      cin>>choixclient;
      choixclient--;

      if(searchclientbytablefacture(clients[choixclient],factures,indice)){
             cout<<"RESULTAT :"<<endl;
            cout<<"Le client a deja passe une facture"<<endl;
            cout<<"--------------------------------------"<<endl;
      }
      else{
            cout<<"RESULTAT :"<<endl;
            cout<<"Le client n'a jamais passe une facture"<<endl;
            cout<<"--------------------------------------"<<endl;
      };
    break;
  case 11:
      int choixf;
      cout<<"Choisir une facture pour changer l'etat (ID) : "<<endl;
      showtablefactures(factures,indice);
      cin>>choixf;
      choixf--;
      if(factures[choixf].getEtat()){
      factures[choixf].setEtat(false);
      }
      else
        factures[choixf].setEtat(true);

      cout<<"Etat change avec success :"<<endl;
      factures[choixf].Affichage();
    break;
    // Confirmer
  case 12:
    int choixfactureedit;
    int choixproduitedit;

    cout<<"Choisir une facture :"<<endl;
    showtablefactures(factures,indice);
    cin>>choixfactureedit;
    choixfactureedit--;

    cout<<"Choisir un produit :"<<endl;
    showproduits(produits,indiceproduits);
    cin>>choixproduitedit;
    choixproduitedit--;

    factures[choixfactureedit].editProduitbyIndex(choixproduitedit);

    cout<<"Verification de modification :"<<endl;

    factures[choixfactureedit].Affichage();
    break;
   case 13:
    int choixfactureclient;

    cout<<"Choisir une facture :"<<endl;
    showtablefactures(factures,indice);
    cin>>choixfactureclient;
    choixfactureclient--;

    factures[choixfactureclient].editClient();

    cout<<"Verification de modification :"<<endl;

    factures[choixfactureclient].Affichage();
    break;
   case 14:
    int submenunow;
    do{
    cout<<"Le tableau des factures a ete cree avec succes , choisir une operation :"<<endl;


    submenu();
    cin>>submenunow;

    switch(submenunow) {
      case 15:
      int choixfacturetest;

    cout<<"Choisir une facture :"<<endl;
    showtablefactures(factures,indice);
    cin>>choixfacturetest;
    choixfacturetest--;
    if(factures[choixfacturetest].searchfacturetableau(nouvellesfactures,indicefac)){cout<<"La facture existe dans le tableau"<<endl;}
    else{cout<<"La facture n'existe pas dans le tableau"<<endl;};
      break;
      case 16:
      cout<<"--------------------"<<endl;

      int indouca;
      cout<<"Choisir une facture :"<<endl;
      showtablefactures(factures,indice);
      cin>>indouca;
      indouca--;
      if(factures[indouca].searchfacturetableau(nouvellesfactures,indouca)){
            int indoucacheck;
            for(int k=0;k<indicefac;k++){
                if(factures[indouca] == nouvellesfactures[k]){indoucacheck = k;}
            }
            cout<<"La facture existe dans le tableau"<<endl;
            nouvellesfactures[indoucacheck].setstate();
      }
      else cout<<"La facture n'existe pas dans le tableau"<<endl;

      cout<<"--------------------"<<endl;

      break;
      case 17:
      int choixclienttest;

      cout<<"Choisir un client :"<<endl;
      showclients(clients,indiceclients);
      cin>>choixclienttest;
      choixclienttest--;
      if(searchclientbytablefacture(clients[choixclienttest],nouvellesfactures,indicefac)){cout<<"Le client a passe une facture"<<endl;}
      else{cout<<"Le client n'a pas passe une facture"<<endl;};
      break;
      case 18:
      int choixfactureadding;

      cout<<"Choisir une facture :"<<endl;
      showtablefactures(factures,indice);
      cin>>choixfactureadding;
      choixfactureadding--;

      factures[choixfactureadding].addtotable(nouvellesfactures,indicefac);
      indicefac++;
      cout<<"La facture a ete ajoutee avec succes"<<endl;

      break;
      case 19:
       elementtodelete(nouvellesfactures,indicefac);
      break;
      case 20:
        showtablefactures(nouvellesfactures,indicefac);
      break;
      default:
      bool quitsub;
      cout <<"Est-ce que vous voulez quitter ? (0 ou 1)"<<endl;
      cin >> quitsub;
      if(!quitsub)
        quitsub = 0;

    }

    }while(submenunow != -1);
     break;

      default:
      bool quit;
      cout <<"Est-ce que vous voulez quitter ? (0 ou 1)"<<endl;
      cin >> quit;
      if(!quit)
        expression = 0;
    }}while(expression != -1);
    //testing.deleteproduct(pr3);
    //addfacture(testing);
    /*
    if(searchclientbyfacture(omar5)){cout<<"client a deja passe une facture"<<endl;};
    addfacture(testing2);


    if(searchfacture(testing2)){
        cout<<"Facture existes dans le tableau"<<endl;
    }

    if(!searchfacture(testing3)){
        cout<<"Facture inexsistante"<<endl;
    }
    //testing.showproducts();
    //testing.editproduct();
    //testing.Affichage();
    //testing.Affichage();
    //testing.Affichage();

 */
//showallfactures();

//time_t ttime = time(0);

    //todaytime();

    testing.ajouterautableau(factures,indice);
    testing2.ajouterautableau(factures,indice);
    testing3.ajouterautableau(factures,indice);
    testing4.ajouterautableau(factures,indice);
    //showtablefactures(factures,indice);

    //testing2.changestate(factures,indice,true);

    //showallunpaidfactures();

    //deletefromtablefacture(factures,indice);

    //todayfactures();
    //todayfactures();
    //showallfactures();

    return 0;
}
