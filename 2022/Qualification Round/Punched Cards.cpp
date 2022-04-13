#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int R, C;
	
	cin >> R >> C;
	
	for(int i = 0; i < R * 2 + 1; i++)
	{
		for(int j = 0; j < C * 2 + 1; j++)
		{
			if(i <= 1 && j <= 1)
			{
				cout << ".";
			}
			else
			{
				if(i % 2 == 0)
				{
					cout << (j % 2 ? "-" : "+");
				}
				else
				{
					cout << (j % 2 ? "." : "|");
				}
			}
		}
		cout << endl;
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
		cout << "Case #" << case_no++ << ":" << endl;
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