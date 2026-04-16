#pragma once
#include <cmath>
#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2
{
	// 배열 형태에서 접근할 수 있도록 union 사용
	union {
		struct { float x, y; };
		float m[2];
	};

	// 생성자 : 참고-struct생성자 Tstoty블로그
	Vector2() { x = 0.0f; y = 0.0f; }
	Vector2(float _x, float _y) : x(_x), y(_y) {}

	// 상수 벡터
	static const Vector2 Zero;
	static const Vector2 UnitX;
	static const Vector2 UnitY;

	// 연산자 오버로딩 벡터 덧셈 및 뺄셈, 복합 대입 연산자
	Vector2 operator+(const Vector2& v) const {
		return Vector2(x + v.x, y + v.y);
	}
	Vector2& operator+=(const Vector2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	Vector2 operator-(const Vector2& v) const {
		return Vector2(x - v.x, y - v.y);
	}
	Vector2& operator-=(const Vector2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	// 스칼라곱
	Vector2 operator*(float s) const {
		return Vector2(x * s, y * s);
	}

	// 스칼라곱 양방향 - 해당 내용은 AI 도움: 맨 아래

	// 내적
	float operator*(const Vector2& v) const {
		return x * v.x + y * v.y;
	}

	// 외적
	float operator^(const Vector2& v) const {
		return (x * v.y) - (y * v.x);
	}

	// 캐스팅 : 참고-AI 설명, float* 타입으로 변환시에 배열 첫버내 주소(m) 반환
	operator float* () { return m; }
	operator const float* () const { return m; }

	// 함수

	// 벡터의 길이
	float Length() const {
		return std::sqrt(x * x + y * y);
	}

	// 정규화 - 단위 벡터
	Vector2 Normalize() {
		float len = Length();
		// 0으로 나뉘는 걸 방지
		if (len > 0.0f) {
			x /= len;
			y /= len;
		}
		return *this;
	}

	// 내적
	float Dot(const Vector2& v) const {
		return x * v.x + y * v.y;
	}

	// 두 벡터 사이의 각도 : AI 도움
	float Angle(const Vector2& v) const {
		float dot = Dot(v);
		float len = Length() * v.Length();
		if (len == 0.0f) {
			return 0.0f;
		}

		// AI : acos입력단위 벗어나지 않도록 클램핑
		float cosTheta = dot / len;
		if (cosTheta > 1.0f) {
			cosTheta = 1.0f;
		}
		if (cosTheta < -1.0f) {
			cosTheta = -1.0f;
		}

		// 결과값 : 라디안
		return std::acos(cosTheta);
	}

};

// AI 도움 : 스칼라곱 양방향. 숫자가 객체 앞에 오는 경우,
// 피연산자를 기준으로 함수를 찾으나, float 기본 자료형 내부에는 vector2를 인자로 받는
// 곱셈 함수가 존재하지 않으므로 전역 범위의 연산자 함수를 만들어 컴파일러가 이를 찾도록 해야함
inline Vector2 operator*(float s, const Vector2& v) {
	// 이미 구현된 vec * s 를 호출
	return v * s;
}

#endif // !VECTOR2_H
