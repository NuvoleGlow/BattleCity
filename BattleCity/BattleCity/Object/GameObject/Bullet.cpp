#include "framework.h"
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

	_collider->Render();
	_quad->Render();
}

void Bullet::SetDirection(Vector2 dir)
{
	_direction = dir;
}

bool Bullet::IsCollision(shared_ptr<Collider> _collider)
{
    return false;
}
