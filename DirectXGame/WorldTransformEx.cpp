#include "WorldTransformEx.h"


// 1, x軸回転行列
Matrix4x4 WorldTransformEx::MakeRotateXMatrix(float radian) {
	Matrix4x4 ans = {0};

	ans.m[0][0] = 1;
	ans.m[1][1] = std::cos(radian);
	ans.m[1][2] = std::sin(radian);
	ans.m[2][1] = -std::sin(radian);
	ans.m[2][2] = std::cos(radian);
	ans.m[3][3] = 1;

	return ans;
};

// 2, y軸回転行列
Matrix4x4 WorldTransformEx::MakeRotateYMatrix(float radian) {
	Matrix4x4 ans = {0};

	ans.m[0][0] = std::cos(radian);
	ans.m[0][2] = -std::sin(radian);
	ans.m[1][1] = 1;
	ans.m[2][0] = std::sin(radian);
	ans.m[2][2] = std::cos(radian);
	ans.m[3][3] = 1;

	return ans;
};

// 3, z軸回転行列
Matrix4x4 WorldTransformEx::MakeRotateZMatrix(float radian) {
	Matrix4x4 ans = {0};

	ans.m[0][0] = std::cos(radian);
	ans.m[0][1] = std::sin(radian);
	ans.m[1][0] = -std::sin(radian);
	ans.m[1][1] = std::cos(radian);
	ans.m[2][2] = 1;
	ans.m[3][3] = 1;

	return ans;
};

Matrix4x4 WorldTransformEx::Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 ans;
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			ans.m[a][b] = m1.m[a][0] * m2.m[0][b] + m1.m[a][1] * m2.m[1][b] + m1.m[a][2] * m2.m[2][b] + m1.m[a][3] * m2.m[3][b];
		}
	}
	return ans;
};

// ３次元アフィン変換行列
Matrix4x4 WorldTransformEx::MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 S = {0};
	Matrix4x4 R = {0};
	Matrix4x4 rX = {0};
	Matrix4x4 rY = {0};
	Matrix4x4 rZ = {0};
	Matrix4x4 T = {0};
	Matrix4x4 ans = {0};

	S.m[0][0] = scale.x;
	S.m[1][1] = scale.y;
	S.m[2][2] = scale.z;
	S.m[3][3] = 1;

	rX = MakeRotateXMatrix(rotate.x);
	rY = MakeRotateYMatrix(rotate.y);
	rZ = MakeRotateZMatrix(rotate.z);

	R = Multiply(rX, Multiply(rY, rZ));

	T.m[0][0] = 1;
	T.m[1][1] = 1;
	T.m[2][2] = 1;
	T.m[3][3] = 1;
	T.m[3][0] = translate.x;
	T.m[3][1] = translate.y;
	T.m[3][2] = translate.z;

	ans.m[0][0] = S.m[0][0] * R.m[0][0];
	ans.m[0][1] = S.m[0][0] * R.m[0][1];
	ans.m[0][2] = S.m[0][0] * R.m[0][2];
	ans.m[1][0] = S.m[1][1] * R.m[1][0];
	ans.m[1][1] = S.m[1][1] * R.m[1][1];
	ans.m[1][2] = S.m[1][1] * R.m[1][2];
	ans.m[2][0] = S.m[2][2] * R.m[2][0];
	ans.m[2][1] = S.m[2][2] * R.m[2][1];
	ans.m[2][2] = S.m[2][2] * R.m[2][2];
	ans.m[3][0] = T.m[3][0];
	ans.m[3][1] = T.m[3][1];
	ans.m[3][2] = T.m[3][2];
	ans.m[3][3] = 1;

	return ans;
};

void WorldTransformEx::UpdateMatrix() {
	
}
