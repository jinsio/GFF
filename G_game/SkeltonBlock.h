//インクルード
#pragma once
#include <vector>
#include <math.h>
#include "Player.h"
#include"PlayerObject.h"
#include"PlayerObjectManager.h"
#include "Bullet.h"

//1番目のブロック
const int FIRST_POSITION_X = 1440;
const int FIRST_POSITION_Y = 640;

//2番目のブロック
const int SECOND_POSITION_X = 3040;
const int SECOND_POSITION_Y = 640;

//3番目のブロック
const int THIRD_POSITION_X = 4120;
const int THIRD_POSITION_Y = 560;

//4番目のブロック
const int FOURTH_POSITION_X = 4360;
const int FOURTH_POSITION_Y = 1280;

//5番目のブロック
const int FIFTH_POSITION_X = 4680;
const int FIFTH_POSITION_Y = 1200;

//6番目のブロック
const int SIXTH_POSITION_X = 5040;
const int SIXTH_POSITION_Y = 1160;

const int BLOCK_WIDTH = 160;                  //当たり判定の幅
const int BLOCK_HEIGHT = 80;                 //当たり判定の高さ

/*const int SECOND_POSITION_X;
const int SECOND_POSITION_Y;*/

class SkeltonBlock {

public:
	SkeltonBlock();
	~SkeltonBlock() { ; }

	/// <summary>
	/// 当たり判定
	/// </summary>
	//判定チェック
	void CheckPlayerHit(Player* player);
	void CheckBulletHit(Bullet* bullet);

	//各ブロック処理(プレイヤーと弾)
	//1番目
	bool PlayerFirstColBox(VECTOR& objPos);
	bool BulletFirstColBox(VECTOR& objPos);
	//2番目
	bool PlayerSecondColBox(VECTOR& objPos);
	bool BulletSecondColBox(VECTOR& objPos);
	//3番目
	bool PlayerThirdColBox(VECTOR& objPos);
	bool BulletThirdColBox(VECTOR& objPos);
	//4番目
	bool PlayerFourthColBox(VECTOR& objPos);
	bool BulletFourthColBox(VECTOR& objPos);
	//5番目
	bool PlayerFifthColBox(VECTOR& objPos);
	bool BulletFifthColBox(VECTOR& objPos);
	//6番目
	bool PlayerSixthColBox(VECTOR& objPos);
	bool BulletSixthColBox(VECTOR& objPos);

	//描画
	void Draw(int scrX, int scrY);

private:
	//1番目のブロック
	int FirstFalseImg;
	int FirstTrueImg;
	int FirstX;
	int FirstY;
	bool FirstVisibleFlag = false;
	//2番目のブロック
	int SecondFalseImg;
	int SecondTrueImg;
	int SecondX;
	int SecondY;
	bool SecondVisibleFlag = false;
	//3番目のブロック
	int ThirdFalseImg;
	int ThirdTrueImg;
	int ThirdX;
	int ThirdY;
	bool ThirdVisibleFlag = false;
	//4番目のブロック
	int FourthFalseImg;
	int FourthTrueImg;
	int FourthX;
	int FourthY;
	bool FourthVisibleFlag = false;
	//5番目のブロック
	int FifthFalseImg;
	int FifthTrueImg;
	int FifthX;
	int FifthY;
	bool FifthVisibleFlag = false;
	//5番目のブロック
	int SixthFalseImg;
	int SixthTrueImg;
	int SixthX;
	int SixthY;
	bool SixthVisibleFlag = false;



	//高さ・幅
	int W;
	int H;

	//スクロール差分
	int offSetX;
	int offSetY;

	class  Scroll;
};

