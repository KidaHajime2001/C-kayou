#include "MapCollider.h"
MapCollider::MapCollider()
{
}

MapCollider::~MapCollider()
{
}

bool MapCollider::Cheak()
{
	return false;
}

void MapCollider::Update()
{
}

void MapCollider::ReadFileStageSize(string fileName)
{
	int characterPack;		//CSVのセルの中の文字を格納する変数
	char buffer[10];		//文字列変数
	int num;				//タイルの番号
	bool eofFlag = false;	//eof（end of file）検出フラグ

	FILE* filePointer;						//ファイルのポインタを宣言

	fopen_s(&filePointer,fileName.c_str(), "r");	//fopen_s関数でmap.csvを読み取り形式で開く
	if (filePointer == NULL)				//filePointerが空の場合は
	{
		DebugBreak();						//デバッグ中止
	}

	memset(buffer, 0, sizeof(buffer));		//memset関数でメモリにbufferをセットし、sizeof演算子で要素数を決める

	int maxWidth = 0;

	while (1)
	{
		while (1)
		{
			characterPack = fgetc(filePointer);										//fgetc関数でfilepointerから文字を読んでcharacterPackに格納
			if (characterPack == EOF)
			{
				eofFlag = true;														//EndOfFileを検出して
				break;																//ループを抜ける
			}
			if (characterPack != ',' && characterPack != '\n')						//区切りか改行でなければ
			{
				strcat_s(buffer, (const char*)&characterPack);						//strcat_s関数でbufferに連結し、const char関数で書き換える
			}
			else
			{

				memset(buffer, 0, sizeof(buffer));									//bufferをリセット
				break;																//区切りか改行なのでループを抜ける
			}
		}
		if (eofFlag)																//1マップ分になったら
		{
			break;																	//ループを抜ける
		}
		if (characterPack == ',')													//区切りを検出したら
		{
			lineNum++;															//列の数を増やす
		}
		if (characterPack == '\n')													//改行だったら
		{
			columnNum++;															//行を増やす
			if (maxWidth < lineNum)maxWidth = lineNum;
			lineNum = 0;															//列を0にする
		}
	}
	lineNum = maxWidth++;
	fclose(filePointer);
}
void MapCollider::SetStageData(string fileName)
{
	int characterPack;		//文字を格納する変数
	char buffer[10];		//文字列変数
	int num;				//タイルの番号
	bool eofFlag = false;	//eof（end of file）検出フラグ

	int width = 0;
	int height = 0;

	FILE* filePointer;						//ファイルのポインタを宣言
	fopen_s(&filePointer, fileName.c_str(), "r");	//fopen_s関数でmap.csvを読み取り形式で開く
	if (filePointer == NULL)				//filePointerが空の場合は
	{
		DebugBreak();						//デバッグ中止
	}

	memset(buffer, 0, sizeof(buffer));		//memset関数でメモリにbufferをセットし、sizeof演算子で要素数を決める

	while (1)
	{
		while (1)
		{
			characterPack = fgetc(filePointer);										//fgetc関数でfilepointerから文字を読んでcharacterPackに格納
			if (characterPack == EOF)
			{
				eofFlag = true;														//EndOfFileを検出して
				break;																//ループを抜ける
			}
			if (characterPack != ',' && characterPack != '\n')						//区切りか改行でなければ
			{
				strcat_s(buffer, (const char*)&characterPack);						//strcat_s関数でbufferに連結し、const char関数で書き換える
			}
			else
			{
				num = atoi(buffer);													//atoi関数でbufferをint型に直して、ローカル変数numに代入
				mMapData[height].push_back(num);										//num番目のチップ画像のハンドルを取得
				memset(buffer, 0, sizeof(buffer));									//bufferをリセット
				break;																//区切りか改行なのでループを抜ける
			}
		}
		if (eofFlag)																//1マップ分になったら
		{
			break;																	//ループを抜ける
		}

		if (characterPack == ',')													//区切りを検出したら
		{
			width++;															//列の数を増やす
		}
		if (characterPack == '\n')													//改行だったら
		{
			height++;
			width = 0;															//列を0にする
		}
	}
	fclose(filePointer);
}