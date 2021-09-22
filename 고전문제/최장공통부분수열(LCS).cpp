//최장 공통 부분 수열 (Longest Common Subsequence)
//고전 문제
/*
두 개의 수열에 대해서 가장 긴 공통 부분 수열을 찾는 문제로, 고전적인 문제이다(풀려고 했는데 안풀리는 이유가 있다..)
더 작은 부분 문제로 문제를 쪼갠다.

<첫 번째 성질>
두 수열이 같은 원소로 끝난 다고 생각할때, 서로 다른 원소가 나올때까지 원소를 삭제한다
ex) BANANA, ATANA - ANA 삭제
BAN, AT - 두 수열의 LCS는 A가 됨
A+ANA = AANA : 원 수열의 LCS

이건 결국
X[i]==Y[j] 일때 LCS(i+1,j+1) = LCS(i,j)+1; //왜냐면 같으니까 부분수열에 한칸 더 붙는 것이다

LCS(Xn,Ym) = (LCS(Xn-1,Ym-1),xn)
Xn과 Ym의 LCS을 계산하려면 더 짧은 수열 Xn-1과 Ym-1의 LCS을 계산하여 붙여야하는 수열 xn을 붙인다.

<두 번째 성질>
두 수열 X,Y 가 위와 같이 같은 원소로 끝나지 않을때, 
LCS(Xn,Ym) = max(LCS(Xn,Ym-1),LCS(Xn-1,Ym)
그러니 당연히 둘 중 하나의 수열에서 마지막 원소를 뺀것의 LCS 값과 LCS(Xn,Ym)의 값은 같다(정확히는 최대값)


예시

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int LCS[1001][1001];//반복문 안에서 선언하면 Runtime error 가 발생한다. 어차피 해당 matrix의 서쪽과 북쪽둘레가 0으로 되어있어서, 초기화를 따로 해주지않더라도 혼동되지않고 새로 값을 덮어씌울수있다.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	for (int t = 1;t <= test;t++)
	{
		int n;
		string str1, str2;
		//int LCS[1001][1001];

		cin >> str1 >> str2;
		int len1 = str1.size(), len2 = str2.size();

		for (int i = 0; i < len1;i++)
		{
			for (int j = 0; j < len2;j++)
			{
				if (str1[i] == str2[j])
				{
					LCS[i + 1][j + 1] = LCS[i][j] + 1;//두 수열의 끝 문자가 같으면 해당 문자를 뺐을때 작은 수열의 LCS 값에 +1을 한 것과 같다
				}
				else
				{
					LCS[i + 1][j + 1] = max(LCS[i + 1][j], LCS[i][j + 1]);
					//끝문자가 같지않으면
					//1. 부분수열이 str1의 끝점을 가질때: 원 str1, str2는 하나뺀 수열에서의 LCS
					//2. 부분수열이 str2의 끝점을 가질때: 원 str2, str1의 원소를 하나 뺀 수열에서의 LCS
					//1,2중 더 긴 부분 수열이 현 str1,2의 부분 수열이 된다.
				}
			}
			
		}

		cout << "#" << t << " " << LCS[len1][len2] << "\n";
	}



	return 0;
}
