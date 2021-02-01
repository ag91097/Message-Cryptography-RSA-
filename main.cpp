#include<bits/stdc++.h>
using namespace std;

int main(){

    long p = 47;                              // 1st prime number
    long q = 53;                              // 2nd prime number
    long n = p*q;                             // 
    long phi = (p-1)*(q-1);                   // eular totient function phi(n)

    long e = 2;                              // encryption key(public key)

// FINDING 'e' such that e and phi are coprime
    while(e<phi){
        long num = __gcd(e, phi);
        if(num ==1){
            break;
        }else{
            e++;
        }
    }

// FINDING THE DECRYPTION KEY (PRIVATE KEY)     (e*d = 1 + i*phi) -> bcoz encryption and decryption key are mutiplicative inverse of each other
    long d;
    long k=1;
    while(1){
        k = k + phi;
        if(k % e == 0){
            d = k/e;
            break;
        }
    }

    cout<<"Encryption key:: "<<e<<"\nDecryption Key::  "<<d<<endl;

// ENCRYPTION OF MESSAGE
    cout<<"ENTER THE MESSAGE TO BE ENCRYPTED.\n";
    string s;                  // message by sender (need to be encrypted)
    getline(cin,s);
    int l = s.length();
    long en[l];                           // encrypted message stored here
    long temp[l];                         // after encrypting each character their integer equivqlent stored here
    long curr;
    for(int i=0;i<l;i++){
        curr = s[i];
        curr = curr-96;                  //curr = curr-96
        k = 1;
        for(int j=0;j<e;j++){
            k = (k*curr)%n;
        }
        temp[i] = k;
        en[i] = k+96;                //en[i] = k + 96;
    }
    cout<<"\nCIPHER TEXT IS:\n";
    for(int i=0;i<l;i++){
        cout<<char(en[i]);
    }
    cout<<endl;

    // decryption of message
    long m[l];                       // decrypted message stored here
    for(int i=0;i<l;i++){
        curr = temp[i];
        k = 1;
        for(int j=0;j<d;j++){
            k = (k*curr)%n;
        }
        m[i] = k+96;                //m[i] = k + 96;
    }

    cout<<"\nDECRYPTED MESSAGE IS::\n";
    for(int i=0;i<l;i++){
        cout<<char(m[i]);
    }
    return 0;
}