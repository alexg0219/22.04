#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s, t = "";
    int a[2][200];
    int k = 0;
    a[0][0] = 0;
    a[1][0] = 0;
    cin >> s;

    for (int i = 0; i < s.length(); i++) 
    {
        k++;

        if (s[i] == 'N') 
        {
            a[0][k] = a[0][k - 1];
            a[1][k] = a[1][k - 1] + 1;
            t += 'S';
        }

        if (s[i] == 'E')
        {
        a[0][k] = a[0][k - 1] + 1;
        a[1][k] = a[1][k - 1];
        t += 'W';
        }

        if (s[i] == 'S') 
        {
            a[0][k] = a[0][k - 1];
            a[1][k] = a[1][k - 1] - 1;
            t += 'N';
        }
        
        if (s[i] == 'W') 
        {
            a[0][k] = a[0][k - 1] - 1;
            a[1][k] = a[1][k - 1];
            t += 'E';
        }

        int j = 0;

        while (a[0][j] != a[0][k] || a[1][j] != a[1][k]) {
            j++;
        }
        
        if (j < k) 
        {
            t.erase(j + 1, k - j);
            k = j;
        }
    }
    
    for (int i = t.length() - 1; i >= 0; i--) 
    {
        cout << t[i];
    }

}