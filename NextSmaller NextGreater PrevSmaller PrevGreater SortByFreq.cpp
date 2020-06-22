// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[] = {2,4,1,7,3,9,8,1,3,7};
//     stack<int> s;
//     int prevsmaller[10];
//     for(int i=0;i<10;i++){
//         while(!s.empty() && s.top()>=arr[i])
//             s.pop();
//         if(s.empty())
//             prevsmaller[i] = -1;
//         else
//             prevsmaller[i] = s.top();
//         s.push(arr[i]);
//     }
//     for(int i=0;i<10;i++)
//         cout<<prevsmaller[i]<<" ";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[] = {2,4,1,7,3,9,8,1,3,7};
//     stack<int> s;
//     int prevgreater[10];
//     for(int i=0;i<10;i++){
//         while(!s.empty() && s.top()<=arr[i])
//             s.pop();
//         if(s.empty())
//             prevgreater[i] = -1;
//         else
//             prevgreater[i] = s.top();
//         s.push(arr[i]);
//     }
//     for(int i=0;i<10;i++)
//         cout<<prevgreater[i]<<" "; 
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[] = {2,4,1,7,3,9,8,1,3,7};
//     stack<int> s; 
//     int nextsmaller[10];
//     for(int i=9;i>=0;i--){
//         while(!s.empty() && s.top()>=arr[i])
//             s.pop();
//         if(s.empty())
//             nextsmaller[i] = -1;
//         else 
//             nextsmaller[i] = s.top();
//         s.push(arr[i]);
//     }
//     for(int i=0;i<10;i++)
//         cout<<nextsmaller[i]<<" "; 
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[] = {2,4,1,7,3,9,8,1,3,7};
//     stack<int> s;  
//     int nextgreater[10];
//     for(int i=9;i>=0;i--){
//         while(!s.empty() && s.top()<=arr[i])
//             s.pop();
//         if(s.empty())
//             nextgreater[i] = -1;
//         else
//             nextgreater[i] = s.top();
//         s.push(arr[i]);
//     }
//     for(int i=0;i<10;i++)
//         cout<<nextgreater[i]<<" "; 
// }

// #include<bits/stdc++.h>
// using namespace std;

// bool cmp(pair<int,int> p1,pair<int,int> p2){
//     if(p1.second!=p2.second)
//         return p1.second>p2.second;
//     return p1.first<p2.first;
// }

// int main(){
//     int arr[] = {2,2,3,2,3,4,5,4,3,3,5,3,1};
//     unordered_map<int,int> m;
    
//     for(int i=0;i<13;i++)
//         m[arr[i]]++;
//     vector<pair<int,int>> v(m.begin(),m.end());
//     sort(v.begin(),v.end(),cmp);
//     for(int i=0;i<v.size();i++){
//         while(v[i].second--)
//             cout<<v[i].first<<" ";
//     }
// }


