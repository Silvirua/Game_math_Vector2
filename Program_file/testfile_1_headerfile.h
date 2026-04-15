#pragma once

// Vector2 구현
// 기본벡터 ( 상수 벡터 정의 , Zero, UnitX, UnitY )
// -> 생성자
// 연산자 오버로딩 ( 벡터 덧셈, 뺄셈, 스칼라곱(양방향)
// 내적
// 외적
// 함수 -> Length(), Normalize(), Dot(), Angle()(두 벡터 사이의 각도)
// 캐스팅 operator float*() , operatro const float*()

struct Vector2
{
	float x, y;
	
	static const Vector2 Zero;     // (0, 0)
	static const Vector2 UnitX;    // (1, 0)
	static const Vector2 UnitY;    // (0, 1)
};

class Vector2 {
public:
	// 오버로드 함수
	// 덧셈 뺄셈
	Vector2 operator+=(Vector2& v)const;
	Vector2 operator-=(Vector2& v)const;
	// 벡터의 스칼라곱 양방향
	Vector2 operator*(Vector2& v, float s)const;
	Vector2 operator*(float s, Vector2& v)const;
	// 내적 및 외적
	float operator*(const Vector2& v) const;
	float operator^(const Vector2& v) const;
};

Length();

Normalize();

Dot();

Angle();
