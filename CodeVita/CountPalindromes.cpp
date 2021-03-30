#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

string increment(string time)
{
    int len = time.size();
    int isec = std::stoi(time.substr(len-2, len-1));
    int imin = std::stoi(time.substr(len-4, len-3));
    int ihrs = std::stoi(time.substr(len-6, len-5));
    int iday = std::stoi(time.substr(0, len-7));
    cout<<"Day: "<<iday<<"Hr: "<<ihrs<<"min: "<<imin<<"sec: "<<isec<<endl;
    isec++;
    
    string sec, min, hrs, day;
    if(isec>59)
    {
        isec=00;
        imin = imin+1;
    }
    if(imin>59)
    {
        imin = 00;
        ihrs+=1;
    }
    if(ihrs>23)
    {
        ihrs = 00;
        iday++;
    }

    if(isec<10)
        sec = "0"+to_string(isec);
    else
    {
        sec = to_string(isec);
    }

    if(imin<10)
        min = "0"+to_string(imin);
    else
    {
        min = to_string(imin);
    }

    if(ihrs<10)
        hrs = "0"+to_string(ihrs);
    else
    {
        hrs = to_string(ihrs);
    }
    
    return day+hrs+min+sec;
}

long reverse(long n)
{
    long ret = 0;
    while(n!=0)
    {
        ret = ret*10+n%10;
        n/=10;
    }
    return ret;
}

bool checktime(long n)
{
    int sec = n%100;
    n/=100;
    int min = n%100;
    n/=100;
    int hr = n%100;
    if(sec<60 && min<60 && hr<24)
        return true;
    else
    {
        return false;
    }
    
}

bool checkpal(string n)
{
    int len = n.size();
    for(int i=0; i<len/2; i++)
    {
        if(n[i]!=n[len-1-i])
            return false;
    }
    return true;
}

int main()
{
    auto start = high_resolution_clock::now();

    string si,ei;
    // cin>>si>>ei;
    si = "1";
    ei = "2";
    // long n1 = si*1000000;
    // long n2 = ei*1000000 + 235959;



    string i1 = si+"000000";
    string i2 = ei+"235959";
    int count = 0;
    while(i1!=i2)
    {
        if(checkpal(i1))
            count++;
        i1 = increment(i1);
    }



    // cout<<reverse(1000000009)<<endl;
    // cout<<checkpal("123321")<<endl;




    cout<<"i1 = "<<i1<<" i2 = "<<i2<<endl;

    // int count = 0;

    // for(long i=n1; i<=n2; i++)
    // {
    //     long j = reverse(i);
    //     if(checktime(i) && checktime(reverse(i)) && j==i)
    //     {
    //         // cout<<i<<endl;
    //         count++;
    //     }
    // }

    cout<<"Palindromes = "<<count<<endl;

    // cout<<"\nMaximum value of subarrays = "<<maxsum<<endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}