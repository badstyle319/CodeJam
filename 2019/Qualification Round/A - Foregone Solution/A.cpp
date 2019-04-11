#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
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

void solve()
{
	int idx;
	string s;
	cin>>s;
	idx = s.length()-1;
#ifdef BG
	cout<<"("<<s<<") ";
#endif
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='4')
		{
			idx = min(i, idx);
			cout<<'1';
		}
		else
			cout<<s[i];
	}
	cout<<' ';
	for(int i=0; i<s.length();i++)
	{
		if(s[i]=='4')
			cout<<'3';
		else
		{
			if(i>=idx)
				cout<<'0';
		}
	}
	cout<<endl;
}

int main()
{
#ifdef BG
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	int case_num, no=1;
	cin>>case_num;
	while(case_num-->0){
		cout<<"Case #"<<no++<<": ";
		solve();
	}
	
#ifdef BG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
