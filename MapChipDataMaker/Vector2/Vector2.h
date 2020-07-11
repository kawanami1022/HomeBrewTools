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

	T calcAngle(T x, T y);		// �p�x�����߂�
	T calcSin(T angle);				// y���̃x�N�g�������߂�
	T calcCos(T angle);				// x���̃x�N�g�������߂�
	T calcTwoPtDisComp(T*, T*);		// 2�̃|�C���g�̊Ԃ̋����̍���
	T calcVecX(T dis, T angle);	// �p�x����x��y���̂��ꂼ��̑��x���v�Z����
	T calcVecY(T dis, T angle);	// �p�x����x��y���̂��ꂼ��̑��x���v�Z����
	T x, y;								// ���W�i�[�p�ϐ�
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

// �ړI:�f�J���g���W�n�ł̊p�x�����߂�
//����	:x	x���W
//		:y	y���W
template<class T>T Vector2<T>::calcAngle(T x, T y)
{
	// 0���`90���̎�
	if (0 < x && 0 < y)
		return atan(y / x) * 180 / PI;

	// 90���`180���̎�  180���`270���̎�
	if (x < 0 && 0 < y || x < 0 && y < 0)
		return 180 + atan(y / x) * 180 / PI;
	// 270���`360���̎�
	else { return 360 + atan(y / x) * 180 / PI; }
}

//�ړI	:
//����	:angle
template<class T>T Vector2<T>::calcSin(T angle)
{
	return sin(angle * (PI / 180));
}

//�ړI	:
//����	:angle
template<class T>T Vector2<T>::calcCos(T angle)
{
	return cos(angle * (PI / 180));
}

// �ړI	:2�_�Ԃ̋����̍����������������߂�
//����	:pointA	
//		:pointB
template<class T>T Vector2<T>::calcTwoPtDisComp(T* pointA, T* pointB)
{
	// 0:x 1:y
	int dissX = pointA[0] + pointB[0];
	int dissY = pointA[1] + pointB[1];
	return sqrtf(dissX * dissX + dissY * dissY);
}

//�ړI	:x���̈ړ��ʂ����߂�
//����	:dis		
//		 angle		
template<class T>T Vector2<T>::calcVecX(T dis, T angle)
{
	double vec = dis * calcCos(angle);
	return vec;
}

//�ړI	:y���̈ړ��ʂ����߂�
//����	:dis		
//		 angle		
template<class T>T Vector2<T>::calcVecY(T dis, T angle)
{
	double vec = dis * calcSin(angle);
	return vec;
}

template<class T>
Vector2<T>& Vector2<T>::operator=(const Vector2& vec2)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	x = vec2.x;
	y = vec2.y;
	return (*this);
}

template<class T>
Vector2<T>& Vector2<T>::operator+(const Vector2& vec2)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	return (vec2.x + this->x, vec2.y + this->y);
}

template<class T>
Vector2<T>& Vector2<T>::operator-(const Vector2& vec2)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	return (vec2.x - this->x, vec2.y - this->y);
}

template<class T>
Vector2<T>& Vector2<T>::operator*(const Vector2& vec2)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	return (this->x * vec2.x, this->y * vec2.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator/(const Vector2& vec2)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	return (this->x / vec2.x, this->y / vec2.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator%(const Vector2& vec2)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	return (this->x % vec2.x, this->y % vec2.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator+=(Vector2& vec2)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	this->x += vec2.x;
	this->y += vec2.y;
	return (*this);
}

template<class T>
Vector2<T>& Vector2<T>::operator-=(Vector2& vec2)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
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