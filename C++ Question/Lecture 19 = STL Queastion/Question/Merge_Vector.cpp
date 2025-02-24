#include <iostream>
#include <vector>
using namespace std;

 
 vector<int> Merge(vector<int> v1, int n, vector<int> v2, int m, vector<int>& v3)
{
    int i = 0;
    int j = 0;
    int z = 0;

    while (i < n && j < m)
    {
        if (v1[i] < v2[j])
        {
            v3[z] = v1[i];
            z++;
            i++;
        }
        
        else
        {
            v3[z] = v2[j];
            z++;
            j++;
        }
    }

    while (i < n)
    {
        v3[z] = v1[i];
        z++;
        i++;

        // v3[z++] = v1[i++];
    }

    while (j < m)
    {
        v3[z] = v2[j];
        z++;
        j++;
    }

    return v3;
}

void PrintArray(vector<int> ans, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1, v2, v3;

    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v2.push_back(7);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);
    v2.push_back(16);

    int n = v1.size();
    int m = v2.size();
    int k = n + m;

    v3.resize(k); // Resize v3 to hold the merged result

    vector<int> ans = merge(v1, n, v2, m, v3);

    PrintArray(ans, k);

    return 0;
}
