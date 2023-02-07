#include "framework.h"
#include "HeadQuarter.h"

HeadQuarter::HeadQuarter()
{
	_collider = make_shared<CircleCollider>(16.0f);
	_quad = make_shared<Quad>(L"Resource/Texture/HeadQuarter.png", Vector2(32.0f, 32.0f));
	_quad->GetTransform()->SetParent(_collider->GetTransform());
	_collider->GetTransform()->SetPos(Vector2(240.0f, 48.0f));
}

HeadQuarter::~HeadQuarter()
{
}

void HeadQuarter::Update()
{
	if (isActive == false)
		return;

	_collider->Update();
	_quad->Update();
}

void HeadQuarter::Render()
{
	if (isActive == false)
		return;

	_quad->Render();
}
