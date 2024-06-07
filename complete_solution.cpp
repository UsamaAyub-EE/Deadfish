#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_set>
#include<climits>
const long long int MAX_N=pow(LLONG_MAX,0.5);
using namespace std;
void printset(unordered_set <long long int> nums)
{
	for(auto it=nums.begin();it!=nums.end();++it)
		cout<<" , "<<*it;
	cout<<endl;
}
long long int sort_digits(long long int n)
{
	if(n<12)
		return n;
	vector<long long int> digits;
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
long long int perform_operation(long long int n,char choice)
{
	if(choice=='i')
		return ++n;
	if(choice=='d')
		return --n;
	if(choice=='s')
		return n*n;
	if(choice=='p')
		return sort_digits(n);
	else
		return n;
}
class Deadfish{
	public:
	int short_code(int N)
	{
		if(N<4)
			return N;
		size_t count=2;
		unordered_set <long long int> nums;
		unordered_set <long long int> prev_nums;
		unordered_set <long long int> temp_nums;
		nums.insert(2);
		prev_nums.insert(1);
		prev_nums.insert(2);
		long long int tmp,temp;
		while(1)
		{
			++count;
			for(auto it=nums.begin();it!=nums.end();++it)
			{
				tmp=*it;
				temp=perform_operation(tmp,'i');
				if(temp==N)
					return count;
				if(prev_nums.find(temp)==prev_nums.end())
				{
					prev_nums.insert(temp);
					temp_nums.insert(temp);
				}
				temp=perform_operation(tmp,'d');
				if(temp==N)
					return count;
				if(prev_nums.find(temp)==prev_nums.end())
				{
					prev_nums.insert(temp);
					temp_nums.insert(temp);
				}
				temp=perform_operation(tmp,'s');
				if(temp==N)
					return count;
				if(tmp<MAX_N && prev_nums.find(temp)==prev_nums.end())
				{
					prev_nums.insert(temp);
					temp_nums.insert(temp);
				}
				temp=perform_operation(tmp,'p');
				if(temp==N)
					return count;
				if(prev_nums.find(temp)==prev_nums.end())
				{
					prev_nums.insert(temp);
					temp_nums.insert(temp);
				}
			}
			nums.clear();
			nums=temp_nums;
			temp_nums.clear();
		}
	}
	int shortestCode(int N)
	{
		size_t count=0;
		int temp=N;
		while(temp>110)
		{
			auto sq_root=sqrt(temp);
			auto Floor=floor(sq_root);
			auto Ceil=ceil(sq_root);
			auto temp2=temp;
			temp=abs(Floor*Floor-temp2)<abs(Ceil*Ceil-temp2)?Floor:Ceil;
			count+=abs(temp*temp-temp2)+1;
		}
		return count+short_code(temp);
	}
};
int main()
{
  	Deadfish obj;
  	int n;
	while(1)
	{
		cout<<"Enter the number\n";
		cin>>n;
		cout<<"Shortest code for this  "<<n<<" is "<<obj.shortestCode(n)<<"\n";
	}
	return 0;
}
