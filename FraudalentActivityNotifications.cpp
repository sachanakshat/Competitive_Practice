#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void printdebug(vector<int> arr)
{
    int n = arr.size();
    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void printdebug(multiset<int> s)
{
    for(auto it:s)
        cout<<it<<" ";
}

int activityNotifications(vector<int>& expenditure, int d) {
    cout<<"\nactivityNotifications entered"<<endl;
    int n = expenditure.size(), notifs = 0;
    if(n<=d)
        return 0;

    //Multiset Initialized and values inserted
    multiset<int> s;

    cout<<"\nMultiset Declared"<<endl;
    cout<<endl;

    for(int j = 0; j<d-1; j++)
        s.insert(expenditure[j]);

    cout<<"\nPrinting set: ";
    printdebug(s);


    // multiset<int>:: iterator it;
    // it = s.find(2);
    // s.erase(it);
    // cout<<"\nAfter removing 2: ";
    // printdebug(s);

    for(int i = d; i<n; i++)
    {
        s.insert(expenditure[i-1]);
        multiset<int>:: iterator it;
        it = s.cbegin();
        std::advance(it,d/2);
        if(d%2 == 0)
        {
            auto iter2 = it--;
            if(expenditure[i] >= 2* double(*it + *iter2) / 2)
            {
                notifs++;
            }
        }
        else
        {
            if( expenditure[i] >= 2*(*it))
            {
                notifs++;
            }
        }
        cout<<" and i = "<<expenditure[i];
        it = s.find(expenditure[i-d]);
        s.erase(it);
        cout<<"\nAfter removing "<<expenditure[i-d]<<": ";
        printdebug(s);

    }

/*
    //Main loop
    for(auto i=expenditure.begin()+d; i!=expenditure.end(); i++)
    {
        cout<<"\nLoop Entered"<<endl;

        s.insert(*i-1);
        multiset<int>:: iterator it;

        cout<<"\nFirst element loop inserted"<<endl;
        // vector<int> median(i-d,i);
        // cout<<"\n";
        // cout<<"For subarray [";
        // printdebug(median);
        // sort(median.begin(), median.end());
        // cout<<"] sorted [";
        // printdebug(median);
        // cout<<"]";
        int n2 = s.size();

        cout<<"\nSize checked"<<endl;

        it = s.cbegin();

        cout<<"\niterator initialized"<<endl;
        
        std::advance(it,n2/2);
        
        cout<<"\nIterator Advanced"<<endl;
        cout<<"\nit = "<<*it<<endl;
        cout<<"\n"<<n2%2<<endl;
        
        if(n2%2 == 0)
        {
            cout<<"\n"<<n2%2<<endl;
            cout<<"\nIterator 2 set to it--"<<endl;
            
            auto iter2 = it--;
            
            cout<<"\nIterator 2 set to it--"<<endl;
            if(*i >= 2* double(*it + *iter2) / 2)
            {
                cout<<" Median = "<<double(*it + *iter2) / 2;
                notifs++;
            }
        }
        else
        {
            if( *i >= 2*(*it))
            {
                cout<<" Median = "<<(*it);
                notifs++;
            }
        }
        cout<<" and i = "<<*i;
        it = s.find(*i-d);
        s.erase(it);
        cout<<"\nAfter removing "<<*i-d<<": ";
        printdebug(s);

    }
    */
    return notifs;
}

int main()
{
    auto start = high_resolution_clock::now();
    // vector<int> expenditure{1,2,3,4,4};
    vector<int> expenditure;
    int val;
    for(int i=0;i<200000; i++)
    {
        cin>>val;
        expenditure.push_back(val);
    }

    cout<<"Array [";
    printdebug(expenditure);
    cout<<"]"<<endl;

    int result = activityNotifications(expenditure, 4);

    cout<<"\nNumber of notifications = "<<result<<endl;
    

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}