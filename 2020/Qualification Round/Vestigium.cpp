#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265
#define SIZE 101

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int nums[SIZE][SIZE];

void solve()
{
	int N;
	int k = 0, r = 0, c = 0;
	map<int, int> mp;
	
	memset(nums, 0, sizeof(nums));
	
	cin>>N;
	for(int row = 0; row < N; row++)
	{
		mp.clear();
		for(int col = 0; col < N; col++)
		{
			cin>>nums[row][col];
			
			if(row == col)
				k += nums[row][col];
			
			mp[nums[row][col]] = 1;
		}
		if(mp.size() != N)
			r++;
	}
	
	for(int col = 0; col < N; col++)
	{
		mp.clear();
		for(int row = 0; row < N; row++)
		{
			mp[nums[row][col]] = 1;
		}
		if(mp.size() != N)
			c++;
	}
	
	cout<<k<<" "<<r<<" "<<c;
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int case_num, no = 1;
	cin>>case_num;
	while( case_num-- > 0 ){
		cout<<"Case #"<<no++<<": ";
		solve();
	}

	return 0;
}
