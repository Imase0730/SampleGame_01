//--------------------------------------------------------------------------------------
// File: SceneManager.h
//
// シーンを管理するクラス
//
// Date: 2023.3.25
// Author: Hideyasu Imase
//--------------------------------------------------------------------------------------
#pragma once

#include "DeviceResources.h"

#define ESC_QUIT_ENABLE

namespace Imase
{
	class SceneManager;

	// シーンの基底クラス
	class Scene
	{
	private:

		// シーンマネージャーへのポインタ
		SceneManager* m_sceneManager;

	public:

		// シーンマネージャー設定関数
		void SetSceneManager(SceneManager* sceneManager) { m_sceneManager = sceneManager; }

		// シーンの切り替え関数
		template <class T>
		void ChangeScene();

		// デバイスリソース取得関数
		const DX::DeviceResources* GetDeviceResources();

	public:

		// デストラクタ
		virtual ~Scene() = default;

		// 初期化
		virtual void Initialize() = 0;

		// 更新
		virtual void Update(float elapsedTime) = 0;

		// 描画
		virtual void Render() = 0;

		// 終了処理
		virtual void Finalize() = 0;

	};

	// シーンマネージャークラス
	class SceneManager
	{
	private:

		const DX::DeviceResources* m_deviceResources;

		// 実行中のシーンへのポインタ
		Scene* m_scene;

		// シーン削除関数
		void DeleteScene();

	public:

		// コンストラクタ
		SceneManager(DX::DeviceResources* deviceResorces)
			: m_deviceResources(deviceResorces), m_scene(nullptr)
		{
		};

		// デストラクタ
		virtual ~SceneManager() { DeleteScene(); };

		// 更新
		void Update(float elapsedTime);

		// 描画
		void Render();

		// シーンの設定関数
		template <class T>
		void SetScene();

		// デバイスリソース取得関数
		const DX::DeviceResources* GetDeviceResources() { return m_deviceResources; }

	};

	// シーンの切り替え関数
	template <class T>
	void Scene::ChangeScene()
	{
		m_sceneManager->SetScene<T>();
	}

	// シーンの設定関数
	template <class T>
	void SceneManager::SetScene()
	{
		// シーンを削除
		DeleteScene();

		assert(m_scene == nullptr);

		// シーンを生成
		m_scene = new T();

		// シーンにシーンマネージャーへのポインタを設定
		m_scene->SetSceneManager(this);

		// シーンの初期化処理
		m_scene->Initialize();
	}

}

