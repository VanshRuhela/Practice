// CPP program to find if any element appears
// more than n/3.
#include <bits/stdc++.h>
using namespace std;

int appearsNBy3(int arr[], int n) {
    cout << "fin lk andr\n";
    int count1 = 0, count2 = 0;
    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < n; i++) {
        // if this element is previously seen,
        // increment count1.
        if (first == arr[i]) {
            count1++;
            cout << "first i :" << i << " cnt1 " << count1 << endl;
        }

        // if this element is previously seen,
        // increment count2.
        else if (second == arr[i]) {
            count2++;
            cout << "second i :" << i << " cnt2 " << count2 << endl;
        }

        else if (count1 == 0) {
            count1++;
            first = arr[i];
            cout << "first i :" << i << " cnt1 " << count1 << endl;

        }

        else if (count2 == 0) {
            count2++;
            second = arr[i];
            cout << "second i :" << i << " cnt2 " << count2 << endl;

        }

        // if current element is different from
        // both the previously seen variables,
        // decrement both the counts.
        else {
            count1--;
            count2--;

            cout << "dec i :" << i << " cnt1 " << count1 <<" cnt2 : " <<count2 << endl;

        }
    }

    cout << "f " << first << " s " << second << "\n";
    count1 = 0;
    count2 = 0;

    // Again traverse the array and find the
    // actual counts.
    for (int i = 0; i < n; i++) {
        if (arr[i] == first)
            count1++;

        else if (arr[i] == second)
            count2++;
    }

    if (count1 > n / 3) return first;

    if (count2 > n / 3) return second;

    return -1;
}

int main() {
    int arr[] = {1,1,1,1,1,1,2,3,2,3,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << appearsNBy3(arr, n) << endl;
    return 0;
}
