#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <vector>
#include "Matrix4x4.h"
#include "Vector3.h"
#include <cmath>
#include "DebugCamera.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	
	// 1, x軸回転行列
	Matrix4x4 MakeRotateXMatrix(float radian);

	// 2, y軸回転行列
	Matrix4x4 MakeRotateYMatrix(float radian);

	// 3, z軸回転行列
	Matrix4x4 MakeRotateZMatrix(float radia);

	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	//３次元アフィン変換行列
	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	//ワールドトランスフォーム
	//WorldTransform worldTransform_;
	//ビュープロジェクション
	ViewProjection viewProjection_;

	//デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	//デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	Model* model_ = nullptr;

	
	
	uint32_t texturehandle_ = 0;


	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
