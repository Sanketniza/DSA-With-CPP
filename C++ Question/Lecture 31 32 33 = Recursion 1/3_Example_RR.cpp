#include <iostream>
using namespace std;
//^ I want to go from source to destination
// like 1 to 19;

void reachHome(int src, int dest)
{

    cout << "src " << src << " dest " << dest << endl;

    // base case == when you have to stop , (breaking condition)
    if (src == dest)
    {
        cout << "I reached home" << endl;
        return;
    }

    // Processing - increase one step toward home
    src++;

    // recursive case
    reachHome(src, dest);
}
int main()
{

    int src = 1;
    int dest = 10;

    reachHome(src, dest);

    return 0;
}