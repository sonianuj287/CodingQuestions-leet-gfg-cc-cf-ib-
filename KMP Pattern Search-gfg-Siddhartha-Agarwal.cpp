// { Driver Code Starts
//Initial Template for C++

// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

using namespace std;


 // } Driver Code Ends


//User function Template for C++

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string s, int M, int* lps) 
{ 
   int n=s.length();
    
    lps[0]=0;
    int len=0;
    for(int i=1;i<n;)
    {
        if(s[len]==s[i])
        {
            lps[i]=++len;
            i++;
        }
        else if(len==0)
        {
            lps[i]=0;
            i++;
        }
        else
        {
            len=lps[len-1];
        }
    }
}

// Returns true if pat found in txt
bool KMPSearch(string pat, string txt) {
    // Your code here
    
    int i=0, j=0;
    
    int n=txt.length(),m=pat.length();
    int lps[txt.length()];
    
    computeLPSArray(pat,pat.length(),lps);
    
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        
        if(j==m)
        {
            return true;
            j=lps[j-1];
        }
        
        if(pat[j]!=txt[i])
        {
            if(j==0)
            {
            i++;
            }
            else
            {
                
                j=lps[j-1];
            }
            
        }
        
    }
    
    return false;
}

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{ 
    int t;
    std::cin >> t;
    
    while(t--){
        string s, pat;
        cin >> s >> pat;
        if(KMPSearch(pat, s)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    
	return 0;
} 
  // } Driver Code Ends
