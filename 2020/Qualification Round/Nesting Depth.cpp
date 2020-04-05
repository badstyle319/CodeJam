#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

void solve()
{
	string s;
	int pre;
	
	cin>>s;
	
	pre = s[0] - '0';
	if(pre)
		cout<<string(pre, '(');
	cout<<pre;
	
	for(int i = 1; i < s.length(); i++)
	{
		int digit = s[i] - '0';
		
		if(pre < digit && digit)
			cout<<string(abs(pre-digit), '(');
		else if(pre > digit)
			cout<<string(abs(pre-digit), ')');
		
		cout<<digit;

		pre = digit;
	}
	if(pre)
		cout<<string(pre, ')');
	
	
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
