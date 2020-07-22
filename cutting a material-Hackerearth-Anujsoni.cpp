#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		if(n == 0)
			cout<<1;
		else{
			cout<<1 + n*(n+1)/2;
		}
		cout<<endl;
	}
}
