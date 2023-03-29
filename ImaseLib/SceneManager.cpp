//--------------------------------------------------------------------------------------
// File: SceneManager.cpp
//
// シーンを管理するクラス
//
// Date: 2023.3.25
// Author: Hideyasu Imase
//--------------------------------------------------------------------------------------
#include "../pch.h"
#include "SceneManager.h"

#ifdef ESC_QUIT_ENABLE
#include "Keyboard.h"
#endif

using namespace DirectX;
using namespace Imase;

// 更新関数
void SceneManager::Update(float elapsedTime)
{
#ifdef ESC_QUIT_ENABLE
	// ESCキーで終了
	auto kb = Keyboard::Get().GetState();
	if (kb.Escape) PostQuitMessage(0);
#endif

	// シーンの更新
	if (m_scene) m_scene->Update(elapsedTime);
}

// 描画関数
void SceneManager::Render()
{
	// シーンの描画
	if (m_scene) m_scene->Render();
}

// デバイスリソース取得関数
const DX::DeviceResources* Scene::GetDeviceResources()
{
	assert(m_sceneManager);

	return m_sceneManager->GetDeviceResources();
}

// シーンの削除関数
void SceneManager::DeleteScene()
{
	if (m_scene)
	{
		// シーンの終了処理
		m_scene->Finalize();

		// シーンの削除
		delete m_scene;

		m_scene = nullptr;
	}
}
