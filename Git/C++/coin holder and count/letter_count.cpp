#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int counts[26] = {0};

    char x;

    while (cin.get(x)) 
    {
        if (isalpha(x)) {
            x = (int)toupper(x);
            counts[x - 'A']++;
        } 
    }
    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 'A') << " " << counts[i] << endl;
    }

    return 0;
}