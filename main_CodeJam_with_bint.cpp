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
	bool bNeg;
	bint _abs(const bint& y)
	{
		if(y.bNeg)
			return -y;
		return y;
	}
public:
	int operator [](int i) const { return d[i]; }
	int &operator [](int i) { return d[i]; }
	bint(): bNeg(false)
	{
		memset(d, 0, sizeof(d));
	}
	bint(long long x): bNeg(false)
	{
		if(x<0)
		{
			bNeg = true;
			x = ~x+1;
		}
		for(l=1,d[l-1]=x%B,x/=B;x;d[l++]=x%B,x/=B);
	}
	
	bint(int x)
	{
		*this = bint((long long)x);
	}
	
	bint(string s): bNeg(false)
	{
		int i, j, n;

		//erase leading 0
		s.erase(0, min(s.find_first_not_of('0'), s.size()-1));

		if((i=s.find_first_of('-'))!=string::npos)
		{
			s.erase(i, 1);
			bNeg = true;
		}
		n = s.length();
		
		for(l=(n+LB-1)/LB, i=0; i<l; i++)
			for(d[i]=0, j=0; j<LB; j++)
				if(n-i*LB-LB+j>=0) d[i]=d[i]*10+s[n-i*LB-LB+j]-'0';
	}
	
	bint(const char* s)
	{
		*this = bint(string(s));
	}
	
	//unary -
	bint operator-() const
	{
		bint x(*this);
		x.bNeg = !this->bNeg;
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
		if(bNeg==y.bNeg)
		{
			if(l!=y.l)
				return l<y.l;
			int i;
			for(i=l-1;i>=0&&d[i]==y[i];i--);
			return (i>=0 && (bNeg?y[i]<d[i]:d[i]<y[i]));
		}else{
			return bNeg;
		}
	}
	//equal with
	bool operator==(const bint& y)
	{
		if(bNeg!=y.bNeg || l!=y.l)
			return 0;
		int i;
		for(i=l-1;i>=0&&d[i]==y[i];i--);
		return i<0;
	}
	//addition
	bint operator+(const bint& y)
	{
		bint x(*this);
		if(x.bNeg==y.bNeg)
		{
			int i;
			LL h;
			for(h=0,i=0; i<x.l||i<y.l||h;h+=(i<x.l)*x[i]+(i<y.l)*y[i],x[i]=h%B,h/=B,i++);
			x.l = i;
			return x;
		}
		else if(_abs(y)<_abs(x))
		{
			int i;
			LL h;
			for(h=0, i=0; i<x.l; h+=x[i]-(i<y.l)*y[i]+B, x[i]=h%B, h/=B, h--, i++);
			for(; x.l>1 && !x[x.l-1]; x.l--);
			return x;
		}else if(_abs(x)<_abs(y))
			return bint(y) + (*this);
		else
			return 0;
	}
	//subtraction
	bint operator-(const bint& y)
	{
		return (*this)+(-y);
	}
	
	bint operator*(const int& y)
	{
		bint x(*this);
		int i;
		LL h;
		for(h=0, i=0; i<x.l || h; h+=(i<x.l)*(long long)x[i]*y, x[i]=h%B, h/=B, i++);
		for(x.l=i; x.l>1 && !x[x.l-1]; x.l--);
		return x;
	}
	
	bint operator/(const int& y)
	{
		bint x(*this);
		int i;
		long long h;
		for(h=0, i=x.l-1; i>=0; h=h*B+x[i], x[i]=h/y, h%=y, i--);
		for(; x.l>1 && !x[x.l-1]; x.l--);
		return x;
	}
	
	bint operator%(const int& y)
	{
		bint x(*this);
		int i;
		long long h;
		for(h=0, i=x.l-1; i>=0; h=h*B+x[i], h%=y, i--);
		return h;
	}
	
	friend ostream& operator<<(ostream& stream, bint x)
	{
		if(x.bNeg)
			stream<<'-';
		for(int i=x.l-1;i>=0;i--)
			if(i==x.l-1)
				stream << x[i];
			else
				stream<<setfill('0')<<setw(LB)<<x.d[i];
		return stream;
	}
	
	friend istream& operator>>(istream& in, bint& x)
	{
		string temp;
		in>>temp;
		x = bint(temp);
		return in;
	}
};

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

#define FILENAME "sample"

void solve()
{
	cout<<endl;
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
		cout<<"Case #"<<no++<<": ";
		solve();
	}
	
#ifdef BG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
