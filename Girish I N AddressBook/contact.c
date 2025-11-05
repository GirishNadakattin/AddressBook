#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //string library files
#include "contact.h" // available in current directory
#include "file.h"   //file save/load funtions
#include <ctype.h>  //character handeling functions

void listContacts(AddressBook *addressBook, int sortCriteria)
{

    if (sortCriteria == 1) // Sort by name
    {
        // Bubble sort logic
        for (int i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (int j = 0; j < addressBook->contactCount - i - 1; j++)
            {
                if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) // Comparing two names
                {
                    addressBook->temp[0] = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = addressBook->temp[0];
                }
            }
        }
    }
    else if (sortCriteria == 2) // Sort by phone
    {
        // Bubble sort logic
        for (int i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (int j = 0; j < addressBook->contactCount - i - 1; j++)
            {
                if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0) // Comparing two phone numbers
                {

                    addressBook->temp[0] = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = addressBook->temp[0];
                }
            }
        }
    }

    else if (sortCriteria == 3) // Sort by email
    {
        // Bubble sort logic
        for (int i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (int j = 0; j < addressBook->contactCount - i - 1; j++)
            {
                if (strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0) // Comparing two emails
                {
                    addressBook->temp[0] = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = addressBook->temp[0];
                }
            }
        }
    }
    else if (sortCriteria == 4) // Normal method
    {
        // Not any Sorting
        // Move to next line and just print
    }
    printf("%-20s%-20s%-20s\n","Name","Phone number","Email ID");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < (addressBook->contactCount); i++)
    {
        printf("%-20s%-20s%-20s", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        printf("\n");
    }
    printf("---------------------------------------------------------------\n");
}
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0; // '->' is taken bcs addressBook is a pointer
    loadContactsFromFile(addressBook); // Load contacts from file during initialization (After files)
    }

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook)    //create new contact
{
    char name[50];
    char phone[11];
    char email[50];
    if(addressBook->contactCount >= MAX_CONTACTS) //check for full addressbook if it is reaching maximum contacts
    {
        printf("AdressBook is full!\n");
    }
skip1: //input name
    printf("Enter name : ");
    scanf(" %[^\n]", name);
    int check = validate_name(name);
    if (check == 1)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    }
    else
    {
        printf("Entered Name is invalid\n");
        goto skip1;
    }
skip2: //input phone number
    printf("Enter phone number :");
    scanf(" %[^\n]", phone);
    check = validate_phone(phone, addressBook);
    if (check == 1)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    }
    else
    {
         printf("Entered phone number is invalid or already exist\n");
        goto skip2;
    }
skip3: //input email
    printf("Enter email :");
    scanf(" %[^\n]",email);
    check = validate_email(email, addressBook);
    if (check == 1)
    {
         strcpy(addressBook->contacts[addressBook->contactCount].email, email);
         }
     else
     {
         printf("Entered email is invalid or already exist.\n");
         goto skip3;
     }
    addressBook->contactCount++; //increament contactcount
    printf("Contact created successfully !\n");
    saveContactsToFile(addressBook); //save contact to file
}
int searchContact(AddressBook *addressBook) //search for contact
{
    int choice, i = 0;
    char search[30];
    int flag = 0;
    do {
        printf("\nSelect any one:\n");
        printf("1. Search by name\n");
        printf("2. Search by phone number\n");
        printf("3. Search by email\n");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter 1/2/3.\n");
            getchar(); // clear invalid input
            choice = 0; // force loop to repeat
        } else if (choice < 1 || choice > 3) {
            printf("Invalid choice.please try again.\n");
        }
        getchar(); // clear newline left by scanf
    } while (choice < 1 || choice > 3);

    if (choice == 1) //search by name
    { 
        printf("\nEnter Name: \n");
        scanf(" %[^\n]", search);  
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasecmp(addressBook->contacts[i].name, search) == 0)
            {
                printf("\nIndex :%d\nName :%s\nPhone Number: %s\nEmail ID: %s\n\n",i+1,addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
                flag = 1;
            }
        }
        if (flag == 1) 
        {
            printf("Contact found successfully\n");
            return 1;
        }else
        {
            printf("Name not found.\n");
            return -1;
        }
    }
    else if (choice == 2) //search by phone
    {   
        printf("\nEnter phone: \n");
        scanf(" %[^\n]", search);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasecmp(addressBook->contacts[i].phone, search) == 0)
            {
                printf("\nIndex: %d\nName :%s\nPhone Number: %s\nEmail ID: %s\n\n",i+1,addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
                printf("Contact found successfully\n");
                flag = 1;
                return 1;
            }
        }
        if (flag == 0)
        {
            printf("Phone Number not found.\n");
            return -1;
        }
    }
    else if (choice == 3) //search by email id
    {
        printf("\nEnter email: \n");
        scanf(" %[^\n]", search);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasecmp(addressBook->contacts[i].email, search) == 0)
            {
                printf("\nIndex: %d\nName :%s\nPhone Number: %s\nEmail ID: %s\n",i+1,addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
                printf("Contact found successfully!\n");
                flag = 1;
                return 1;
            }
        }
        if (flag == 0)
        {
            printf("Email ID Not found.\n");
            return -1;
        }
    }
}
void editContact(AddressBook *addressBook) //edit contact
{
    char name[50];
    char phone[15];
    char email[30];
    int check;
    int ret, choice, index;
    ret = searchContact(addressBook);
    if (ret == -1)
    {
        printf("Data not found !\n");
    }
    else{
    printf("Enter the index which you want to edit :");
    scanf("%d",&index);
    index = index-1; //change array index
    printf("\nSelected contact is :\n");
    printf("=> %s %s %s\n",addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);
    checkchoice:
    printf("\nEnter what do you want to edit ?\n1.Name \n2.phone \n3.email: \n=>");
    scanf("%d", &choice);
    if (choice == 1) //edit name
    {   checkname:
        printf("Enter name to update: \n");
        getchar();
        scanf("%[^\n]", name);
        check = validate_name(name);
        if (!check)
        {
            printf("Entered Name is invalid,Try Again\n");
            goto checkname;
        }
        strcpy(addressBook->contacts[index].name, name);
    }
    else if (choice == 2) //edit phone number
    {   checkphone:
        printf("Enter phone number to update: \n");
        getchar();
        scanf("%[^\n]", phone);
        check = validate_phone(phone, addressBook);
        if (!check)
        {
            printf("Entered phone number is invalid,Try Again.\n");
            goto checkphone;
        }
        strcpy(addressBook->contacts[index].phone, phone);
    }
    else if (choice == 3) //edit Email ID
    {   checkemail:
        printf("Enter email to update.\n");
        getchar();
        scanf("%[^\n]", email);
        check = validate_email(email, addressBook);
        if (!check)
        {
            printf("Entered email is invalid,Try Again.\n");
            goto checkemail;
        }
        strcpy(addressBook->contacts[index].email, email);
    }
    else
    {
        printf("Enter Correct choice :\n");
        goto checkchoice;
        return;
    }
    printf("Contact updated succesfully !\n");
    saveContactsToFile(addressBook);
    }}
