/* #include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string : ";
    getline(cin, s); // Use getline to read the entire line including spaces and special characters

    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            temp += "@40"; // Use += to concatenate the string "@40"
            cout << temp << endl; 
        }
        else
        {
             temp += s[i]; // Use += to concatenate the character
        }
    }

    cout << s;

    return 0;
}
 */

//!without creating a new string to store the current string.

#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string: ";
    getline(cin, s); // Read the entire line including spaces and special characters

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            s.replace(i, 1, "@40"); // Replace the space with "@40"
          //  i += 2; // Skip the next two characters (since "@40" is 3 characters long)
        }
    }

    cout << s;
    
    return 0;
}
