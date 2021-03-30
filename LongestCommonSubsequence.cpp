#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int lcs(string& s1, string & s2, int m, int n,int& p, int& q, vector<vector<int>>& tab)
{

    if(m<0 || n<0)
        return 0;
    else
    {
        if(s1[m] == s2[n])
        {
            if( tab[m][n] == -1)
            {
                tab[m][n] = 1+lcs(s1, s2, m-1, n-1, p, q, tab);
                return tab[m][n];
            }
            else
            {
                // cout<<"\ntab["<<m<<"]["<<n<<"] = "<<*((tab+m*q)+n);
                return tab[m][n];
            }
            
        }
        else
        {
            int a,b;
            if( tab[m-1][n] == -1)
            {
                a = lcs(s1, s2, m-1, n, p, q, tab);
                tab[m-1][n] = a;
            }
            else
                a = tab[m-1][n];
            
            if( tab[m][n-1] == -1)
            {
                b = lcs(s1, s2, m, n-1, p, q, tab);
                tab[m][n-1] = b;
            }
            else
                b = tab[m][n-1];
            
            return int(max(a,b));
        }
        
    }
    
}

int main()
{
    auto start = high_resolution_clock::now();
    string s1 = "SHINCHAN";
    string s2 = "NOHARAAA";

    int p = s1.size();
    int q = s2.size();

    // int tab[p][q];
    vector<int> val;
    vector<vector<int>> tab;

    cout<<"p: "<<p;
    cout<<"q: "<<q;
    for(int i = 0; i<p; i++)
    {
        for(int j=0; j<q; j++)
        {
            cout<< "\nShitty akshat";
            val.push_back(-1);
        }
        tab.push_back(val);
        cout<<"\ntab row size: "<< tab[i].size()<<"\n";
        val.clear();
    }
    val.push_back(224);
    for (int i=0;i<tab.size();i++) {
        for (int j=0; j<tab[i].size(); j++){
            cout<< tab[i][j]<< " ";
        }
        cout<< "\n";
    }
    cout<<"\nRow size = "<<tab.size()<<"\nColumn size = "<<tab.size();
    cout<<"\nChutiya mannu*****************\n";
    for (int j=0; j<tab[0].size(); j++){
                cout<< tab[0][j]<< " ";
            }
    int j = tab[0].size();
    cout<< "\nj:"<<j<<"\n";
    cout<<"\nRow size = "<<tab.size();
    cout<<"\nAsshole Mannu***";
    cout<< "\nj:"<<j<<"\n";
    cout<< "\nCol size:"<<j<<"\n";
    cout<<"\nCol size = "<<j;

    cout<<"\nThat shhit is happening coz of code u wrote here. Check fucking here - https://stackoverflow.com/questions/15862067/missing-cout-before-segmentation-fault. Blame urself before blaming others\n\n\n\n\n\n\n\n\n"<<std::flush;
    // int sol = lcs(s1, s2, p-1, q-1,p, q, tab);
    // cout<<"\nNumber of subsequence = "<<sol;

    // for(int i = 0; i<p; i++)
    // {
    //     for(int j=0; j<q; j++)
    //         cout<<tab[i][j]<<" ";
    //     cout<<"\n";
    // }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}