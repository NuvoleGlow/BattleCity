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

	wstring fps = L"FPS : " + to_wstring((int)Timer::GetInstance()->GetFPS());
	RECT rect = { 0,0,500,100 };

	DirectWrite::GetInstance()->GetDC()->BeginDraw();
	DirectWrite::GetInstance()->RenderText(fps, rect);

	CAMERA->SetUICameraBuffer();
	SCENE->PostRender();

	DirectWrite::GetInstance()->GetDC()->EndDraw();
	Device::GetInstance()->Present();
}
