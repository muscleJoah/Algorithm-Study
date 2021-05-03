//codejam quali 1
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int test_case, length ,n, ans;



int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> test_case;

    
    for(int test = 1; test <= test_case; test++){
        cin >> length;
        vector<int> iVec;
        ans = 0;
        for(int index =0 ; index < length; index++)
            {
                cin >> n;
                iVec.push_back(n);
            }
        
        for(int index= 0; index < iVec.size()-1;  index++){
            int min = *min_element(iVec.begin()+index , iVec.end());
            int i = index ;
            int j = find(iVec.begin(), iVec.end(), min) - iVec.begin();
            
            //삼단논법으로 바꿔버리기
            int temp;
            temp = iVec[i];
            iVec[i] = iVec[j];
            iVec[j] = temp;
         
            ans += (j - i + 1);
            if(++i < --j)
            while(i < j)
            {
                int temp;
                temp = iVec[i];
                iVec[i] = iVec[j];
                iVec[j] = temp;
                i++;
                j--;
            }
            
            
        }
        cout << "Case #" << test << ": " << ans << endl; 
    }
}