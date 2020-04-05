#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265
#define dbg printf

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

typedef struct
{
	int start;
	int end;
}ACT;

void solve()
{
	int N, counter = 0, act1 = -1, act2 = -1;
	vector<int> v;
	map<int, ACT > mp;
	string result;

	cin>>N;
	result = string(N, 'x');
	for(int i=0; i<N; i++)
	{
		ACT a;
		cin>>a.start>>a.end;

		mp[i] = a;
		v.push_back(a.start);
		v.push_back(-a.end);
	}

	sort(v.begin(), v.end(),
		[](int i, int j)
		{
			if(abs(i) == abs(j))
				return i < j;
			return abs(i) < abs(j);
		});

	for(int i = 0; i < v.size(); i++)
	{
		if(v[i]>=0)
			counter++;
		else
			counter--;

		if(counter > 2)
		{
			result = "IMPOSSIBLE";
			break;
		}

		if(v[i] >= 0)
		{
			if(act1 == -1)
			{
				act1 = i;
				continue;
			}
			else if(act2 == -1)
			{
				act2 = i;
				continue;
			}
		}

		if(v[i] < 0)
		{
			for(auto m:mp)
			{
				if(act1 != -1 && v[act1] == m.second.start && v[i] == -m.second.end)
				{
					act1 = -1;
					result[m.first] = 'C';
					mp.erase(m.first);
					break;
				}
				else if(act2 != -1 && v[act2] == m.second.start && v[i] == -m.second.end)
				{
					act2 = -1;
					result[m.first] = 'J';
					mp.erase(m.first);
					break;
				}
			}
		}
	}

	cout<<result;
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int case_num, no=1;
	cin>>case_num;
	while(case_num-->0){
		cout<<"Case #"<<no++<<": ";
		solve();
	}

	return 0;
}
