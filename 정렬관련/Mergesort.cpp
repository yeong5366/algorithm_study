#include<iostream>
#include<algorithm>


int sorted[10000];

//2개의 인접한 배열 의 합병 과정이라는데..
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;//시작하는 값

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
		{
			//countval += (k - i);//얼마나 꼬인선을 풀어야하는지 (k는 i보다 언제나 클수밖에없다 근데 만약 같은 수가 여러개면 어떻게 되려나? )
			sorted[k++] = list[i++];//작은 애를 먼저 넣습니다.
		}
		else
		{
			sorted[k++] = list[j++];//오른쪽 청크의 값이 더 크다면 얘를 땡겨옵니다...			
		}
	}

	if (i > mid)
	{
		for (l = j;l <= right;l++)
			sorted[k++] = list[l];//오른쪽 청크 남은거 다 옮김
	}
	else {
		for (l = i;l <= mid;l++)
		{
			//countval += (k - l);//얼마나 꼬인선을 풀어야하는지 센다
			sorted[k++] = list[l];
		}
	}

	for (l = left;l <= right;l++)
	{
		list[l] = sorted[l];
	}
}

void merge_sort(int list[], int left, int right)//left, right
{
	int mid;
	if (left < right)//left==right가 될때까지 반복하는것이다.->left,right가 되면 아무것도 안일어남->2개배열 생각
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
