#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <list>

namespace fileControl
{
	//�ړI	:�ʒu�s���Ƃɕ������ǂݍ���
	//����	:int lineSize				�s��	
	//		:std::string* lineString	1�s���̕�����
	//		:std::string FileName		�t�@�C����
	int GetLineString(int lineSize, std::string* lineString, std::string FileName);


	//�ړI	:�}�b�v�f�[�^����������
	bool GenerateMapData(int x, int y, int * mapData, std::string FileName);

	//�ړI	:string�̕������txt�t�@�C���ɕۑ�����
	bool WriteString(std::string FileName, std::list<std::string> lineString);


	//�ړI	:x��y�����ꂼ��̃`�b�v�������߂�
	//����	:T *x
	//		:T *y
	//		:FileName
	template<typename T>
	int GetMapSizeForTxt(T* x, T* y, std::string FileName, char countChar);

	//�ړI	:x��y�����ꂼ��̃`�b�v�������߂�
	//����	:T x
	//		:T y
	//		:T *mapChipData
	//		:FileName
	template<typename T>
	int LoadMapDataForTxt(T size_x, T size_y, T* mapChipData, std::string FileName, char checkChar);

}

#include "detail/FileControl.h"