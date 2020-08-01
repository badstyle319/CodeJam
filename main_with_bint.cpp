#include <bits/stdc++.h>

#define LL long long

using namespace std;

class bint
{
	static const int DLM = 4096; //digital length max
	static const int B = 100000000; //base
	static const int LB = (int)log10(B);
	static const int DIGIT_SIZE = DLM / LB + 1 ; //bint*bint
    
	bool bNeg;
	bint _abs(const bint& y)
	{
		if(y.bNeg)
			return -y;
		return y;
	}
	
public:
	int d[DIGIT_SIZE], l;
	int operator [](int i) const { return d[i]; }
	int &operator [](int i) { return d[i]; }
    
	bint(): bNeg(false)
	{
		memset(d, 0, sizeof(d));
		l = 1;
	}

	bint(LL x): bNeg(false)
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
        LL t = (LL) x;
        assert(t <= LLONG_MAX);
		*this = bint(t);
	}
	
	bint(string s): bNeg(false)
	{
		int i, j, n;
        size_t pos;

		//erase leading 0
		s.erase(0, min(s.find_first_not_of('0'), s.size()-1));

		if((pos=s.find_first_of('-'))!=string::npos)
		{
			s.erase(pos, 1);
			bNeg = true;
		}
        i = (int)pos;
		
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
	bool operator<(const bint& y) const
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
	//not equal with
	bool operator!=(const bint& y)
	{
		return !(*this==y);
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
	//multiplication for int
	bint operator*(int y)
	{
        return (*this) * bint(y);
	}
	//multiplication for bint
	bint operator*(const bint& y)
	{
		bint x(*this);
		int i, j;
		LL h;
		bint z;
		for(h=0, z.l=x.l+y.l, i=0; i<z.l; z[i]=h%B, h/=B, i++)
			for(j=i<x.l-1?i:x.l-1; j>=0 && i-j<y.l; h+=(LL)x[j]*y[i-j], j--);
		for(; z.l>1 && !z[z.l-1]; z.l--);
		return z;
	}
	//division for int
	bint operator/(int y)
	{
		bint x(*this);
		int i;
		LL h;
		for(h=0, i=x.l-1; i>=0; h=h*B+x[i], x[i]=h/y, h%=y, i--);
		for(; x.l>1 && !x[x.l-1]; x.l--);
		return x;
	}
	//division for bint
	bint operator/(bint y)
	{
		bint x(*this);
		int i;
		bint h, t;
		if(y.l==1) 
			return x/y[0];
		for(h=0, i=x.l-1; i>=0; h=h-y*x[i], i--)
			for(t=x[i], h=h*B+t, x[i]=((h.l>y.l)*((LL)h[h.l-1]*B*B+(LL)h[h.l-2]*B+h[h.l-3])+(h.l==y.l)*((LL)h[h.l-1]*B+h[h.l-2]))/((LL)y[y.l-1]*B+y[y.l-2]); x[i] && h<y*x[i]; x[i]--);
		for(; x.l>1 && !x[x.l-1]; x.l--);
		return x;
	}
	//modulo for int
	bint operator%(const int& y)
	{
		bint x(*this);
		int i;
		LL h;
		for(h=0, i=x.l-1; i>=0; h=h*B+x[i], h%=y, i--);
		return h;
	}
	//modulo for bint
	bint operator%(const bint& y)
	{
		bint x(*this);
		if(x<y)
			return x;
		else if(x==y)
			return 0;
		
		if(y.l==1) 
			return x%y[0];
		
		return x-x/y*y;
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

void solve()
{
	cout<<endl;
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