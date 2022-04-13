#include <bits/stdc++.h>

using namespace std;

void solve()
{
	vector< vector<int> > data(3, vector<int>(4, 0));
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cin >> data[i][j];
			if(i)
			{
				data[0][j] = min(data[0][j], data[i][j]);
			}
		}
	}
#ifdef DBG
	for(int i = 0; i < 4; i++)
		cout << data[0][i] << " ";
	cout << endl;
#endif
	
	cout << " ";
	int sum = 0;
	for(int i = 0; i < 4; i++)
		sum += data[0][i];
	
	if(sum < 1e6)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		sum = 1e6;
		int temp;

		for(int i = 0; i < 4; i++)
		{
			temp = min(sum, data[0][i]);
			sum -= temp;
			if(i != 0)
				cout << " ";
			cout << temp;
		}
	}
	
	cout<<endl;
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