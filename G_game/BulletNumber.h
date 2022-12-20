#pragma once
class BulletNumber
{
public:
    BulletNumber();
    ~BulletNumber();
    int GetBulletNumber() { return mBulletNumber; }         //c’e”‚ÌŠm”F
    void AddBulletNumber() { mBulletNumber++; }             //c’e‚ğ‘‚â‚·
    void SubBulletNumber() { mBulletNumber--; }             //c’e‚ğŒ¸‚ç‚·
private:
    int mBulletNumber;                                      //c’e”
};

