#include<iostream>
#include<cstdlib>
using namespace std;

int compare(const void *a, const void *b)
    return ( *(int *) a - *(int *) b);
}

int main (){
    int n; cin >> n; int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    qsort(a, n, sizeof(int), compare);

    for (int i = 0; i < n; i++)
        if (i > 0) cout << ' ';
        cout << a[i];

    return 0;
}
