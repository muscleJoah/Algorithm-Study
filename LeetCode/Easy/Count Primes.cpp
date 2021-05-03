//leetcode 204
//브루트 포스는 당연히 안된다 
//<<<<에라스토네스의 체>>>>>  라는 신기한 알고리즘을 발견함


class Solution {
public:
   
    int countPrimes(int n) {

        if(n <=2 )
            return 0;
        
        bool* PrimeArray = new bool[n]; // 2~ n-1까지 저장할 수 있게.
        
        for(int i=2 ; i <n; i++)
            PrimeArray[i] = true;
    
        for(int i =2 ; i *i<n; i++)
        {
            if(PrimeArray[i])
                for(int j=i*i; j <n; j+=i)
                    PrimeArray[j] = false;
        }
        int count = 0;
        for(int i =2; i <n ; i ++)
            if(PrimeArray[i])
                count++;
        return count;    
    }
};