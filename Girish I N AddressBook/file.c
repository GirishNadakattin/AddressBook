#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
  FILE *fptr = fopen("contacts.csv", "w"); // opening file in write mode
  if (fptr == NULL)
  {
    printf("Error in opening file\n");
    return;
  }
  fprintf(fptr, "%d\n", addressBook->contactCount); // writing the contact count to file

  for (int i = 0; i < addressBook->contactCount && i <= MAX_CONTACTS; i++)
  {
    fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email); // To write each contact details in CSV file
  }
  fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook)
{
  FILE *fptr = fopen("contacts.csv", "r");
  if (fptr == NULL)
  {
    printf("Error in opening file\n");
    return;
  }
  fscanf(fptr, "%d\n", &addressBook->contactCount);

  for (int i = 0; i < addressBook->contactCount && i <= MAX_CONTACTS; i++)
  {
    // fscanf(fptr, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name,
    //        addressBook->contacts[i].phone,
    //        addressBook->contacts[i].email); // tp read each contacts file from CSV file

    fscanf(fptr, "%[^,],%[^,],%[^\n]\n", addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
  }
  fclose(fptr);
}