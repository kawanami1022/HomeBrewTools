//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------d
#pragma once
#include <array>
#include <math.h>

#define PI 3.14159265

template<class T>
class Vector2
{
public:
	Vector2();
	Vector2(T x,T y);

	T calcAngle(T x, T y);		// 角度を求める
	T calcSin(T angle);				// y軸のベクトルを求める
	T calcCos(T angle);				// x軸のベクトルを求める
	T calcTwoPtDisComp(T*, T*);		// 2つのポイントの間の距離の合成
	T calcVecX(T dis, T angle);	// 角度からx軸y軸のそれぞれの速度を計算する
	T calcVecY(T dis, T angle);	// 角度からx軸y軸のそれぞれの速度を計算する
	T x, y;								// 座標格納用変数
	Vector2& operator=(const Vector2& vec2);
	Vector2& operator+(const Vector2& vec2);
	Vector2& operator-(const Vector2& vec2);
	Vector2& operator*(const Vector2& vec2);
	Vector2& operator/(const Vector2& vec2);
	Vector2& operator%(const Vector2& vec2);
	Vector2& operator+=(Vector2& vec2);
	Vector2& operator-=(Vector2& vec2);
	bool operator==(Vector2& vec2);
};



template<class T> Vector2<T>::Vector2()
{
	x = 0;
	y = 0;
}

template<class T> Vector2<T>::Vector2(T x, T y)
{
	this->x = x;
	this->y = y;
}

// 目的:デカルト座標系での角度を求める
//入力	:x	x座標
//		:y	y座標
template<class T>T Vector2<T>::calcAngle(T x, T y)
{
	// 0°～90°の時
	if (0 < x && 0 < y)
		return atan(y / x) * 180 / PI;

	// 90°～180°の時  180°～270°の時
	if (x < 0 && 0 < y || x < 0 && y < 0)
		return 180 + atan(y / x) * 180 / PI;
	// 270°～360°の時
	else { return 360 + atan(y / x) * 180 / PI; }
}

//目的	:
//入力	:angle
template<class T>T Vector2<T>::calcSin(T angle)
{
	return sin(angle * (PI / 180));
}

//目的	:
//入力	:angle
template<class T>T Vector2<T>::calcCos(T angle)
{
	return cos(angle * (PI / 180));
}

// 目的	:2点間の距離の合成した距離を求める
//入力	:pointA	
//		:pointB
template<class T>T Vector2<T>::calcTwoPtDisComp(T* pointA, T* pointB)
{
	// 0:x 1:y
	int dissX = pointA[0] + pointB[0];
	int dissY = pointA[1] + pointB[1];
	return sqrtf(dissX * dissX + dissY * dissY);
}

//目的	:x軸の移動量を求める
//入力	:dis		
//		 angle		
template<class T>T Vector2<T>::calcVecX(T dis, T angle)
{
	double vec = dis * calcCos(angle);
	return vec;
}

//目的	:y軸の移動量を求める
//入力	:dis		
//		 angle		
template<class T>T Vector2<T>::calcVecY(T dis, T angle)
{
	double vec = dis * calcSin(angle);
	return vec;
}

template<class T>
Vector2<T>& Vector2<T>::operator=(const Vector2& vec2)
{
	// TODO: return ステートメントをここに挿入します
	x = vec2.x;
	y = vec2.y;
	return (*this);
}

template<class T>
Vector2<T>& Vector2<T>::operator+(const Vector2& vec2)
{
	// TODO: return ステートメントをここに挿入します
	return (vec2.x + this->x, vec2.y + this->y);
}

template<class T>
Vector2<T>& Vector2<T>::operator-(const Vector2& vec2)
{
	// TODO: return ステートメントをここに挿入します
	return (vec2.x - this->x, vec2.y - this->y);
}

template<class T>
Vector2<T>& Vector2<T>::operator*(const Vector2& vec2)
{
	// TODO: return ステートメントをここに挿入します
	return (this->x * vec2.x, this->y * vec2.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator/(const Vector2& vec2)
{
	// TODO: return ステートメントをここに挿入します
	return (this->x / vec2.x, this->y / vec2.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator%(const Vector2& vec2)
{
	// TODO: return ステートメントをここに挿入します
	return (this->x % vec2.x, this->y % vec2.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator+=(Vector2& vec2)
{
	// TODO: return ステートメントをここに挿入します
	this->x += vec2.x;
	this->y += vec2.y;
	return (*this);
}

template<class T>
Vector2<T>& Vector2<T>::operator-=(Vector2& vec2)
{
	// TODO: return ステートメントをここに挿入します
	this->x -= vec2.x;
	this->y -= vec2.y;
	return (*this);
}

template<class T>
inline bool Vector2<T>::operator==(Vector2& vec2)
{
	return ((this->x == vec2.x) && (this->y == vec2.y));
}

using Vector2I = Vector2<int>;
using Vector2L = Vector2<long>;
using Vector2F = Vector2<float>;
using Vector2D = Vector2<double>;
using Vector2Sh = Vector2<short>;