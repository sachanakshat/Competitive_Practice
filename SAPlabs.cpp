#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

#define MAX = INT32_MAX;

using namespace std;
using namespace std::chrono;

class Integer
{
        int num;
public:
        Integer()
        {
                num = 0;
                cout << "Constructor 1";
        }
        Integer(int arg)
        {
                cout << "Constructor 2";
                num = arg;
        }
        int getValue()
        {
                cout << "Constructor 3";
                return num;
        }
};
int main()
{
        Integer i;
        cout<<"\nBefore Initialization"<<endl;
        i = 10;
        cout<<"\ni=10 initilized"<<endl;
        cout << i.getValue();
        cout<<endl;
        return 0;
}