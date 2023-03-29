//--------------------------------------------------------------------------------------
// File: UserResources.h
//
// シーンへ渡すユーザーリソースクラス（サンプル）
//
// Date: 2023.3.25
// Author: Hideyasu Imase
//--------------------------------------------------------------------------------------
#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

// 各シーンに渡す共通リソースを記述してください
class UserResources
{
private:

	// デバイスリソース
	DX::DeviceResources* m_deviceResources;

	// 共通ステート
	DirectX::CommonStates* m_states;

	// ステップタイマー
	DX::StepTimer* m_timer;

	// キーボードステートトラッカー
	DirectX::Keyboard::KeyboardStateTracker* m_tracker;

public:

	// コンストラクタ
	UserResources()
		: m_deviceResources(nullptr), m_states(nullptr), m_timer(nullptr), m_tracker(nullptr)
	{
	}

	// デバイスリソースを設定する関数
	void SetDeviceResources(DX::DeviceResources* deviceResources) { m_deviceResources = deviceResources; }

	// デバイスリソースを取得する関数
	const DX::DeviceResources* GetDeviceResources() { return m_deviceResources; }

	// 共通ステートを設定する関数
	void SetCommonStates(DirectX::CommonStates* states) { m_states = states; }

	// 共通ステートを取得する関数
	const DirectX::CommonStates* GetCommonStates() { return m_states; }

	// ステップタイマーを設定する関数
	void SetStepTimerStates(DX::StepTimer* timer) { m_timer = timer; }

	// ステップタイマーを取得する関数
	const DX::StepTimer* GetStepTimer() { return m_timer; }

	// キーボードステートトラッカーを設定する関数
	void SetKeyboardStateTracker(DirectX::Keyboard::KeyboardStateTracker*  tracker) { m_tracker = tracker; }

	// キーボードステートトラッカーを取得する関数
	const DirectX::Keyboard::KeyboardStateTracker*  GetKeyboardStateTracker() { return m_tracker; }
};

