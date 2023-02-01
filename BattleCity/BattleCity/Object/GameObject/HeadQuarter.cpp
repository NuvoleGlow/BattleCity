#include "framework.h"
#include "HeadQuarter.h"

HeadQuarter::HeadQuarter()
{
	_quad = make_shared<Quad>(L"Resource/Texture/HeadQuarter.png", Vector2(32.0f, 32.0f));
	_collider = make_shared<CircleCollider>(16.0f);
	_collider->GetTransform()->SetParent(_quad->GetTransform());
	_quad->GetTransform()->SetPos(Vector2(240.0f, 48.0f));
}

HeadQuarter::~HeadQuarter()
{
}

void HeadQuarter::Update()
{
	if (isActive == false)
		return;

	_quad->Update();
	_collider->Update();
}

void HeadQuarter::Render()
{
	if (isActive == false)
		return;

	_quad->Render();
	_collider->Render();
}
