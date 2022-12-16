#pragma once
#include<DxLib.h>
#include<vector>

const int LayerNum = 3;
const int screenNum = 2;

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
	/// BackGound更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// BackGround描画処理
	/// </summary>
	void Draw(int scrX,int scrY);

private:
	int bgBack;
	int bgMid;
	int bgFront;
	VECTOR bgPos;				//背景座標
};

