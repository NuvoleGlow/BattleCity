#include "framework.h"
#include "Program.h"

Program::Program()
{
	srand(static_cast<UINT>(time(nullptr)));
}

Program::~Program()
{
}

void Program::Update()
{
	if (KEY_DOWN(VK_F1))
	{
		Collider::isDebug = !Collider::isDebug;
	}

	Keyboard::GetInstance()->Update();
	Timer::GetInstance()->Update();

	SCENE->Update();
	EFFECT->Update();

	CAMERA->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	CAMERA->SetProjectionBuffer(WIN_WIDTH, WIN_HEIGHT);
	CAMERA->SetCameraWorldBuffer();

	SCENE->PreRender();

	CAMERA->SetViewPort();

	AlphaBlendState->SetState();

	SCENE->Render();
	EFFECT->Render();

	CAMERA->SetUICameraBuffer();
	SCENE->PostRender();

	Device::GetInstance()->Present();
}
