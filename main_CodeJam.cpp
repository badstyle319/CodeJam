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

class bint
{
	static const int DLM = 100; //digital length max
	static const int B = 100000; //base
	static const int LB = (int)log10(B);
	
	int d[DLM/LB], l;
	bool bSign;
public:
	int operator [](int i) const { return d[i]; }
	int &operator [](int i) { return d[i]; }
	bint(long long x): bSign(false)
	{
		if(x<0)
		{
			bSign = true;
			x = ~x+1;
		}
		for(l=1,d[l-1]=x%B,x/=B;x;d[l++]=x%B,x/=B);
	}
	
	bint(int x)
	{
		*this = bint((long long)x);
	}
	
	bint(string s): bSign(false)
	{
		int i, j, val;

		//erase leading 0
		s.erase(0, min(s.find_first_not_of('0'), s.size()-1));

		if((i=s.find_first_of('-'))!=string::npos)
		{
			s.erase(i, 1);
			bSign = true;
		}
		
		reverse(s.begin(), s.end());
		for(l=0,i=0; i<s.length(); i+=LB)
		{
			string s1=s.substr(i, LB);
			reverse(s1.begin(), s1.end());
			val = 0;
			for(j=0; j<s1.length(); j++)
				val = val*10+s1[j]-'0';
			d[l++] = val;
		}
	}
	
	bint(const char* s)
	{
		*this = bint(string(s));
	}
	
	//unary -
	bint operator-() const
	{
		bint x(*this);
		x.bSign = !this->bSign;
		return x;
	}
	//prefix ++
	bint& operator++()
	{
		*this = *this + 1;
		return *this;
	}
	//postfix ++
	bint operator++(int)
	{
		bint x(*this);
		++(*this);
		return x;
	}
	//prefix --
	bint& operator--()
	{
		(*this) = (*this) - 1;
		return *this;
	}
	//postfix --
	bint operator--(int)
	{
		bint x(*this);
		--(*this);
		return x;
	}
	//less than
	bool operator<(const bint& y)
	{
		if(bSign==y.bSign)
		{
			if(l!=y.l)
				return l<y.l;
			int i;
			for(i=l-1;i>=0&&d[i]==y[i];i--);
			return (i>=0 && d[i]<y[i]) ^ bSign;
		}else{
			return bSign;
		}
	}
	//equal with
	bool operator==(const bint& y)
	{
		if(bSign!=y.bSign || l!=y.l)
			return 0;
		int i;
		for(i=l-1;i>=0&&d[i]==y.d[i];i--);
		return i<0;
	}
	//addition
	bint operator+(const bint& y)
	{
		bint x(*this);
		if(x.bSign==y.bSign)
		{
			int i;
			LL h;
			for(h=0,i=0; i<x.l||i<y.l||h;h+=(i<x.l)*x.d[i]+(i<y.l)*y.d[i],x.d[i]=h%B,h/=B,i++);
			x.l = i;
		}
		return x;
	}
	//subtraction
	bint operator-(const bint& x)
	{
		return *this;
	}
	
	// bint operator*(const bint& x)
	// {
		// return *this;
	// }
	
	// bint operator*(const bint& x)
	// {
		// return *this;
	// }
	
	// bint operator%(const bint& x)
	// {
		// return *this;
	// }
	
	friend ostream& operator<<(ostream& stream, bint x)
	{
		if(x.bSign)
			stream<<'-';
		for(int i=x.l-1;i>=0;i--)
			stream<<x.d[i];
		return stream;
	}
};

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

#define FILENAME "sample"

void solve(){
	
}

int main()
{
#ifdef BG
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	int case_num, no=1;
	
	cin>>case_num;
	while(case_num-->0){
		
		
		
		
		
		cout<<"Case #"<<no++<<": "<<endl;
		
	}
	
	
#ifdef BG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
