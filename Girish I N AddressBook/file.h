#ifndef FILE_H      //prevent multiple inclusion
#define FILE_H

#include "contact.h" //Include contact defintion

void saveContactsToFile(AddressBook *addressBook);  //save contacts to file
void loadContactsFromFile(AddressBook *addressBook); //loading contacts to file

#endif //End include guard
