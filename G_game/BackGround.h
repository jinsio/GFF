#pragma once
const int LayerNum = 3;

/*�w�i�̃N���X*/
class BackGround
{
public:
	BackGround();
	~BackGround();
	void Update();
	void Draw();
private:
	int bgHandle[LayerNum];
	int bgX[LayerNum];
	int bgY[LayerNum];
};

