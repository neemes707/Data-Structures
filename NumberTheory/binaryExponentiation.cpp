#include<iostream>
using namespace std;
int mod=1e9+7;
int power(int a,int n)
{
	if(n==0){
		return 1;
	}
	int res=power(a,n/2);
	if((n&1) ==0){
		return ((res%mod)*1LL*(res%mod))%mod;
	}
	else{
		return ((a%mod)*1LL*(res%mod)*(res%mod))%mod;
	}
}
//O(log(n))
int main()
{


}
