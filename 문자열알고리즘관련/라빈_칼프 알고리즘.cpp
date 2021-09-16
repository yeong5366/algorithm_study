//해시함수를 이용해서 한번 비교할때마다 O(1)의 시간복잡도로 패턴과 비교하는 알고리즘

#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

vector<int>position;

bool checksmall(string subparent, string pattern, int start,int patternsize)
{
	for (int i = 0; i < patternsize;i++)
	{
		if (subparent[start + i] != pattern[i])
		{
			return false;
		}
	}//hash값이 일치할때 정말로 패턴이 일치하는지 확인한다

	return true;
}

void hash_function(string parent, string pattern)
{
	int m = pattern.size();
	int parentsize = parent.size();

	long long patternhash=0, parenthash =0;
	long long tmp1, tmp2;

	for (int i = 0; i < m;i++)
	{
		tmp1 = pattern[i] - 'a' + 97; tmp2 = parent[i] - 'a' + 97;
		patternhash += pow(2, 64 - i)*(tmp1);
		parenthash += pow(2, 64 - i)*(tmp2);
	}//patternhash 구함

	for (int i = 0;i < parentsize - m + 1;i++)
	{
		if (parenthash == patternhash)
		{
			if (checksmall(parent, pattern, i, m))
			{
				position.push_back(i);
			}
		}
		tmp1 = parent[i + m]-'a'+97 ;
		tmp2 = parent[i] - 'a' + 97;
		parenthash = parenthash*2+ pow(2, 64 - (m-1))*(tmp1)-pow(2,64)*(tmp2);
	}
}


int main()
{

	string parent = "banananobanana";
	string pattern ="ana";

	hash_function(parent, pattern);

	for (int x : position)
	{
		cout << x+1 << " ";
	}
	cout <<"번째 등장"<< endl;

	return 0;
}
