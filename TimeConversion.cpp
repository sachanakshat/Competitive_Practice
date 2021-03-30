#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string mer;
    int hrs, min, sec;
    char buffer[9];

    hrs = stoi(s.substr(0,2));
    min = stoi(s.substr(3,5));
    sec = stoi(s.substr(6,8));

    mer = s.substr(8);

    if(mer == "AM")
        if(hrs == 12)
            sprintf(buffer, "%02d:%02d:%02d", 00, min, sec);
        else
            sprintf(buffer, "%02d:%02d:%02d", hrs, min, sec);
    else
        if(hrs == 12)
            sprintf(buffer, "%02d:%02d:%02d", hrs, min, sec);
        else
            sprintf(buffer, "%02d:%02d:%02d", hrs+12, min, sec);
    
    // cout<<"\nHRS: "<<hrs<<"\nMIN: "<<min<<"\nSEC: "<<sec<<"\nMER: "<<mer<<"\n";
    // cout<<"Buffer: "<<buffer<<"\n";
    string str(buffer);
    return str;
}

int main(){
    auto start = high_resolution_clock::now();

    string converted = timeConversion("12:04:36AM");
    cout<<"String class: "<<converted<<"\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    cout<<5%5;

    return 0;
}