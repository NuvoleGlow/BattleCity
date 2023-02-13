#include "framework.h"
#include "HPCount.h"

HPCount::HPCount()
{
	_quad = make_shared<Quad>(L"Resource/Texture/HP.png", Vector2(32.0f, 32.0f));
}

HPCount::~HPCount()
{
}

void HPCount::Update()
{
	_quad->Update();
}

void HPCount::Render()
{
	_quad->Render();
}
