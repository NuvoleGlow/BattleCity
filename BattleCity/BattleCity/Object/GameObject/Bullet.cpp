#include "framework.h"

#include "Brick.h"

#include "Bullet.h"

Bullet::Bullet()
{
	_collider = make_shared<CircleCollider>(3.0f);
	_quad = make_shared<Quad>(L"Resource/Texture/Bullet.png", Vector2(6.0f, 8.0f));
	_quad->GetTransform()->SetParent(_collider->GetTransform());
	_collider->GetTransform()->SetPos(Vector2(-16.0f, 16.0f));
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_collider->GetTransform()->GetWorldPos().x < 35.0f ||
		_collider->GetTransform()->GetWorldPos().x > 445.0f)
	{
		isActive = false;
	}

	if (_collider->GetTransform()->GetWorldPos().y < 35.0f ||
		_collider->GetTransform()->GetWorldPos().y > 445.0f)
	{
		isActive = false;
	}

	if (isActive == false)
		return;

	_collider->GetTransform()->GetPos() += _direction * _speed * DELTA_TIME;

	_collider->Update();
	_quad->Update();
}

void Bullet::Render()
{
	if (isActive == false)
		return;

	_quad->Render();
}

void Bullet::SetDirection(Vector2 dir)
{
	_direction = dir;
}

bool Bullet::IsCollision(shared_ptr<Collider> collider)
{
	if (isActive == false)
		return false;

	return _collider->IsCollision(collider);
}
