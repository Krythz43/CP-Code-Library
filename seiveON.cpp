    
    
    vector<bool> prime(1e6 + 5,true);
    prime[1] = false;
    rep(i,prime.size(),2){
        if(!prime[i])continue;
        for(int j = 2*i; j < prime.size(); j += i)prime[i] = false;
    }