/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

char uniqueChar(string s){
    string t=s;
    if(s.size()==0){
        return '0';
    }
    vector<int> alpha(26,0);
    for (int i=0;i<s.size();i++){
            if(s[i]-'a'>=0){
            alpha[s[i]-'a']++;
            }
            else{
                alpha[s[i]-'A']++;
            }
    }
     for(int j=0;j<s.length();j++){
            if(alpha[s[j]-'a']==1 || alpha[s[j]-'A']==1)
                return s[j];
                
    }
   
    return '0';
}

string transformedString(string s){
    vector<int> freq(128,0);
        for(char c : s) freq[c]++;
        vector<pair<int,char>> fp;
        for(int i=0; i<=127; i++) {
            fp.push_back(make_pair(freq[i],(char)i));
        }
        stable_sort(fp.begin(), fp.end(), []( const auto& lhs, const auto& rhs )
        {
            return lhs.first>rhs.first;
        });
        string res="";
        for(int i=127; i>=0; i--) {
            if(fp[i].first == 0) continue;
            res += string(fp[i].first, fp[i].second);
        }
        return res;
}

int main()
{
    
    string s;
    cout << "Enter a String"<<'\n';
    cin>>s;
    //got uniqueChar
    cout <<uniqueChar(s)<<'\n';
  
    cout <<transformedString(s);
    return 0;
}
