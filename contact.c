#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    printf("\n-----------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%s\t", addressBook->contacts[i].name);
        printf("%s\t", addressBook->contacts[i].phone);
        printf("%s\n", addressBook->contacts[i].email);
    }
    printf("\n------------------------------------------------------------------------------------------------\n");
    
}

void initialize(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.txt", "r");

    if (fp == NULL)
    {
        // File not present → use dummy data
        printf("No file found. Loading dummy contacts...\n");
        populateAddressBook(addressBook);
        return;
    }

    addressBook->contactCount = 0;

    while (fscanf(fp, "%49[^,],%19[^,],%49[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) != EOF)
    {
        addressBook->contactCount++;
    }
     fclose(fp);
  }

void saveAndExit(AddressBook *addressBook) {
     FILE *fp = fopen("contacts.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }

    fclose(fp);

}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("Enter name: ");
    scanf("%s", addressBook->contacts[addressBook->contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", addressBook->contacts[addressBook->contactCount].phone);
    printf("Enter email: ");
    scanf("%s", addressBook->contacts[addressBook->contactCount].email);

    addressBook->contactCount++;

    printf("Contact added sucessfully!\n");
    
}

void searchContact(AddressBook *addressBook) 
{
    int choice;
    char name[50], phone[20], email[50];
    int flag = 0;

    printf("\nSearch By:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter name: ");
            scanf(" %[^\n]", name);

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(name, addressBook->contacts[i].name) == 0)
                {
                    printf("\nContact Found:\n");
                    printf("%s\t%s\t%s\n",
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                    flag = 1;
                    break;
                }
            }
            break;

        case 2:
            printf("Enter phone: ");
            scanf("%s", phone);

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(phone, addressBook->contacts[i].phone) == 0)
                {
                    printf("\nContact Found:\n");
                    printf("%s\t%s\t%s\n",
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                    flag = 1;
                    break;
                }
            }
            break;

        case 3:
            printf("Enter email: ");
            scanf("%s", email);

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(email, addressBook->contacts[i].email) == 0)
                {
                    printf("\nContact Found:\n");
                    printf("%s\t%s\t%s\n",
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                    flag = 1;
                    break;
                }
            }
            break;

        default:
            printf("Invalid choice\n");
            return;
    }

    if (flag == 0)
    {
        printf("\nContact not found\n");
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
        int choice, editChoice, index = -1;
    char value[50];

    printf("\nEdit Contact By:\n1.Name\n2.Phone\n3.Email\nEnter choice: ");
    scanf("%d", &choice);

    getchar();  // clear buffer

    // ✅ Proper prompt based on choice
    if (choice == 1)
        printf("Enter name: ");
    else if (choice == 2)
        printf("Enter phone: ");
    else if (choice == 3)
        printf("Enter email: ");
    else
    {
        printf("Invalid choice\n");
        return;
    }

    scanf("%[^\n]", value);

    // Search
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if ((choice == 1 && strcmp(value, addressBook->contacts[i].name) == 0) ||
            (choice == 2 && strcmp(value, addressBook->contacts[i].phone) == 0) ||
            (choice == 3 && strcmp(value, addressBook->contacts[i].email) == 0))
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Contact not found\n");
        return;
    }

    printf("\nContact Found:\n%s\t%s\t%s\n",
        addressBook->contacts[index].name,
        addressBook->contacts[index].phone,
        addressBook->contacts[index].email);

    // Edit menu
    printf("\nEdit:\n1.Name\n2.Phone\n3.Email\nEnter choice: ");
    scanf("%d", &editChoice);

    getchar();  // clear buffer

    if (editChoice == 1)
    {
        printf("Enter new name: ");
        scanf("%[^\n]", addressBook->contacts[index].name);
    }
    else if (editChoice == 2)
    {
        printf("Enter new phone: ");
        scanf("%s", addressBook->contacts[index].phone);
    }
    else if (editChoice == 3)
    {
        printf("Enter new email: ");
        scanf("%s", addressBook->contacts[index].email);
    }

    printf("Contact updated successfully!\n");
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int choice, index = -1;
    char value[50];

    printf("\nDelete Contact By:\n1.Name\n2.Phone\n3.Email\nEnter choice: ");
    scanf("%d", &choice);

    getchar();  // clear buffer

    // Prompt
    if (choice == 1)
        printf("Enter name: ");
    else if (choice == 2)
        printf("Enter phone: ");
    else if (choice == 3)
        printf("Enter email: ");
    else
    {
        printf("Invalid choice\n");
        return;
    }

    scanf("%[^\n]", value);

    // Search contact
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if ((choice == 1 && strcmp(value, addressBook->contacts[i].name) == 0) ||
            (choice == 2 && strcmp(value, addressBook->contacts[i].phone) == 0) ||
            (choice == 3 && strcmp(value, addressBook->contacts[i].email) == 0))
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Contact not found\n");
        return;
    }

    // Shift contacts (IMPORTANT LOGIC)
    for (int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("Contact deleted successfully!\n");
   
}
