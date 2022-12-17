#pragma once
#include<DxLib.h>
#include<vector>

const int ScreenW = 1920;
const int ScreenH = 1080;

using namespace std;

/*背景のクラス*/
class BackGround
{
public:
	/// <summary>
	/// BackGroundのコンストラクター
	/// </summary>
	BackGround();

	/// <summary>
	/// BackGroundのデストラクター
	/// </summary>
	~BackGround();

	/// <summary>
	/// BackGround描画処理
	/// </summary>
	void Draw(int scrX,int scrY);

private:
	int bgBack;					//背面レイヤー
	int bgMid;					//中央レイヤー
	int bgFront;				//前面レイヤー
	int drawBgX;				//描画座標X
	int drawBgY;				//描画座標Y
	VECTOR bgPos;				//背景座標
};

