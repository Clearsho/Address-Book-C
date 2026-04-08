/****************************************************************
 * NAME: SHUBHAM SHIVPUJIMATH
 * DATE: 05-04-2026
 * DESCRIPTION: ADDRESSBOOK MENU
 ****************************************************************/

#include <stdio.h>
#include "contact.h"

int main() {

    AddressBook var;
    initialize(&var);
    int choice;
    do
    {
    printf("\n");
    printf("Address Book menu\n");
    printf("1.Add contact\n");
    printf("2.Search contact\n");
    printf("3.Edit contact\n");
    printf("4.Delete contact\n");
    printf("5.List contact\n");
    printf("6.Save and exit\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        printf("Add contact is selected\n");
        createContact(&var);
        break;
        case 2:
        printf("Search contact is selected\n");
        searchContact(&var);
        break;
        case 3:
        printf("Edit contact is selected");
        editContact(&var);
        break;
        case 4:
        printf("Delete contact is selected");
        deleteContact(&var);
        break;
        case 5:
        printf("list contact is selected");
        listContacts(&var);
        break;
        case 6:
        printf("Save contact is selecetd");
        saveAndExit(&var);
        break;
        default:
        printf("Invalid choiice");
        break;
    } 
    } while ( choice !=6 );

    
          return 0;
}
