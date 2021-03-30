#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int isPrefixOfWord(string sentence, string searchWord) {
        std::istringstream ss(sentence);
        vector<string> separated;
        int flag=0;

        do{
            string word;
            ss>>word;
            separated.push_back(word);
        }while(ss);

        for(int i=0; i<separated.size(); i++)
        {
            if (separated[i].find(searchWord) != string::npos && separated[i].find(searchWord)==0)
            {
                flag = 1;
                return i+1;
            }
        }

        if(flag == 0)
            return -1;
        return -2;
        
    }

int main()
{
    auto start = high_resolution_clock::now();

    string sentence = "i use triple pillow";
    string searchWord = "pill";

    int sol = isPrefixOfWord(sentence, searchWord);

    cout<<"\nString found: "<<sol<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}