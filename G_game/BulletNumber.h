#pragma once
class BulletNumber
{
public:
    BulletNumber();
    ~BulletNumber();
    int GetBulletNumber() { return mBulletNumber; }         //�c�e���̊m�F
    void AddBulletNumber() { mBulletNumber++; }             //�c�e�𑝂₷
    void SubBulletNumber() { mBulletNumber--; }             //�c�e�����炷
private:
    int mBulletNumber;                                      //�c�e��
};