void deleteContact(AddressBook *addressBook) //delete contact
{
    int ret, choice, index=0,confirm;
    ret = searchContact(addressBook);
    if (ret == -1)
    {
        printf("Data not found !\n");
        return;
    }
    printf("\nEnter the index which you want to delete :");
    scanf("%d",&index);
    index = index-1; //changing array index
    printf("\nSelected contact is \n");
    printf("=> %s %s %s\n",addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);
    printf("\nAre you sure you want to delete this contact ? \n1.Yes\n2.No\n=>"); //asking confirmation from user
    scanf("%d",&confirm);
    if(confirm == 2)
    {
        printf("\nContact deletion cancelled! \n");
        return;
    }
    else if(confirm ==1)
    {
    for (int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook -> contacts[i] = addressBook -> contacts[i+1]; //shift contacts left to overwrite deleted contact
    }
    addressBook->contactCount--; //reducing contactcount
    printf("Contact deleted successfully!\n");
    saveContactsToFile(addressBook);
}}
int validate_name(char *ptr) //Name validation
{
    int i = 0;
    while (ptr[i])
    {
        if (!((ptr[i] >= 'a' && ptr[i] <= 'z') || (ptr[i] >= 'A' && ptr[i] <= 'Z') || ptr[i] == ' '))
        {
            return 0;
        }
        if (ptr[i] == ' ' && ptr[i + 1] == ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int validate_phone(char *ptr, AddressBook *addressBook) //phone Validation
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasecmp(addressBook->contacts[i].phone, ptr) == 0)
        {
            return 0;
        }
    }
    int i = 0;
    while (ptr[i])
    {
        if (!(ptr[i] >= '0' && ptr[i] <= '9'))
        {
            return 0;
        }
        if (ptr[i + 1] == ' ')
        {
            return 0;
        }
        i++;
    }
    if (i != 10)
    {
        return 0;
    }
    return 1;
}
int validate_email(char *email, AddressBook *addressBook) //Email validation
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasecmp(addressBook->contacts[i].email, email) == 0)
        {
            return 0;
        }
    }

    char *dotsign = strchr(email, '.');
    char *atsign = strchr(email, '@');

    if (!dotsign || !atsign) // there must be dotsign and atsign
    {
        return 0;
    }
    if (atsign > dotsign) //at sign nmust be before dot sign
    {
        return 0;
    }
    if (atsign == email)
    {
        return 0;
    }
    if (*(atsign + 1) == '.' || *(atsign + 1) == '\0') // must have character after @.
    {
        return 0;
    }
    if (*(dotsign + 1) == '\0') // there should be a character after '.'
    {
        return 0;
    }

    int i = 0, atcount = 0;
    while (email[i])
    {
        if (!(isalnum(email[i]) || email[i] == '@' ||
              email[i] == '.'))
        {
            return 0;
        }
        if (email[i] == '@')
        {
            atcount++;
            if (atcount > 1)
                return 0; // there should be no more than one '@'
        }
        i++;
    }

    return 1; // if all the test cases are passed
}