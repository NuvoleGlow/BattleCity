#include "framework.h"
#include "Numbers.h"

Numbers::Numbers(float curNumber)
{
	_sprite = make_shared<Sprite>(L"Resource/Texture/UI/Numbers.png", Vector2(16.0f, 16.0f), Vector2(10.0f, 1.0f));
	_curframe = { curNumber, 0.0f };
}

Numbers::~Numbers()
{
}

void Numbers::Update()
{
	_sprite->Update();
}

void Numbers::Render()
{
	_sprite->SetSpriteByFrame(_curframe);
	_sprite->Render();
}

void Numbers::SetNumber(float curNumber)
{
	_curframe = { curNumber, 0.0f };
}
