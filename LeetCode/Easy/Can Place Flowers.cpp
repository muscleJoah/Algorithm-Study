//leetcode 605.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        for( int i =0;i <  flowerbed.size(); i++){
            
            if(flowerbed[i]==0 && (i == 0 || flowerbed[i-1] == 0) && (flowerbed.size() == i+1 || flowerbed[i+1] == 0 ) ){
                cout << i << endl;
                n--;
                flowerbed[i] = 1;
            }
            if(n == 0)
                return true;
        }
    return false;
    }
    
};