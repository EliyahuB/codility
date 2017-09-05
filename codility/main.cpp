#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;

int binaryGap(int N)
{
	bool start = false;
	int max = 0;
	int tempMax = 0;
	bool one;
	while (N > 0)
	{
		one = N & 1;
		if (one)
		{
			if (!start)
			{
				start = true;
			}
			else
			{
				//start = false;
				if (tempMax > max)
				{
					max = tempMax;
				}
				tempMax = 0;
			}
		}
		else  //zero
		{
			if (start)
			{
				tempMax++;
			}
		}
		N = N >> 1;
	}
	return max;
}

int OddOccurrencesInArray(vector<int> &A)
{
	int ans = 0;
	for (int i = 0; i < A.size(); i++)
	{
		ans ^= A[i];
	}
	return ans;
}

vector<int> CyclicRotation(vector<int> &A, int K) {
	if (A.size() == 0)
	{
		return A;
	}
	int rounds = K % A.size();
	int index = 0;
	int temp, temp2;
	int nextIndex;
	temp = A[index];

	for (int i = 0; i < A.size(); i++)
	{
		int nextIndex = (index + rounds) % A.size();
		temp2 = A[nextIndex];
		A[nextIndex] = temp;
		temp = temp2;
		index = nextIndex;
	}
	return A;
}


int PermMissingElem(vector<int> &A)
{
	int size = A.size() + 1;
	int sum = size*(size+1)/2;
	int temp = 0;
	for (int i = 0; i < A.size(); i++)
	{
		temp += A[i];
	}
	return sum - temp;
}

int solution(int X, int Y, int D)
{
	int ans = (Y - X) / D;
	if ((Y - X) % D)
		ans++;
	return ans;
}

int TapeEquilibrium(vector<int> &A)
{
	int sum = 0;
	int diff = 2000;
	for (int i = 0; i < A.size(); i++)
	{
		sum += A[i];
	}
	int part1 = 0;
	int part2 = sum;
	for (int i = 0; i < A.size(); i++)
	{
		if (abs(part1 - part2) < diff)
			diff = abs(part1 - part2);
		part1 += A[i];
		part2 -= A[i];
	}
	return diff;	

}

int MissingInteger(vector<int> &A)
{
	vector<bool> temp(1000000);
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i]  > 0)
		{
			temp[A[i]] = true;
		}
	}
	for (int i = 1; i < temp.size(); i++)
	{
		if (!temp[i])
			return i;
	}
	return 0;
}

int PermCheck(vector<int> &A)
{
	vector<bool> temp(100000);
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i]  > 100000)
		{
			return 0;
		}
		else
		{
			temp[A[i]] = true;
		}
	}
	if (A.size() == 1 && A[0] == 1)
		return 1;
	for (int i = 1; i <= A.size(); i++)
	{
		if (!temp[i])
			return 0;
	}
	return 1;
}

int FrogRiverOne(int X, vector<int> &A)
{
	int sum = X*(1 + X) / 2;
	int count = 0;
	vector<bool> temp(100000);
	for (int i = 0; i < A.size(); i++)
	{
		if (!temp[A[i]])
		{
			temp[A[i]] = true;
			count += A[i];
			if (count == sum)
				return i;
		}
	}
	return -1;
}

void main()
{
	//int N;
	//cout << "please enter number\n";
	//cin >> N;
	//if (N < 0)
	//{
	//	cout << "error, negative number\n";
	//	return;
	//}
	//cout << binaryGap(N);
	//vector<int> arr = { 1,3,5,3,1,6,8,5,6,5,8 };
	//cout << OddOccurrencesInArray(arr);
	//vector<int> arr= { 1,2,3,4,5 };
	//vector<int> arr2 = CyclicRotation(arr, 11);
	//for (int i = 0; i <arr2.size(); i++)
	//{
	//	cout << arr2[i] << "\n";
	//}
	//vector<int> arr= { 1,2,4,5 };
	//cout << PermMissingElem(arr);

	//vector<int> arr = { 3,1,2,4,3 };
	//cout << TapeEquilibrium(arr);

	//vector<int> arr = { 2,4,3,5,1,6,8 ,7};
	//cout << MissingInteger(arr);

	//vector<int> arr = { 2,4,3,1,6,8 ,7 ,5};
	//cout << PermCheck(arr);
	//vector<int> arr = { 1,3,1,4,2,3,5,4};
	//cout << FrogRiverOne(5,arr);
	//branch1
	system("pause");
}