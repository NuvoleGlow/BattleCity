#pragma once

#define RED		 RGB(255,0,0)
#define GREEN	 RGB(0,255,0)
#define BLUE	 RGB(0,0,255)

#define WIN_WIDTH		512
#define WIN_HEIGHT		480

#define PI				 3.141592

#define DEVICE Device::GetInstance()->GetDevice()
#define DC Device::GetInstance()->GetDeviceContext()

#define KEY_DOWN(k) Keyboard::GetInstance()->Down(k)
#define KEY_UP(k) Keyboard::GetInstance()->Up(k)
#define KEY_PRESS(k) Keyboard::GetInstance()->Press(k)

#define DELTA_TIME Timer::GetInstance()->GetElasedTime()
#define RUN_TIME Timer::GetInstance()->GetRunTime();

#define SAMPLER StateManager::GetInstance()->GetSampler()
#define AlphaBlendState StateManager::GetInstance()->GetAlphaBlend()
#define AdditiveBlendState StateManager::GetInstance()->GetAdditiveBlend()

#define ADD_VS(k) ShaderManager::GetInstance()->AddVS(k)
#define ADD_PS(k) ShaderManager::GetInstance()->AddPS(k)

#define EFFECT EffectManager::GetInstance()

#define CAMERA Camera::GetInstance()

#define SOUND Audio::GetInstance()

#define SCENE SceneManager::GetInstance()

#define MOUSE_POS CAMERA->GetWorldMousePos()

#define LERP(s,e,t) s + (e - s) * t

using Float2 = XMFLOAT2;

using CallBack = std::function<void()>;
