#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#include <stdio.h>

typedef struct {  //for declaring variables no need to declare struct keyword,only contact name is enough
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {        //for declaring variables no need to declare struct keyword
    Contact contacts[100];
    int contactCount; //how many contacts are stored till then only loop will run and memo will be allocated in stack
    Contact temp[1];
} AddressBook;
int validate_name(char* name); //for name validation
int validate_phone(char* ptr,AddressBook *addressBook); //for phone number validation
int validate_email(char *email, AddressBook *addressBook); //for email validation
void createContact(AddressBook *addressBook); //for creating contact
int searchContact(AddressBook *addressBook);  //for searching conatct
void editContact(AddressBook *addressBook);  //modifying the data only after searching
void deleteContact(AddressBook *addressBook); //for creating contact
void listContacts(AddressBook *addressBook, int sortCriteria); //for listing contact
void initialize(AddressBook *addressBook); //  to initialize the contact count
void saveContactsToFile(AddressBook *AddressBook); //saving contacts to file

#endif
