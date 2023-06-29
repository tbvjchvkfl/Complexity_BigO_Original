#include <iostream>

//chrono 헤더는 c++에서 제공하는 시간과 관련된 내용들이 담겨있음.
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

// Time Complexity :4 * n^ ( 4곱하기 n 제곱 )
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



//	정량화
//	Complexity(복잡도)

		//Time Complexity ( 시간 복잡도 )
		//	알고리즘의 시작 ~ 끝 소요 시간
		//	수행 회수 ( 몇번 실행 했냐 / 몇 회 실행했냐 )

		//Space Complexity ( 공간 복잡도 )
		//	알고리즘 도중에 사용되는 메모리를 측정
		//	변수의 개수 ( 변수가 몇개임? )

//	정량화 예시

int sum(int x, int y)
{
	return x + y;
}

//TimeComplexity : 1
//SpaceComplexity : 2


//  아래 경우 count가 n이라 하면,
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

//	TimeComplexity는 Worst case를 기준으로 계산함
//  SpaceComplexity에서 Worst case는 매개변수를 포함하지 않음


//		<이런 기술이 있다!!!>
// 
// 
//			Big O Notation
//				컴퓨터의 성능이나 환경에 영향을 받지 않고, '입력의 개수'에 따라 정량화 측정
//			
//				1. 곱하기
//					변수를 제외한 상수는 무시
//			
//				2. 더하기
//					높은 차수만 고려 ( x: 1차, x^2 : 2차 )
//			
//				3. 숫자
//					1 무조건
//			
//				4. Worst case 계산
//					매개 변수는 Space Complexity에서 제외
//			
//				
//			0(n+3) = 0(n^1 + 3* n^0) = 0(n)
//			0(2) = 0(1)


//점근법 (asymtotic notation) - 점점 가까워진다!!!

// 0(Time Complexity) : O (4*n^2) = O(n^2)
// Space Complexity : O(3) = 0(1)

