#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N;
    
    cin>>N;
    cin.ignore(1024, '\n');
    
    if(!N)
        cout << "INSOMNIA";
    else
    {
        bitset<10> bs;
        int i;
        
        for(i = 1; ; i++)
        {
            int n = N * i;
            while(n)
            {
                int digit = n % 10;
                bs.set(digit, 1);
                n /= 10;
            }
            if(bs.count() == 10)
                break;
        }
        cout << N * i;
    }
    
    cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef DBG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	// clock_t begin = clock();
#endif
    
	int T, case_no = 1;
	
    cin >> T;
    cin.ignore(1024, '\n');
	while(T--)
    {
		cout << "Case #" << case_no++ <<": ";
		solve();
	}
    
#ifdef DBG
	// clock_t end = clock();
	// double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    // cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}