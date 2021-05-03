#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int test_case, length , target ;
vector<int> ans;
vector<int> findPos(int t, int n){
    vector<int> pos;
    t -= (n-1);
    for(int i = n-1; i >0 ;i --)
    {
       if(t - i >= 0)
       {
           pos.push_back(i);
           t -= i;
        if(t == 0)
        break;
       }
       else
       pos.push_back(0);
    }
    return pos;
}


int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> test_case;
    
    
    for(int test = 1; test <= test_case; test++){
      vector<int> iVec; 
      cin >> length >> target ;
      if(target < length-1){cout <<"Case #" << test << ": " << "IMPOSSIBLE" << endl; continue;}
      if(target > length*(length+1)/2 - 1){cout << "Case #" << test<< ": " << "IMPOSSIBLE" << endl; continue;}
      
      for(int i = 0 ; i <length; i++)
      iVec.push_back(i+1);
      
      if(target != length-1){
      vector<int> iPos = findPos(target, length);
      cout << "Case #" << test<< ": " ;
      for(int index =iPos.size()-1; index >=0; index--){
      
      if(iPos[index] != 0){
      int front = index;
      int back = iPos[index]+index;
      int temp = iVec[front];
      iVec[front] = iVec[back];
      iVec[back] = temp;
      
      while(front < back)
      {
          front++;
          back--;
          if(front>=back)
          break;
      temp = iVec[front];
      iVec[front] = iVec[back];
      iVec[back] = temp;
      }
      }
      
      }
        for(auto e : iVec)  
        cout << e << " ";
        cout << endl;
     }
      else
      {
        cout <<"Case #" << test <<": " ;
        for(auto e : iVec)
        cout << e << " ";
        cout << endl;
      }
      
    }
    
    
    
}
