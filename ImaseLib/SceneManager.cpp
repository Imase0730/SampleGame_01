//--------------------------------------------------------------------------------------
// File: SceneManager.cpp
//
// �V�[�����Ǘ�����N���X
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

// �X�V�֐�
void SceneManager::Update(float elapsedTime)
{
#ifdef ESC_QUIT_ENABLE
	// ESC�L�[�ŏI��
	auto kb = Keyboard::Get().GetState();
	if (kb.Escape) PostQuitMessage(0);
#endif

	// �V�[���̍X�V
	if (m_scene) m_scene->Update(elapsedTime);
}

// �`��֐�
void SceneManager::Render()
{
	// �V�[���̕`��
	if (m_scene) m_scene->Render();
}

// �f�o�C�X���\�[�X�擾�֐�
const DX::DeviceResources* Scene::GetDeviceResources()
{
	assert(m_sceneManager);

	return m_sceneManager->GetDeviceResources();
}

// �V�[���̍폜�֐�
void SceneManager::DeleteScene()
{
	if (m_scene)
	{
		// �V�[���̏I������
		m_scene->Finalize();

		// �V�[���̍폜
		delete m_scene;

		m_scene = nullptr;
	}
}
