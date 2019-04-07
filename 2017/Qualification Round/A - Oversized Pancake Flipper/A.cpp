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

#define FILENAME "A-large"

int main()
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	
	int T, caseNo=1;
	cin>>T;
	
	string S;
	int ans, K;
	bitset<1000> val;
	
	while(caseNo<=T){
		cin>>S>>K;
		
		val.reset();
		ans = 0;
		
		for(int i=0;i<S.size();i++)
			if(S[i]=='+')
				val[i] = 1;
		
		while(val.count()!=S.size() && ans!=-1){
			for(int i=0;i<S.size();i++){
				if(!val[i]){
					if((i+K)<=S.size()){
						for(int j=0;j<K;j++)
							val.flip(i+j);
						ans++;
					}else{
						ans = -1;
					}
					break;
				}
			}
		}
		
		
		cout<<"Case #"<<caseNo<<": ";
		if(ans>=0)
			cout<<ans;
		else
			cout<<"IMPOSSIBLE";
		cout<<endl;
		
		caseNo++;
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
