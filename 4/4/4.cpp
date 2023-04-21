#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string str;
    vector<vector<long long> > f;
    int n;

    cin >> str;
    n = str.size();
    f = vector<vector<long long> >(n, vector<long long>(n, 0));

    int j;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            j = i + k;
            
            if (j == n)
                break;
            
            if (i == j)
                f[i][j] = 1;
            else
            {
                if (str[i] != str[j])
                    f[i][j] = f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
                else
                    f[i][j] = f[i + 1][j] + f[i][j - 1] + 1;
            }
        }
    }

    cout << f[0].back();
}