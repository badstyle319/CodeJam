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

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

#define FILENAME "sample"

unsigned char solve(int num){
	int temp;
	do{
		temp = num % 10;
		if(temp == 4)
			return 1;
	}while(num/=10);
	return 0;
}

unordered_map<int,unsigned char> mpContains4;

int main()
{
#ifdef BG
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	int case_num, no = 1, test_num, temp;
	
	cin>>case_num;
	while(case_num-->0){
		cin>>test_num;
#ifdef BG
	cout<<test_num<<": ";
#endif
		int num1 = 0, num2 = 0, k = 1;
		do{
			temp = test_num % 10;
			if(temp==4)
			{
				num1 += k;
				num2 += 3 * k;
			}else{
				num1 += temp * k;
			}
			k*=10;
		}while(test_num/=10);
#ifdef BG
	cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl;
#endif
		cout<<"Case #"<<no++<<": "<<num1<<" "<<num2<<endl;
	}
	
#ifdef BG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
