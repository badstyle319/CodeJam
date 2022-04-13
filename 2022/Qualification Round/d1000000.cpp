#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int N;
	vector<int> v;
	
	cin >> N;
	v.resize(N, 0);
	
	for(int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	
#ifdef DBG
	for(auto it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
#endif
	
	int target = 0;
	for(auto it = v.begin(); it != v.end(); it++)
	{
		if(target < (*it))
		{
			target++;
		}
	}
	
	cout<< " " << target << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef DBG
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	// clock_t begin = clock();
#endif
    
	int T, case_no = 1;
	
    cin >> T;
	while(T--)
    {
		cout << "Case #" << case_no++ <<":";
		solve();
	}
    
#ifdef DBG
	// clock_t end = clock();
	// double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    // cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
	fclose(stdin);
	// fclose(stdout);
#endif 

	return 0;
}