#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
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

unordered_map<char, pair<int,int> > mp;

void solve(vector< vector<char> > &arr, int x, int y, int w, int h){
	if(x>=arr.size() || y>=arr[0].size())
		return;
	
	for(auto it: mp)
		cout<<it.first<<endl;
	cout<<endl;
	if(mp.size()==1){
		for(int i=x;i<x+w;i++){
			for(int j=y;j<y+h;j++){
				if(arr[i][j]=='?')
					arr[i][j]='a';//it->first;
			}
		}
		return;
	}
	
	// int posX=it->second.first, posY=it->second.second;
	// for(int i=y;i<y+w;i++){
		// cout<<arr[posX][i]<<" ";
	// }
	// cout<<endl;
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
		int R, C;
		cin>>R>>C;
		vector< vector<char> > arr(R, vector<char>(C, ' '));
		mp.clear();
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++){
				cin>>arr[i][j];
				if(arr[i][j]!='?')
					mp[arr[i][j]] = make_pair(i, j);
			}
		
		solve(arr, 0, 0, R, C);
		
			
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
		
		
		
		cout<<"Case #"<<no++<<":"<<endl;
		
	}
	
	
#ifdef D
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
