#include "framework.h"

#include "Bullet.h"

#include "Brick.h"

Brick::Brick()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Brick.png", Vector2(16.0f, 16.0f));
	_collider = make_shared<CircleCollider>(8.0f);
	_collider->GetTransform()->SetParent(_quad->GetTransform());
}

Brick::~Brick()
{
}

void Brick::Update()
{
	if (isActive == false)
		return;

	_quad->Update();
	_collider->Update();
}

void Brick::Render()
{
	if (isActive == false)
		return;

	_quad->Render();
	// _collider->Render();
}

bool Brick::IsCollision_Bullet(shared_ptr<Bullet> bullet)
{
	return _collider->IsCollision(bullet->GetCollider());
}
