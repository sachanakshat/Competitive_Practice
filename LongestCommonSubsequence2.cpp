#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int lcs(string& s1, string & s2, int m, int n, int& row_size, int& col_size, int * tab)
{
    // for (int i=0;i<row_size;i++) {
    //     for (int j=0; j<col_size; j++){
    //         cout<< tab[i*col_size+j]<< " ";
    //     }
    //     cout<< "\n";
    // }

    // cout<<"\nString s1 = "<<s1<<" and string s2 = "<<s2<<endl;
    cout<<"\nPerforming for characters: "<<s1.at(m)<<" and "<<s2.at(n)<<endl;
    if(m==0 || n==0)
    {
        cout<<"\nValues m = "<<m<<" or n = "<<n<<" equal to ZERO"<<endl;
        if(s1[m] == s2[n])
        {
            cout<<"BASE EQUAL and tab["<<m<<"]["<<n<<"] = 1"<<endl;
            tab[m*col_size+n] = 1;
            return tab[m*col_size+n];
        }
        else
        {
            cout<<"BASE UNEQUAL and tab["<<m<<"]["<<n<<"] = 0"<<endl;
            tab[m*col_size+n] = 0;
            return tab[m*col_size+n];
        }
    }

    else
    {
        if(s1.at(m) == s2.at(n))
        {
            cout<<"\n"<<s1.at(m)<<" and "<<s2.at(n)<<" are equal"<<endl;
            if( tab[m*col_size+n] == -1)
            {
                cout<<"\nValue at EQUAL indices "<<m<<" and "<<n<<" not present. Calculating..."<<endl;
                // cout<<"\ntab["<<m<<"]["<<n<<"] = "<<tab[m*col_size+n];
                tab[m*col_size+n] = 1+lcs(s1, s2, m-1, n-1, row_size, col_size, tab);
                cout<<"\nNew values assigned for EQUAL indices "<<m<<" and "<<n<<" = "<<tab[m*col_size+n];
                // cout<<"\nNew  tab["<<m<<"]["<<n<<"] = "<<tab[m*col_size+n];
                return tab[m*col_size+n];
            }
            else
            {
                // cout<<"\nAlready present if equal tab["<<m<<"]["<<n<<"] = "<<tab[m*col_size+n];
                cout<<"\nValue at EQUAL indices "<<m<<" and "<<n<<" already present. Value = "<<tab[m*col_size+n]<<endl;
                return tab[m*col_size+n];
            }
            
        }
        else
        {
            cout<<"\n"<<s1.at(m)<<" and "<<s2.at(n)<<" are not equal"<<endl;
            int a,b;
            if( tab[(m-1)*col_size+n] == -1)
            {
                cout<<"\nValue at FIRST indices "<<m-1<<" and "<<n<<" not present. Calculating..."<<endl;
                a = lcs(s1, s2, m-1, n, row_size, col_size, tab);
                tab[(m-1)*col_size+n] = a;
                cout<<"New values assigned for FIRST indices "<<m-1<<" and "<<n<<" = "<<tab[(m-1)*col_size+n];
            }
            else
            {
                cout<<"\nValue at FIRST indices "<<m-1<<" and "<<n<<" already present. Value = "<<tab[(m-1)*col_size+n]<<endl;
                a = tab[(m-1)*col_size+n];
            }
            
            if( tab[(m*col_size)+(n-1)] == -1)
            {
                cout<<"\nValue at SECOND indices "<<m<<" and "<<n-1<<" not present. Calculating..."<<endl;
                b = lcs(s1, s2, m, n-1, row_size, col_size, tab);
                tab[(m*col_size)+(n-1)] = b;
                cout<<"New values assigned for SECOND indices "<<m<<" and "<<n-1<<" = "<<tab[m*col_size+(n-1)];
            }
            else
            {
                cout<<"\nValue at FIRST indices "<<m<<" and "<<n-1<<" already present. Value = "<<tab[m*col_size+(n-1)]<<endl;
                b = tab[(m*col_size)+(n-1)];
            }

            if(tab[m*col_size+n] == -1)
            {
                cout<<"\nNew values CALCULATED to be assigned. A = "<<a<<" B = "<<b<<endl;
                tab[m*col_size+n] = max(a,b);
                cout<<"\ntab["<<m<<"]["<<n<<"] = "<<tab[m*col_size+n]<<" assigned"<<endl;
                return tab[m*col_size+n];
            }
            else
            {
                cout<<"\nValues at CALCULATED tab["<<m<<"]["<<n<<"] already present"<<endl;
                return tab[m*col_size+n];
            }
            
        }
    }
}

int main()
{
    auto start = high_resolution_clock::now();
    string s1 = "abc";
    string s2 = "bcd";
    //Expected 2 MCB MAC
    // string s1,s2;
    // cin>>s1;
    // cin>>s2;

    int p = s1.size();
    int q = s2.size();

    int tab[p*q];
    // vector<int> val;
    // vector<vector<int>> tab;

    cout<<"p: "<<p;
    cout<<"q: "<<q<<endl;

    //Initializing the matrix
    for(int i=0;i<p; i++)
    {
        for(int j=0; j<q; j++)
            tab[i*q+j] = -1;
    }

    //Displaying the matrix
    for (int i=0;i<p;i++) {
        for (int j=0; j<q; j++){
            cout<< tab[i*q+j]<< "\t";
        }
        cout<< "\n";
    }
    int sol = lcs(s1,s2,p-1,q-1,p,q,tab);
    cout<<"\nCommon characters = "<<sol<<endl;

    //Displaying the matrix
    for (int i=0;i<p;i++) {
        for (int j=0; j<q; j++){
            cout<< tab[i*q+j]<< "\t";
        }
        cout<< "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}