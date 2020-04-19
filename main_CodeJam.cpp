#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>

#define PI 3.14159265

using namespace std;

template<typename T>
void PV(vector<T> &v)
{
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl;
};

// static int dx[] = {-1,-1,-1,0,0,1,1,1};
// static int dy[] = {-1,0,1,-1,1,-1,0,1};

void solve()
{
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
