#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <ctime>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

#define FILENAME "sample"

#define SWAP_PAIR(x)( (x) = make_pair((x).second, (x).first))

void solve(){
	
}

int main()
{
#ifdef BG
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	int case_num, no=1, N, L, i, cf, num1, num2, idx;
	vector<int> nums;
	unordered_map<int,pair<int,int>> factors;
	map<int,char> primes;
	
	cin>>case_num;
	while(case_num-->0){
		cin>>N>>L;
		
		nums.resize(L, 0);
		factors.clear();
		primes.clear();
		idx = -1;
		for(i = 0; i < L; i++)
		{
			cin>>nums[i];
			if(i>0)
			{
				if(nums[i]==nums[i-1])
				{
					if(nums[i]%2==0)
						cf = 2;
					else
					{
						for(int j=3; j<=(int)sqrt(nums[i]);j+=2)
						{
							if(nums[i]%j==0)
							{
								cf = j;
								break;
							}
						}
					}
				}
				else
				{
					if(idx==-1)
						idx = i;
					cf = __gcd(nums[i], nums[i-1]);
				}
				
				num1 = nums[i-1] / cf;
				factors[i-1] = make_pair(num1, cf);
				if(!primes.count(cf))
					primes[cf] = 'A';
				if(!primes.count(num1))
					primes[num1] = 'A';
				if(i == L-1)
				{
					num2 = nums[i] / cf;
					factors[i] = make_pair(cf, num2);
					if(!primes.count(cf))
						primes[cf] = 'A';
					if(!primes.count(num2))
						primes[num2] = 'A';
				}
			}
		}
		
		for(int l = idx; l > 0; l--)
			if(factors[l].first != factors[l-1].second)
				SWAP_PAIR(factors[l-1]);
		for(int r = idx; r < L-1; r++)
			if(factors[r].second != factors[r+1].first)
				SWAP_PAIR(factors[r+1]);
		
		i = 0;
		for(auto it = primes.begin(); it != primes.end(); it++)
		{
			it->second += i;
			i++;
		}
#ifdef BG
	// for(auto it = primes.begin(); it != primes.end(); it++)
		// cout<<it->first<<" "<<it->second<<endl;

	for(int i = 0; i < nums.size(); i++)
	{
		cout<<nums[i]<<" = "<<factors[i].first<<" x "<<factors[i].second<<endl;
	}
#endif

		cout<<"Case #"<<no++<<": ";
		for(i = 0; i < nums.size(); i++)
		{
			cout<<primes[factors[i].first];
			if(i==nums.size()-1)
				cout<<primes[factors[i].second];
		}
		cout<<endl;
	}
	
	
#ifdef BG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
