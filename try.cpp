#include <bits/stdc++.h>

#include <iostream>
using namespace std;

void palindrome(int n, int arr[]) {
    int i = 0, j = n - 1;
    while (i <= j) {
        if (arr[i] != arr[j]) {
            cout << "NOT Palindrome\n";
            return;
        }
    }

    cout << "Palindrome\n";
    return;
}

bool palindrome2(int n, int arr[]) {
    int i = 0, j = n - 1;
    while (i <= j) {
        if (arr[i] != arr[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[5] = {1, 2, 3, 2, 1};
    int n = 5;
    int i = 0, j = 5 - 1;
    bool flag = false;
    // while (i <= j) {
    //     if (arr[i] != arr[j]) {
    //         cout << "NOT PALINDROME \n";
    //         flag = true;
    //         break;
    //     }

    //     i++;
    //     j--;
    // }

    // for (int i = 0, j = 4; i <= j; i++, j--) {
    //     if (arr[i] != arr[j]) {
    //         cout << "NOT PALINDROME \n";
    //         flag = true;
    //         break;
    //     }
    // }
    // if (flag == false) cout << "Palindrome \n";

    palindrome(n, arr);

    int a = max(2, 3);  // 3
    int b = min(2, 3);  // 2
    swap(a, b);

    sort(arr, arr + n);

    bool checker = palindrome2(n, arr);

    if (checker == true)
        cout << "Palindrome \n";
    else
        cout << "NOT Palindrome \n";
    return 0;
}