#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> map;
    int n;
    cin >> n;
    while(n--)
    {
        char ch;
        int i;
        cin >> ch >> i;
        if (ch=='I')
        {
            map.insert(i);
        } else {
            if(map.count(i))
            {
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
        
    }
}