#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define MAX 5000000
const auto SQ_MAX=pow(MAX,0.5);
using namespace std;
long int sort_digits(long int n)
{
	if(n<12)
		return n;
	vector<int> digits;
	while(n>0)
	{
		digits.push_back(n%10);
		n/=10;
	}
	sort(digits.begin(),digits.end());
	for(auto i=(digits.size()-1);i!=-1;--i)
	{
		n=n*10+digits[i];
	}
	return n;
}
class Deadfish{
	public:
	int shortestCode(int N)
	{
		if(N<4)
			return N;
		vector<int> short_codes(MAX,MAX);
		long int count=0;
		vector<long int> nums(MAX);
		vector<long int> temp_nums(MAX);
		nums.clear();
		temp_nums.clear();
		nums.push_back(0);
		long int tmp,temp;
		while(1)
		{
			if(count==205)
				return count;
			++count;
			//cout<<"count is "<<count<<"\n";
			for(auto it=nums.begin();it!=nums.end();++it)
			{
				tmp=*it;
				temp=tmp+1;
				if(temp==N)
					return count;
				if(short_codes[temp]>count)
				{
					short_codes[temp]=count;
					temp_nums.push_back(temp);
				}
				temp=tmp-1;
				if(temp==N)
					return count;
				if(temp>0 && temp<MAX)
				{
					if(short_codes[temp]>count)
					{
						short_codes[temp]=count;
						temp_nums.push_back(temp);
					}
				}
				if(tmp<SQ_MAX)
				{
					temp=tmp*tmp;
					if(temp==N)
						return count;
					if(temp<MAX)
					{
						if(short_codes[temp]>count)
						{
							short_codes[temp]=count;
							temp_nums.push_back(temp);
						}
					}
				}
				temp=sort_digits(tmp);
				if(temp==N)
					return count;
				if(temp<MAX)
				{
					if(short_codes[temp]>count)
					{
						short_codes[temp]=count;
						temp_nums.push_back(temp);
					}
				}
			}
			nums.clear();
			nums=temp_nums;
			temp_nums.clear();
		}
	}
};
int main()
{
  	Deadfish obj;
  	int i;
  	cout<<"Enter the number\n";
  	cin>>i;
	cout<<"\nShortest code for "<<i<<" is "<<obj.shortestCode(i)<<"\n";
	char ch;
	cin>>ch;
	return 0;
}
