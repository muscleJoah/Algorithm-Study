//https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/


class Solution {

public:
    int getGCD(int a, int b){
        if(a< b){
            int temp = a;
            a = b;
            b = temp;
        }
        
        if(b == 0)
            return a;
        else
            return gcd(b , a%b);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> v;
        int max = *max_element(deck.begin(), deck.end());
        
        for(int i = 0; i <= max; i++)
            v.push_back(0);
        
        for(auto element : deck)
            v[element]++;
        
        
        int gcd = -1234;
        
        for(int i = 0;i < v.size() ; i ++){
            if(v[i] > 0)
            { if(gcd == -1234)
                    gcd = v[i];
             else
                 gcd = getGCD(gcd, v[i]);
            }  
        }
        if(gcd == 1)
            return false;
        else
            return true;
        
        

        
    }
};