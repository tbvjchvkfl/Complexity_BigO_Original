#include <iostream>

//chrono ����� c++���� �����ϴ� �ð��� ���õ� ������� �������.
#include <chrono>

using namespace std;
using Comparison = bool(*)(int, int);

bool Asscending(int x, int y)
{
	return x > y;
}

bool Descending(int x, int y)
{
	return x < y;
}

void sort(int numbers[], int count, Comparison f)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

// Time Complexity :4 * n^ ( 4���ϱ� n ���� )
// Space Complexity : 3
int main()
{
	const int ARRAY_COUNT{ 10 };
	int scores[ARRAY_COUNT]{ 20, 10, 40, 15, 30, 70, 90, 80, 50 };



	auto startTime = chrono::system_clock::now();
	sort(scores, ARRAY_COUNT, Asscending);
	auto endTime = chrono::system_clock::now();


	auto duration = endTime - startTime;

	cout << "sort() runs :" << duration.count() << "ms" << endl;
}



//	����ȭ
//	Complexity(���⵵)

		//Time Complexity ( �ð� ���⵵ )
		//	�˰����� ���� ~ �� �ҿ� �ð�
		//	���� ȸ�� ( ��� ���� �߳� / �� ȸ �����߳� )

		//Space Complexity ( ���� ���⵵ )
		//	�˰��� ���߿� ���Ǵ� �޸𸮸� ����
		//	������ ���� ( ������ ���? )

//	����ȭ ����

int sum(int x, int y)
{
	return x + y;
}

//TimeComplexity : 1
//SpaceComplexity : 2


//  �Ʒ� ��� count�� n�̶� �ϸ�,
//	TimeComplexity : 1+ 1+ n + 1 = n + 3
//	SpaceComplexity : n + 1 + 1 + 1 = n + 3
int sum(int scores[], int count)
{
	int total{};

	for (int i = 0; i < count; i++)
	{
		total += scores[i];
	}

	return total;
}

//	TimeComplexity�� Worst case�� �������� �����
//  SpaceComplexity���� Worst case�� �Ű������� �������� ����


//		<�̷� ����� �ִ�!!!>
// 
// 
//			Big O Notation
//				��ǻ���� �����̳� ȯ�濡 ������ ���� �ʰ�, '�Է��� ����'�� ���� ����ȭ ����
//			
//				1. ���ϱ�
//					������ ������ ����� ����
//			
//				2. ���ϱ�
//					���� ������ ��� ( x: 1��, x^2 : 2�� )
//			
//				3. ����
//					1 ������
//			
//				4. Worst case ���
//					�Ű� ������ Space Complexity���� ����
//			
//				
//			0(n+3) = 0(n^1 + 3* n^0) = 0(n)
//			0(2) = 0(1)


//���ٹ� (asymtotic notation) - ���� ���������!!!

// 0(Time Complexity) : O (4*n^2) = O(n^2)
// Space Complexity : O(3) = 0(1)

