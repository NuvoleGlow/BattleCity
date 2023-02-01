#include "framework.h"
#include "BrickWall.h"

BrickWall::BrickWall()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Brick.png", Vector2(8.0f, 8.0f));
	_collider = make_shared<CircleCollider>(4.0f);
	_collider->GetTransform()->SetParent(_quad->GetTransform());
}

BrickWall::~BrickWall()
{
}

void BrickWall::Update()
{
	if (isActive == false)
		return;

	_quad->Update();
	_collider->Update();
}

void BrickWall::Render()
{
	if (isActive == false)
		return;

	_quad->Render();
	_collider->Render();
}
