//--------------------------------------------------------------------------------------
// File: SceneManager.h
//
// �V�[�����Ǘ�����N���X
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

	// �V�[���̊��N���X
	class Scene
	{
	private:

		// �V�[���}�l�[�W���[�ւ̃|�C���^
		SceneManager* m_sceneManager;

	public:

		// �V�[���}�l�[�W���[�ݒ�֐�
		void SetSceneManager(SceneManager* sceneManager) { m_sceneManager = sceneManager; }

		// �V�[���̐؂�ւ��֐�
		template <class T>
		void ChangeScene();

		// �f�o�C�X���\�[�X�擾�֐�
		const DX::DeviceResources* GetDeviceResources();

	public:

		// �f�X�g���N�^
		virtual ~Scene() = default;

		// ������
		virtual void Initialize() = 0;

		// �X�V
		virtual void Update(float elapsedTime) = 0;

		// �`��
		virtual void Render() = 0;

		// �I������
		virtual void Finalize() = 0;

	};

	// �V�[���}�l�[�W���[�N���X
	class SceneManager
	{
	private:

		const DX::DeviceResources* m_deviceResources;

		// ���s���̃V�[���ւ̃|�C���^
		Scene* m_scene;

		// �V�[���폜�֐�
		void DeleteScene();

	public:

		// �R���X�g���N�^
		SceneManager(DX::DeviceResources* deviceResorces)
			: m_deviceResources(deviceResorces), m_scene(nullptr)
		{
		};

		// �f�X�g���N�^
		virtual ~SceneManager() { DeleteScene(); };

		// �X�V
		void Update(float elapsedTime);

		// �`��
		void Render();

		// �V�[���̐ݒ�֐�
		template <class T>
		void SetScene();

		// �f�o�C�X���\�[�X�擾�֐�
		const DX::DeviceResources* GetDeviceResources() { return m_deviceResources; }

	};

	// �V�[���̐؂�ւ��֐�
	template <class T>
	void Scene::ChangeScene()
	{
		m_sceneManager->SetScene<T>();
	}

	// �V�[���̐ݒ�֐�
	template <class T>
	void SceneManager::SetScene()
	{
		// �V�[�����폜
		DeleteScene();

		assert(m_scene == nullptr);

		// �V�[���𐶐�
		m_scene = new T();

		// �V�[���ɃV�[���}�l�[�W���[�ւ̃|�C���^��ݒ�
		m_scene->SetSceneManager(this);

		// �V�[���̏���������
		m_scene->Initialize();
	}

}

