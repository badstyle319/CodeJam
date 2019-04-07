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

void solve(string& str){
	if(str.size()>1){
			for(int i=1;i<str.size();i++){
				if(str[i]<str[i-1]){
					string temp(str.size()-i, '9');
					str.replace(i, temp.size(), temp); 
					for(int j=i-1;j>=0;j--){
						if(str[j]>'1'){
							str[j]-=1;
							solve(str);
							break;
						}else{
							if(j==0){
								str.erase(0, 1);
								break;
							}else{
								str[j] = '9';
							}
						}
					}
					break;
				}
			}
		}
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	int T, caseNo=1;
	string N;
	cin>>T;
	
	while(caseNo<=T){
		cin>>N;

		solve(N);
		
		cout<<"Case #"<<caseNo<<": "<<N<<endl;
		
		caseNo++;
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
