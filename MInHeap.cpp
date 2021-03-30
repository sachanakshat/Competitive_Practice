vector<int> C(A.begin(), A.end());
    make_heap(C.begin(), C.end(), greater<int>());
    //cout<<C.front()<<endl;
    
    
    cout<<"Old size = "<<C.size()<<" ";
    
    for(int i=1; i<B; i++)
    {
        pop_heap(C.begin(), C.end());
        C.pop_back();
    }
    
    int d = C.front();
    
    cout<<"New size = "<<C.size()<<" ";
    
    for(int i = 0; i<C.size(); i++)
    {
        cout<<C[i]<<" ";
    }
    
    return C.front();
