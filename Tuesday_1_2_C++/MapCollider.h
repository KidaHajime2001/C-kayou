#pragma once
#pragma once
#include"DxLib.h"
#include"CollisionTag.h"
#include"Actor.h"
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//�����̃|�C���^�[�������o�[�ɂ���
class MapCollider
{
public:

	const int MapChipSize = 32;
	const int FullScreenSizeWidth = 1920;
	const int FullScreenSizeHeight = 1080;
	int lineNum = 0;
	int columnNum =0;
	unordered_map<int, vector<int>> mMapData;
	

	//�c�Ɖ��̕�
	struct MapChipData
	{
		int posX;
		int posY;
		CollisionTag tag;
		int MapChipImg;
	};

	MapCollider();
	~MapCollider();
	bool Cheak();
	void Update();

	//Csv�t�@�C���̏c���擾
	void ReadFileStageSize(string fileName);
	void SetStageData(string fileName);

};

