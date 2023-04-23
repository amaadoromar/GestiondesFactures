# Gestion des Factures

The code imports several header files, including "client.h," "produit.h," and "facture.h." The main function of the program is to manage clients, products, and invoices. The program starts by defining an integer variable "indiceall" and a pointer to the Facture class, "allfactures." The menu function is defined to display options to the user for managing clients, products, and invoices. A submenu function is defined to manage invoices in more detail.

The showclients function displays the list of clients, while the showproduits function displays the list of products. The addfacture function prompts the user to enter a code, choose a client, and choose a product, and then returns a new Facture object. The addproduit function prompts the user to enter information about a new product and returns a new Produit object. The addclient function prompts the user to enter information about a new client and returns a new Client object.

The todayfactures function takes the list of all invoices and displays only those that were created on the current day. The main function starts by calling the menu function and then entering a while loop to continue prompting the user for options until the user chooses to exit the program. The program offers various options to manage clients, products, and invoices, including adding, modifying, and deleting entries. Additionally, the program includes a submenu for managing invoices in more detail, including testing if an invoice belongs to a given list, changing the state of an invoice while checking its existence in a list, and more.

Overall, the code is designed to provide a basic management system for clients, products, and invoices, with a variety of options available to modify and interact with the different data types.



![image](https://user-images.githubusercontent.com/71513920/233869418-5408efbd-5940-4b7c-9713-2956839095b7.png)

Example : 

![image](https://user-images.githubusercontent.com/71513920/233869432-13837056-4dc4-4064-ae79-619e19a8b695.png)
![image](https://user-images.githubusercontent.com/71513920/233869449-d3492f71-2759-40b9-a4e8-2282ee3a2e40.png)
