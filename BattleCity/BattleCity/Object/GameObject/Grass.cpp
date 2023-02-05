#include "framework.h"
#include "Grass.h"

Grass::Grass()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Grass.png", Vector2(16.0f, 16.0f));
}

Grass::~Grass()
{
}

void Grass::Update()
{
	_quad->Update();
}

void Grass::Render()
{
	_quad->Render();
}
