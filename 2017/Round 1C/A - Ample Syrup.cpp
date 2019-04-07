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
#define PI 3.14159265359

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

#define FILENAME "A-large"

void solve(){
	
}

int main()
{
#ifdef D
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	int case_num, no=1;
	
	cin>>case_num;
	while(case_num-->0){
		LL N, K, radius, height;
		map<LL, LL> mp;
		vector<LL> vals;
		
		cin>>N>>K;
		
		for(int i=0;i<N;i++){
			cin>>radius>>height;
			mp[radius*radius] = 2*radius*height;
			vals.push_back(2*radius*height);
			// cout<<radius*radius<<" "<<2*radius*height<<endl;
		}
		sort(vals.begin(), vals.end(), greater<LL>());

		LL ans=0;
		for(auto it=mp.rbegin();it!=mp.rend();it++){
			if(vals.size()>=K){
				int i=1;
				LL sum=it->first+it->second;
				for(int j=0;j<vals.size();j++){
					if(vals[j]==it->second){
						vals.erase(vals.begin()+j);
						break;
					}
				}
				
				for(int j=0;j<vals.size() && i<K;i++,j++){
					sum+=vals[j];
				}
				ans = max(ans, sum);
			}
		}
		
		cout.precision(9);
		cout.setf(ios::fixed, ios::floatfield);
		cout<<"Case #"<<no++<<": "<<ans*PI<<endl;
		
	}
	
	
#ifdef D
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
