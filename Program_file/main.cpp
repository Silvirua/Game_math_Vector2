// 기본 include
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 사용자 지정 헤더파일 include
#include "Vector2.h"

// 사용자 지정 함수.
void FixedTest(void);
float frand(float min, float max);
void RandomTest(void);

// 고정값 테스트 함수
void FixedTest(void) {

	// 테스트 함수 호출 시 출력되는 문구
	printf("====== FIXED TEST ======\n");

	// 사용자 지정 헤더파일로 include 한 Vector2 호출
	Vector2 V1(3.0f, 4.0f);
	Vector2 V2(1.0f, 2.0f);
	float s = 2.0f;

	// Vector2 가 제대로 정의가 되었는지 출력
	printf("V1: %.3f %.3f\n", V1.x, V1.y);
	printf("V2: %.3f %.3f\n", V2.x, V2.y);
	printf("s: %.3f\n", s);

	// Vector2 add , sub 이름으로 연산한 값을 저장
	Vector2 add = V1 + V2;
	Vector2 sub = V1 - V2;

	// Vector2 와 스칼라의 곱
	Vector2 vs = V1 * s;
	Vector2 sv = s * V1;

	// Vector2 끼리의 dot, cross 연산
	float dot = V1 * V2;
	float cross = V1 ^ V2;

	// add, sub 연산한 값을 출력, 제대로 연산이 되었다면 옆의 expected 값과 동일할 것
	printf("ADD: %.3f %.3f (expected: 4.000 6.000)\n", add.x, add.y);
	printf("SUB: %.3f %.3f (expected: 2.000 2.000)\n", sub.x, sub.y);

	// 벡터와 스칼라 곱의 값을 출력, 제대로 연산이 되었다면 옆의 expected 값과 동일할 것
	printf("V*s: %.3f %.3f (expected: 6.000 8.000)\n", vs.x, vs.y);
	printf("s*V: %.3f %.3f (expected: 6.000 8.000)\n", sv.x, sv.y);

	// dot, cross 값을 출력, 제대로 연산이 되었다면 옆의 expected 값과 동일할 것
	printf("DOT: %.3f (expected: 11.000)\n", dot);
	printf("CROSS: %.3f (expected: 2.000)\n", cross);

	printf("LEN_V1: %.3f (expected: 5.000)\n", V1.Length());

	Vector2 n = V1.Normalize();
	printf("NORM_V1: %.3f %.3f (expected: 0.600 0.800)\n", n.x, n.y);

	printf("----------------------------------------------------------------\n");
	printf("ZERO: %.3f %.3f\n", Vector2::Zero.x, Vector2::Zero.y);
	printf("UNITX: %.3f %.3f\n", Vector2::UnitX.x, Vector2::UnitX.y);
	printf("UNITY: %.3f %.3f\n", Vector2::UnitY.x, Vector2::UnitY.y);

	printf("\n\n");
}

float frand(float min, float max) {
	return min + (float)rand() / RAND_MAX * (max - min);
}

// 랜덤 테스트 함수
void RandomTest(void) {
	printf("====== RANDOM TEST ======\n");

	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; ++i) {
		Vector2 V1(frand(-10, 10), frand(-10, 10));
		Vector2 V2(frand(-10, 10), frand(-10, 10));
		float s = frand(-5, 5);

		printf("V1: %.3f %.3f\n", V1.x, V1.y);
		printf("V2: %.3f %.3f\n", V2.x, V2.y);
		printf("s: %.3f\n", s);

		printf("DOT: %.3f\n", V1 * V2);
		printf("CROSS: %.3f\n", V1 ^ V2);

		printf("--------------------------\n");
	}
}


int main(void) {
	FixedTest();
	RandomTest();
	return 0;
}
