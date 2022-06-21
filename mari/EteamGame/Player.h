#pragma once

//プレイヤー
class Player
{

public:

	//初期化
	Player();

	//削除
	~Player();

	//残機
	int credit;

	//位置
	float posX;
	float posY;

	//復帰位置
	float returnPosX;
	float returnPosY;

	//位置取得
	float& GetPosX() { return posX; }
	float& GetPosY() { return posY; }

	//一つ前の位置
	float prevPosY;

	//一つ前の位置取得
	float& GetprevPosY() { return prevPosY; }

	//寸法
	float sizeX;
	float sizeY;

	//速度
	float speedX;
	float speedY;

	//更新処理
	void Update();

	//描画処理
	void Draw();

	//画像
	int image;

	//
	int upwardImage;

	int playerImg[12];
	int playerImgReverse[12];
	int NowImgNumber;

	int flameCount;

	int CycleImg;
	int GravityFontImg;
	int MouseImg;
	float CyclePI=0;

	int x, y;


	int gonimage;

	int goffimage;

	float gPosX;

	float gPosY;

	//接触してるかしてないかの判定
	bool fTouching;

	//接触してるかしてないかの判定
	bool fTouching2;
	
	//ミサイルかトゲと接触してるかしてないかの判定
	bool fHiting;

	//クリックしてるかしてないかの判定
	bool fClick;

	//重力が働いてるか働いてないかの判定
	bool fGravity;

	//画面外に出ているか出ていないかの判定
	bool fOut;
	//一つ前の位置取得
	bool& GetfOut() { return fOut; }

	//中間地点を突破しているかどうかの判定
	bool fCheckPoint;

	//ゲームオーバーしてるかしてないかの判定
	bool fGameOver;

	//ゲームクリアしてるかしてないかの判定
	bool fGameClear;

};
extern Player player;
extern float sp;