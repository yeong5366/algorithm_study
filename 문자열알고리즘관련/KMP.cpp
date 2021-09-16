#include<iostream>
#include<vector>
#include<string>

//접두사와 접미사의 길이를 증가시켜 비교하다가 일치하지않을때 일치했던 부분까지 되돌아가서 검사하는 KMP
//최대 일치 길이 테이블을 구현

using namespace std;

vector <int>position;

vector<int> makeTable(string pattern)
{
	int patternsize = pattern.size();
	vector<int> table(patternsize, 0); //{0,0,0,...}을 생성 벡터를 쓰는 이유는 가변길이를 위함
	int j = 0;
	for (int i = 1; i < patternsize; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];//**잘 이해안가니까 일단 외워두자KMP
			//j가 처음자리(0)으로 돌아가거나, pattern[i]=[j]가 될때까지 검사하는 j의 위치를 옮긴다.
		}
		//위의 while문으로 인해 j가 0으로 돌아가거나 접두,접미가 같아질때까지 줄어든다면
#		//j을 이동시키자
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern)
{
	vector<int> table = makeTable(pattern);//일치길이 테이블
	int parentsize = parent.size();
	int patternsize = pattern.size();

	int j = 0;

	for(int i=0; i<parentsize;i++)
	{
		while (j > 0 && parent[i]!=pattern[j])
		{
			j = table[j - 1];//실패함수
		}
		if (parent[i] == pattern[j])
		{
			if (j == patternsize - 1)
			{
				position.push_back(i - j);//일치한 위치
				j = table[j];//pattern안의 접두사 바로 다음 위치
			}
			else
				j++;
		}
	}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string pattern = "abacaaba";//찾을 문자열
	string parent = "aaaccabacaabaccdcaaabacaabac";

	//step 1. 패턴에서 최대 일치 길이 테이블을 구축한다.
	//vector<int>table = makeTable(pattern);//최대 일치 길이 테이블
	/*for (int i = 0; i < table.size();i++)
	{
		printf("%d", table[i]);
	}*/
	KMP(parent, pattern);

	for (int x : position)
	{
		cout << x+1 << "번째 출현"<<endl;
	}
	cout << endl;

	return 0;

}
