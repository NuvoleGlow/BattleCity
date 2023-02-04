#include "framework.h"

#include "Bullet.h"

#include "Concrete.h"

Concrete::Concrete()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Concrete.png", Vector2(16.0f, 16.0f));
	_collider = make_shared<CircleCollider>(8.0f);
	_collider->GetTransform()->SetParent(_quad->GetTransform());
}

Concrete::~Concrete()
{
}

void Concrete::Update()
{
	if (isActive == false)
		return;

	_quad->Update();
	_collider->Update();
}

void Concrete::Render()
{
	if (isActive == false)
		return;

	_quad->Render();
}

bool Concrete::IsCollision_Bullet(shared_ptr<Bullet> bullet)
{
	return _collider->IsCollision(bullet->GetCollider());
}
