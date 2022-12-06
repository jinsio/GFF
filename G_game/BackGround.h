#pragma once
#include<DxLib.h>

const int LayerNum = 3;
const int screenNum = 2;

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
	void Draw();

	/// <summary>
	/// 背景座標のセッター
	/// </summary>
	/// <param name="scrPos">スクロール座標</param>
	void SetScrPos(VECTOR& scrPos) { bgPos = scrPos; }

private:
	int bgHandle[LayerNum];		//背景画像ハンドル
	float bgX[LayerNum];		//レイヤーごとの背景座標X
	float bgY[LayerNum];		//レイヤーごとの背景座標Y
	float bgScreenX;
	VECTOR bgPos;				//背景座標

};

