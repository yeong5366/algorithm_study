#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector <int> position;
int skiplist[27];

//key: 틀렸을때 얼마나 스킵하는지 알려주는 스킵테이블의 구현

void make_skiptable(string pattern)
{
	int NUM = 27; //알파벳수
	int M = pattern.size(); //패턴의 길이
	fill(skiplist, skiplist + NUM, M);//패턴의 길이만큼 스킵테이블을 채웁니다

	for (unsigned int i = 0; i < M-1; i++)//i=M-1일때는 어차피 테이블에 M값이 채워지거나 혹은 이전에 처리된 0이외의 최솟값이 있으므로 M을 제외해도된다.
	{
		skiplist[pattern[i] - 'a'] = M - i - 1;//알파벳별 스킵구간 완성->틀렸을때 얼마나 점프해서 확인할 것인지
		//여러 배열들이 있어도 이게 최솟값이 되어야하는게 i는 더 커지니까 더 뒤쪽에서 중복해서 나오면 최소값 갱신된다
	}
}//알파벳별 전체 스킵리스트를 만들었다! 이야~신나~~

void boyer_moore(string parent, string pattern)
{
	int parentsize = parent.size();
	int patternsize = pattern.size();

	int i = patternsize-1;
	int j = patternsize - 1;

	while(i<parentsize)
	{
		
	
		if (parent[i - (patternsize - 1 - j)] == pattern[j])
		{
			j--;
			if (j < 0)//뺏더니 음수라는건 완전히 맞는 곳을 찾았다는 거
			{
				position.push_back(i - (patternsize)+1);//발견되는 위치
				i += skiplist[parent[i] - 'a'];//skipvalue만큼 스킵할것임
				j = patternsize - 1;//j도 원상복구
			}
		}
		else//다른 것을 찾았다
		{
			i += skiplist[parent[i] - 'a'];//skipvalue만큼 스킵할것임
			j = patternsize - 1;//j도 원상복구
		}


	}

}

int main()
{
	string sentence = "banana";
	string pattern = "ana";

	make_skiptable(pattern);

	for (int x : skiplist)
	{
		cout << x << " ";
	}
	cout << endl;

	boyer_moore(sentence, pattern);
	for (int x : position)
	{
		cout << x+1 << " ";//발견되는 위치
	}
	cout << endl;
	
	return 0;
}
