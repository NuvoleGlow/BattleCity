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

}

void Program::Render()
{
	Device::GetInstance()->Clear();

	SCENE->PreRender();

	AlphaBlendState->SetState();

	SCENE->Render();
	EFFECT->Render();

	SCENE->PostRender();

	Device::GetInstance()->Present();
}
