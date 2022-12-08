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
	void Draw();

	/// <summary>
	/// 背景座標のセッター
	/// </summary>
	/// <param name="scrPos">スクロール座標</param>
	void SetScrPos(VECTOR& scrPos) { bgPos = scrPos; }

private:
	struct Bg {
		int bgHandle[LayerNum] = { -1,-1,-1 };		//背景画像ハンドル
		float bgX[LayerNum] = {};			//レイヤーごとの背景座標X
		float bgY[LayerNum] = {};			//レイヤーごとの背景座標Y
		int screenPos[LayerNum] = {};	//スクリーン座標

	};
	Bg first;
	Bg second;

	float bgScreenX;
	VECTOR bgPos;				//背景座標
};

