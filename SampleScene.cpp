//--------------------------------------------------------------------------------------
// File: SampleScene.cpp
//
// シーンの雛型に使用してください
//
// Date: 2023.3.25
// Author: Hideyasu Imase
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "SampleScene.h"
#include "ImaseLib/DebugFont.h"

using namespace DirectX;

// 初期化
void SampleScene::Initialize()
{
	CreateDeviceDependentResources();
	CreateWindowSizeDependentResources();

}

// 更新
void SampleScene::Update(float elapsedTime)
{
	UNREFERENCED_PARAMETER(elapsedTime);

	UserResources* userResources = GetUserResources();
	Imase::DebugFont* font = userResources->GetDebugFont();
	font->AddString(L"SampleScene", SimpleMath::Vector2(0.0f, font->GetFontHeight()), Colors::Yellow);
}

// 描画
void SampleScene::Render()
{
}

// 終了処理
void SampleScene::Finalize()
{
}

// デバイスに依存するリソースを作成する関数
void SampleScene::CreateDeviceDependentResources()
{
}

// ウインドウサイズに依存するリソースを作成する関数
void SampleScene::CreateWindowSizeDependentResources()
{
}

// デバイスロストした時に呼び出される関数
void SampleScene::OnDeviceLost()
{
}
