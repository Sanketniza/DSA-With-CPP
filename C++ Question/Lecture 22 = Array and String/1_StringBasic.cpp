#include <iostream>
#include <cstring>
using namespace std;

void reverse(char name[], int n)
{
  int s = 0;
  int e = n - 1;

  while (s < e)
  {
    swap(name[s++], name[e--]);
  }
}

int main()
{
  char name[20];

  cout << "Enter your name: ";
  cin >> name;
  cout << "Your name is: " << name;

  int count = 0;
  for (int i = 0; i < strlen(name); i++)
  {
    count++;
  }

  cout << endl << endl;

  cout << "Length of the name is: " << count;

  cout << endl << endl;
  
  // Reverse the string
  reverse(name, count);

  cout << "Reversed name is: " << name;


  cout << endl << endl;

  string s = "hello sanket ";
  cout << s;

  return 0;
}
