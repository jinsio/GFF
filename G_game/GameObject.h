#pragma once
#include "Dxlib.h"
#include <math.h>
#include "GameObjectTag.h"

class GameObject
{
public:
public:
    GameObject(GameObjectTag tag);
    virtual ~GameObject();

    VECTOR  GetPos() { return mPos; }
    void    SetPos(VECTOR Pos) { mPos = Pos; }

    bool          GetVisible() const { return mVisible; }                  // ����Ԃ̎擾 
    void          SetVisible(bool visible) { mVisible = visible; }         // ����Ԃ̃Z�b�g

    bool    GetAlive() { return mAlive; }
    void    SetAlive(bool SetAlive) { mAlive = SetAlive; }

    GameObjectTag     GetTag()const { return mTag; }                           // �Q�[���I�u�W�F�N�g�̎�ގ擾

    virtual void Update(float deltaTime) = 0;
    virtual void Draw(int offSetX, int offSetY);

protected:
    GameObjectTag   mTag;
    VECTOR  mPos;
    bool    mAlive;
    bool    mVisible;                                    // �����
    bool    mRightDir;
    int     mHandle;

};

