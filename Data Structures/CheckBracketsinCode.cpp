#include <iostream>
#include <stack>
#include <string>
#include <sstream> //to support to_string Patch
// to_string funtion to Convert int to string.. (As Patch not yet fixed in gcc 4.8 at the time that this code is being written)
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
using namespace std;
string CheckBrackets(string reference){
  //Base Cases
  if (reference.size()==0) {
    return "Success";
  }
  if (reference.size()==1) {
    return patch::to_string(1);
  }
std::stack<char>BracketStack; //Contains Brackets.
std::stack<int>PosStack; // Contains Position of the Brackets

for (size_t i = 0; i < reference.size(); i++) {
    if (reference[i]=='{'||reference[i]=='['||reference[i]=='(') {
      BracketStack.push(reference[i]);
      PosStack.push(i);
    }
    if (reference[i]=='}'||reference[i]==']'||reference[i]==')')
    {
      if (BracketStack.size() > 0 ) {
       if (reference[i]=='}' && BracketStack.top()=='{') {
         BracketStack.pop();
         PosStack.pop();
       }
       else if(reference[i]==']' && BracketStack.top()=='[') {
         BracketStack.pop();
         PosStack.pop();
       }
       else if (reference[i]==')' && BracketStack.top()=='(') {
         BracketStack.pop();
         PosStack.pop();
       }
       else{
          return patch::to_string(i+1);
        }
    }
      else{
         return patch::to_string(i+1);
       }
    }
}
if (BracketStack.empty()) {
  return "Success";
}
else{
 //Return the position of first opening Bracket that caused the inconsistency.
  while (PosStack.size()!=1) {
    PosStack.pop();
  }
  return patch::to_string(PosStack.top()+1);
}
}
int main(int argc, char const *argv[]) {
 string inputString;
 std::cin >> inputString;
 std::cout << CheckBrackets(inputString) << '\n';
  return 0;
}
