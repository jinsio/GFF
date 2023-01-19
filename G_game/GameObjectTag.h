#pragma once
#include <vector>

// �Q�[�����A�N�^�[�E�����蔻��̎�ޕʃ^�O
// �K�v�Ȃ��̂�Begin��End�̊Ԃ�254�܂Œ�`�ł���
enum class GameObjectTag : unsigned char
{
    Player,
    Bullet,
    ShotDummy,
    Enemy,
    Map,
};

//------------------------------------------------------------------------------------
// @brief ���[�v����p�B��L�^�O�̑S�v�f���L�q���Ă�������.
// @detail �g�p�@�Ƃ���,for( ObjectTag &tag : ObjectTagAll ) �Ƃ��邱�ƂŁA
// �STag�v�f�̃��[�v�ɂł���
//------------------------------------------------------------------------------------
constexpr static GameObjectTag ObjectTagAll[] =
{
    GameObjectTag::Player,
    GameObjectTag::Bullet,
    GameObjectTag::ShotDummy,
    GameObjectTag::Enemy,
    GameObjectTag::Map,
};