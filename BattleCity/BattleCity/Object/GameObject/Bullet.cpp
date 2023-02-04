#include "framework.h"

#include "Brick.h"

#include "Bullet.h"

Bullet::Bullet()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Bullet.png", Vector2(6.0f, 8.0f));
	_collider = make_shared<CircleCollider>(3.0f);
	_collider->GetTransform()->SetParent(_quad->GetTransform());
	_collider->GetTransform()->GetPos().y += 1.0f;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_quad->GetTransform()->GetWorldPos().x < 35.0f ||
		_quad->GetTransform()->GetWorldPos().x > 445.0f)
	{
		isActive = false;
	}

	if (_quad->GetTransform()->GetWorldPos().y < 35.0f ||
		_quad->GetTransform()->GetWorldPos().y > 445.0f)
	{
		isActive = false;
	}

	if (isActive == false)
		return;

	_quad->GetTransform()->GetPos() += _direction * _speed * DELTA_TIME;

	_collider->Update();
	_quad->Update();
}

void Bullet::Render()
{
	if (isActive == false)
		return;

	// _collider->Render();
	_quad->Render();
}

void Bullet::SetDirection(Vector2 dir)
{
	_direction = dir;
}

bool Bullet::IsCollision(shared_ptr<Collider> collider)
{
	return _collider->IsCollision(collider);
}

bool Bullet::IsCollision(shared_ptr<class Brick> brick)
{
	return _collider->IsCollision(brick->GetCollider());
}
