#include "Item.h"
#define ITEM_SET_MAX (20)

//�A�C�e���̊Ǘ�������N���X
//�����ŃA�C�e���̊Ǘ�������B

void Item::ItemCreate()
{
	sItem Mat[ITEM_SET_MAX];
	//�A�C�e���쐬�֐�
	//�A�C�e���l�[���Z�b�g�ϐ�(�A�C�e��������ꍇ���ITEM_SET_MAX��ύX����̂�Y��Ȃ�)
	char* SetItemName[ITEM_SET_MAX][ITEM_NAME_MAX] = 
	{"�f�o�b�O�A�C�e���P","�f�o�b�O�A�C�e���Q","�f�o�b�O�A�C�e���R"};
	//�A�C�e�������Z�b�g�ϐ�
	char* SetItemDesc[ITEM_SET_MAX][ITEM_DESC_MAX] = 
	{ "�f�o�b�O�p�P","�f�o�b�O�p�Q","�f�o�b�O�p�R" };
	//�A�C�e�����i�Z�b�g�ϐ�
	int SetMon[ITEM_SET_MAX] = { 114,514,1919 };

	/*for (int i = 0; i < ITEM_SET_MAX; i++)
	{
		//�A�C�e���l�[���Z�b�g
		for (int j = 0; j < ITEM_NAME_MAX; j++)
		{
			if (SetItemName[i][j] != '\0')//�������󔒂łȂ����肢���B�󔒂������ꍇ����
				Mat[i].SetItemName[j](i,SetItemName[i][j]);
		}
		//�A�C�e�������Z�b�g
		for (int j = 0; j < ITEM_DESC_MAX; j++)
		{
			//�������󔒂łȂ����肢���B�󔒂������ꍇ����
			if(SetItemDesc[i][j]!='\0')
				Mat[i].SetItemDesc(i,SetItemDesc[i][j]);
		}

		//�A�C�e�����i�Z�b�g
		Mat[i].SetItemMon( SetMon[i]);
	}*///�G���[�f���Ă�̂ł���������u�B�x�[�^�łŎ��������悤




}


//����h��̃A�C�e�������֐�
void Item::EquipCreate()
{
	EquipItem eItem[256];//���푕���̍\���̊Ǘ�
	//eItem[1] = {2,1,0 };//�\���̃G���[�ŏ���������
	
}