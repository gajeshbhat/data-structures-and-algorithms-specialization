#include <iostream>
#include <map>
#include <string>
#include <iterator>

void addContact(std::map<int,std::string> &PhoneBook,std::string Contactname,int Number){  //Adds Contact or Overwrites the name
  PhoneBook[Number]=Contactname;
}

void delNumber(std::map<int,std::string> &PhoneBook,int Number){  //Delets the number or ignors query
  std::map<int,std::string>::iterator searchIt=PhoneBook.find(Number);
  if (searchIt!=PhoneBook.end()) {
    //Found the element time to erase it.
    PhoneBook.erase(searchIt);
  }
}
std::string findNumber(std::map<int,std::string> &PhoneBook,int Number){   //Returns name or 'not found'
std::map<int,std::string>::const_iterator searchIt=PhoneBook.find(Number);
if (searchIt!=PhoneBook.end()) {
  return searchIt->second;
}
else{
  return "not found";
}
}

int main(int argc, char const *argv[]) {
  long int count;
  std::cin >> count;
  std::map<int,std::string> PhoneBook;
  for (size_t i = 0; i < count; i++) {
    std::string opName,Contactname;
    int Number;
    std::cin >> opName;
    if (opName=="add") {
      std::cin >>Number>>Contactname;
      addContact(PhoneBook,Contactname,Number);
    }
    else if (opName=="del") {
      std::cin >>Number;
      delNumber(PhoneBook,Number);
    }
    else if(opName=="find"){
      std::cin >> Number;
      std::cout <<findNumber(PhoneBook,Number)<< '\n';
    }
  }
  return 0;
}
