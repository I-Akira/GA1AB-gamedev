#pragma once
//�}�X�^�[�\���̃t�@�C��
//�}�X�^�[�\���̂������ɂԂ�����
//�g����
/*
//XX�\����-------
struct XX
{
	int XXXX;
	char XXXX;
	char XXXX;
};
*/

//�A�C�e���\����
//�A�C�e���̖��O�Ɛ������A�w�����z���Ǘ�
struct sItem
{
	//�A�C�e����
	char Itemname[40];
	//�A�C�e���̐���
	char Itemdesc[256];
	//���z�i�����p���Ĕ��p�l�i���ݒ�B���p�l�i�͍w�����z�̔����j
	unsigned int Mon;
};

//�L�����N�^�[�\����
//�L�����N�^�[���A�U���́A�h��́A�̗͂Ȃǂ̃X�e�[�^�X���Ǘ�
struct sCharStats
{
	//�L�����N�^�[��
	char Charname[256];
	//�L�����̗̑�
	int Hp;
	//�L�����̃X�L���|�C���g
	int Sp;
	//�U����
	int Atk;
	//�h���
	int Def;
	//�X�L����
	int Spp;
};