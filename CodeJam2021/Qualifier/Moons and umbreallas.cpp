#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int test_case, length ,n, ans,X,Y;
string str;


int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> test_case;
    bool isFront = true;
    
    for(int test = 1; test <= test_case; test++){
        cin >> X >> Y >> str;
        ans = 0;
        for(int i =0 ; i < str.length(); i++ ){
            if(i == 0 && str[i] == '?')
                isFront = false;
            
            if(!isFront && str[i] != '?' ){
                for(int j = 0; j < i; j ++)
                str[j] = str[i];
                isFront = true;
            }
            
            if(str[i] == '?' && isFront)
            str[i] = str[i-1];

        }
        for(int i = 0 ; i < str.length()-1; i++){
            if(str.substr(i,2) == "CJ")
            ans += X;
            if(str.substr(i,2) == "JC")
            ans += Y;
        }
        
         cout << "Case #" << test << ": " << ans << endl; 
    }
       
    
}