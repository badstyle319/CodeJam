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

#define FILENAME "sample"

void solve(string &str, int &start){
	vector<char> temp(1, str[start]);
	int cnt1 = 1;
	int cnt2 = 0;
	
	for(int i = start + 1; i < str.length(); i++)
	{
		if(temp.front()!=temp.back() && cnt1==cnt2)
		{
			break;
		}
		if(str[i]==temp.front())
			cnt1++;
		else
			cnt2++;
		temp.push_back(str[i]);
	}
	
	int j = start;
	while(temp.size()>0)
	{
		str[j++] = temp.back();
		temp.pop_back();
	}
	start = j;
}

int main()
{
#ifdef BG
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	int case_num, no=1, charNum;
	string str;
	
	cin>>case_num;
	while(case_num-->0){
		cin>>charNum>>str;
		
#ifdef BG
	cout<<endl<<str<<endl;
#endif
		int offset = 0;
		do{
			solve(str, offset);
		}while(offset<str.length());
		
		cout<<"Case #"<<no++<<": "<<str<<endl;
	}
	
	
#ifdef BG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
