#pragma once
#include <Windows.h>
#include <D3D11.h>
#include <d3dx11.h>
#include <d3dCompiler.h>
//�������J���}�N��-----------------------------
#define SAFE_DELETE(p)				{if(p){delete(p);		(p)=nullptr;}	}
#define SAFE_DELETE_ARRAY(p)		{if(p){delete[](p);		(p)=nullptr;}	}
#define SAFE_RELEASE(p)				{if(p){(p)->Release();}}

//2D�|���S���\���Ŏg�p����\����---------------
//���_���C�A�E�g�\���́i���_������������j
struct POINT_LAYOUT
{
	float	pos[3];		//XYZ �F���_
	float	color[4];	//RGBA�F�J���[
	float	uv[2];		//UV  �F�e�N�X�`���ʒu
};

//�R���X�^���g�o�b�t�@�\����
struct POLYGON_BUFFER
{
	float color[4];		//RGBA�F�|���S���J���[
	float pos[4];		//�|���S���̈ʒu���
	float scale[4];		//�g��k����
	float rotation[4];	//��]���
	float texsize[4];	//�\������C���[�W�T�C�Y��HW
};


typedef class CDraw2DPolygon
{
public:
	CDraw2DPolygon() {};
	~CDraw2DPolygon() {};

	//�`��@�\  Draw2�Q
	static void Draw2D(int id, float x, float y) { Draw2D(id, x, y, 1.0f, 1.0f, 0.0f); }
	static void Draw2D(int id, float x, float y, float r) { Draw2D(id, x, y, 1.0f, 1.0f, r); }
	static void Draw2D(int id, float x, float y, float sx, float sy) { Draw2D(id, x, y, sx, sy, 0.0f); }
	static void Draw2D(int id, float x, float y, float sx, float sy, float r);

	static HRESULT InitPolygonRender();
	static void	DeletePolygonRender();

	static void LoadImage(int id, wchar_t*	image_name);


private:
	//GPU�ň����p
	static ID3D11VertexShader*			m_pVertexShader;	//�o�[�e�b�N�X�V�F�[�_
	static ID3D11PixelShader*			m_pPixelShader;		//�s�N�Z���V�F�[�_
	static ID3D11InputLayout*			m_pVertexLayout;	//���_���̓V�F�[�_
	static ID3D11Buffer*				m_pConstantBuffer;	//�R���X�^���g�o�b�t�@	

															//�|���S�����o�^�p�o�b�t�@
	static ID3D11Buffer*				m_pVertexBuffer;	//���_�o�b�t�@
	static ID3D11Buffer*				m_pIndexBuffer;		//�C���f�b�N�X�o�b�t�@

															//�e�N�X�`���ɕK�v�ȕ�
	static ID3D11SamplerState*			m_pSampleLinear;	//�e�N�X�`���T���v��
	static ID3D11ShaderResourceView*	m_pTexture[32];		//�e�N�X�`�����\�[�X
	static float						m_width[32];		//�e�N�X�`���̉���
	static float						m_height[32];		//�e�N�X�`���̏c��

}Draw;