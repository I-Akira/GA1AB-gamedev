#pragma once
//マスター構造体ファイル
//マスター構造体をここにぶち込む
//使い方
/*
//XX構造体-------
struct XX
{
	int XXXX;
	char XXXX;
	char XXXX;
};
*/

//アイテム構造体
//アイテムの名前と説明文、購入金額を管理


//キャラクター構造体
//キャラクター名、攻撃力、防御力、体力などのステータスを管理
struct sCharStats
{
	//キャラクター名
	char Charname[256];
	//キャラの体力
	int Hp;
	//キャラのスキルポイント
	int Sp;
	//攻撃力
	int Atk;
	//防御力
	int Def;
	//スキル力
	int Spp;
};