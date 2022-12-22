//#pragma once
//#include <vector>
//
//
//	// ゲーム内アクター・当たり判定の種類別タグ
//	// 必要なものはBeginとEndの間に254個まで定義できる
//	enum class PlayerObjectTag : unsigned char
//	{
//		Player,
//		Bullet,
//		ShotDummy,
//	};
//
//	//------------------------------------------------------------------------------------
//	// @brief ループ制御用。上記タグの全要素を記述しておくこと.
//	// @detail 使用法として,for( ObjectTag &tag : ObjectTagAll ) とすることで、
//	// 全Tag要素のループにできる
//	//------------------------------------------------------------------------------------
//	constexpr static PlayerObjectTag ObjectTagAll[] =
//	{
//		PlayerObjectTag::Player,
//		PlayerObjectTag::Bullet,
//		PlayerObjectTag::ShotDummy
//	};
