#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void printMatrix(vector<vector<int>> matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    char esc_char = 27; // the decimal code for escape character is 27
    cout<<"\n";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

int rotateLeft(vector<vector<int>>& matrix, int i, int p, int q)
{
    int carry = matrix[i+p-1][i];
    // cout<<"\nCarry = "<<carry<<"\n";
    for(int j = i+p-1; j>i; j--)
    {
        // cout<<"\ni = "<<i<<" j = "<<j<<"\n";
        matrix[j][i] = matrix[j-1][i];
        // cout<<"\nmatrix["<<j<<"]["<<i<<"] "<<matrix[j][i]<<"\n";
    }
    return carry;
}

int rotateBottom(vector<vector<int>>& matrix, int i, int p, int q, int carry)
{
    int carry2 = matrix[i+p-1][i+q-1];
    int j;
    // int carry = matrix[i+p-1][i];
    for(j = i+q-1; j>i; j--)
    {
        // cout<<"\ni = "<<i<<" j = "<<j<<"\n";
        matrix[i+p-1][j] = matrix[i+p-1][j-1];
        // cout<<"\nmatrix["<<j<<"]["<<i<<"] "<<matrix[j][i]<<"\n";
    }
    matrix[i+p-1][j+1] = carry;
    return carry2;
}

int rotateRight(vector<vector<int>>& matrix, int i, int p, int q, int carry)
{
    int carry3 = matrix[i][i+q-1];
    int j;
    // int carry = matrix[i+p-1][i];
    for(j = i; j<i+p-1; j++)
    {
        // cout<<"\ni = "<<i<<" j = "<<j<<" p = "<<p<<" matrix["<<j<<"]["<<i+q-1<<"] = "<<matrix[j][i+q-1]<<"\n";
        matrix[j][i+q-1] = matrix[j+1][i+q-1];
        // cout<<"\nmatrix["<<j+1<<"]["<<i+q-1<<"] "<<matrix[j+1][i+q-1]<<"\n";
    }
    matrix[j-1][i+q-1] = carry;
    // cout<<"Carry rotateRight = "<<carry3<<"\n";
    return carry3;
}

int rotateTop(vector<vector<int>>& matrix, int i, int p, int q, int carry)
{
    int carry4 = matrix[i][i];
    int j;
    // int carry = matrix[i+p-1][i];
    for(j = i; j<i+q-1; j++)
    {
        // cout<<"\ni = "<<i<<" j = "<<j<<"\n";
        matrix[i][j] = matrix[i][j+1];
        // cout<<"\nmatrix["<<j<<"]["<<i<<"] "<<matrix[j][i]<<"\n";
    }
    matrix[i][j-1] = carry;
    return carry4;
}

void matrixRotation(vector<vector<int>>& matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();
    int carry, p = m, q = n;
    for(int j = 0; j<r; j++)
    {
        for(int i = 0; i<=min(p,q); i++, p-=2, q-=2)
        {
            // cout<<"\nPerforming rotation for i = "<<i<<" p = "<<p<<" q = "<<q;
            carry = rotateLeft(matrix, i, p, q);
            carry = rotateBottom(matrix, i, p, q, carry);
            carry = rotateRight(matrix, i, p, q, carry);
            rotateTop(matrix, i, p, q, carry);
        }
        p = matrix.size();
        q = matrix[0].size();
    }

}

int main()
{
    auto start = high_resolution_clock::now();
    
    vector<vector<int>> matrix{ {1,2,3,4,5,21,31},
                                {6,7,8,9,10,22,32},
                                {11,12,13,14,15,23,33},
                                {16,17,18,19,20,24,34},
                                {25,26,27,28,29,30,35},
                                {36,37,38,39,40,41,42}
                              };

    // vector<int> values;
    // vector<vector<int>> matrix;
    // int m,n,r,val;

    // cin>>m>>n>>r;
    // for(int i=0; i<m; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cin>>val;
    //         values.push_back(val);
    //     }
    //     matrix.push_back(values);
    //     values.clear();
    // }

    cout<<"\nMatrix before rotation: ";
    printMatrix(matrix);

    matrixRotation(matrix,99);

    cout<<"\nMatrix after rotation: ";
    printMatrix(matrix);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}