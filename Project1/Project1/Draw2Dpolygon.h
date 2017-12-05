#pragma once
#include <Windows.h>
#include <D3D11.h>
#include <d3dx11.h>
#include <d3dCompiler.h>
//メモリ開放マクロ-----------------------------
#define SAFE_DELETE(p)				{if(p){delete(p);		(p)=nullptr;}	}
#define SAFE_DELETE_ARRAY(p)		{if(p){delete[](p);		(p)=nullptr;}	}
#define SAFE_RELEASE(p)				{if(p){(p)->Release();}}

//2Dポリゴン表示で使用する構造体---------------
//頂点レイアウト構造体（頂点が所持する情報）
struct POINT_LAYOUT
{
	float	pos[3];		//XYZ ：頂点
	float	color[4];	//RGBA：カラー
	float	uv[2];		//UV  ：テクスチャ位置
};

//コンスタントバッファ構造体
struct POLYGON_BUFFER
{
	float color[4];		//RGBA：ポリゴンカラー
	float pos[4];		//ポリゴンの位置情報
	float scale[4];		//拡大縮小率
	float rotation[4];	//回転情報
	float texsize[4];	//表示するイメージサイズのHW
};


typedef class CDraw2DPolygon
{
public:
	CDraw2DPolygon() {};
	~CDraw2DPolygon() {};

	//描画機能  Draw2群
	static void Draw2D(int id, float x, float y) { Draw2D(id, x, y, 1.0f, 1.0f, 0.0f); }
	static void Draw2D(int id, float x, float y, float r) { Draw2D(id, x, y, 1.0f, 1.0f, r); }
	static void Draw2D(int id, float x, float y, float sx, float sy) { Draw2D(id, x, y, sx, sy, 0.0f); }
	static void Draw2D(int id, float x, float y, float sx, float sy, float r);

	static HRESULT InitPolygonRender();
	static void	DeletePolygonRender();

	static void LoadImage(int id, wchar_t*	image_name);


private:
	//GPUで扱う用
	static ID3D11VertexShader*			m_pVertexShader;	//バーテックスシェーダ
	static ID3D11PixelShader*			m_pPixelShader;		//ピクセルシェーダ
	static ID3D11InputLayout*			m_pVertexLayout;	//頂点入力シェーダ
	static ID3D11Buffer*				m_pConstantBuffer;	//コンスタントバッファ	

															//ポリゴン情報登録用バッファ
	static ID3D11Buffer*				m_pVertexBuffer;	//頂点バッファ
	static ID3D11Buffer*				m_pIndexBuffer;		//インデックスバッファ

															//テクスチャに必要な物
	static ID3D11SamplerState*			m_pSampleLinear;	//テクスチャサンプラ
	static ID3D11ShaderResourceView*	m_pTexture[32];		//テクスチャリソース
	static float						m_width[32];		//テクスチャの横幅
	static float						m_height[32];		//テクスチャの縦幅

}Draw;