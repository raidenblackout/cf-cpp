#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <cstring>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void SWAP(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void BUBBLE_SORT(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - i - 1; j < size; j++)
        {
            if (a[j] > a[j + 1])
            {
                SWAP(&a[j], &a[j + 1]);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    ofstream in1("in.txt");
    int max = 250;
    int min = -249;
    for (int i = 0; i < n; i++)
    {
        in1 << rand() % (max - min + 1) + min << " ";
    }
    in1.close();
    ifstream in2("in.txt");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        in2 >> a[i];
    }
    BUBBLE_SORT(a, n);
    ofstream out("out.txt");
    for (int i = 0; i < n; i++)
    {
        out << a[i] << " ";
    }
    in1.close();
    in2.close();
    out.close();
    return 0;
}