#include<iostream>
#include<vector>
using namespace std;
int mod=1e9+7;
int MAXN=100001;
int spf[100001];
vector<bool> sieve(int n){
	vector<bool> nums(n+1,true);
	nums[0]=false;
	nums[1]=false;
	nums[2]=true;
	for(int i=2;i*i<=n;i++){
		if(nums[i]==true){
			for(int j=i*i;j<=n;j+=i){
				nums[j]=false;
			}
		}
	}
	return nums;
}
vector<pair<int,int> > primeFactorization(int n){
	vector<pair<int,int> >ans;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			int ctn=0;
			while(n%i==0){
				ctn++;
				n/=i;
			}
			pair<int,int> p;
			p.first=i;
			p.second=ctn;
			ans.push_back(p);

		}
		
	}
	if(n>1){
		pair<int,int> p;
			p.first=n;
			p.second=1;
		ans.push_back(p);
	}
	return ans;
}
int binaryExponentiation(int a,int b){
	if(b==0){
		return 1;
	}

	int res=binaryExponentiation(a,b/2);
	if(a%2==0){
		return (res*1LL*res)%mod;
	}
	else{
		return (a*(res*1LL*res)%mod)%mod;
	}
}


 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieveHelperForPrimeFactorization()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++){
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
    }
    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2){
        spf[i] = 2;
    }
 
    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 
int main(){
	
}
