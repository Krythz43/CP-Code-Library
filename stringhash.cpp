#include <bits/stdc++.h>
using namespace std;

/*
    String hashes convert a string into a number so that strcmp is O(1) instead of O(|s|)

    Polynomial rolling hash is given below.
*/

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

/*
    For Fast hash of substrings, we could store prefix sum of their hashes
    And divide by p power i by taking its modular inverse and we are done.
*/


int main(){

}