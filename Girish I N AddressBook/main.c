#include <stdio.h>
#include "contact.h"

int main() {
    int choice,sortChoice;
    AddressBook addressBook;    // addressbook structure
    initialize(&addressBook); // Initialize the address book
    //print menu
    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {    //check if entered input is number
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');      // clear buffer
            choice = 0;                     //reset choice to avoid invalid execution
            continue;                       //Restart loop
        }
        switch (choice) {
            case 1:
                createContact(&addressBook);        //Add new contact
                saveContactsToFile(&addressBook);   //save contacts
                break;
            case 2:
                searchContact(&addressBook);        //search contact
                break;
            case 3:
                editContact(&addressBook);          //edit contact
                break;
            case 4:
                deleteContact(&addressBook);        //delete contact
                break;
            case 5:          
                    printf("sort by : \n1.Name\n2.Phone Number\n3.Email address\n4.Any order\n==>");   //sorting
                    scanf(" %d",&sortChoice);       //input choice from user
                    listContacts(&addressBook, sortChoice); //sorting 
                break;
            case 6:
                printf("Saving....\n");      //save contacts
                saveContactsToFile(&addressBook); 
                printf("Contact saved successfully !");    
                break;
            case 7:
                printf("Exiting...\n"); //exiting
                break;
            default:
                printf("Invalid choice. Please try again.\n"); //handling  wrong input
                break;}
    } while (choice != 7);
return 0;                                           //End program
    }
