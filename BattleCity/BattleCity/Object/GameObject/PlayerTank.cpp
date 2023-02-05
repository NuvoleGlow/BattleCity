#include "framework.h"

#include "Bullet.h"

#include "PlayerTank.h"

PlayerTank::PlayerTank()
{
	_collider = make_shared<CircleCollider>(16.0f);
	CreateAction(L"Resource/Texture/PlayerTank.png");
	_firePos = make_shared<Transform>();
	_firePos->SetParent(_collider->GetTransform());
	_firePos->GetPos().y += 16.0f;
	_bullet = make_shared<Bullet>();

	_collider->GetTransform()->SetPos(Vector2(176.0f, 48.0f));

}

PlayerTank::~PlayerTank()
{
}

void PlayerTank::CreateAction(wstring file, float speed, Action::Type type)
{
	_sprite = make_shared<Sprite>(file, Vector2(32.0f, 32.0f), Vector2(2.0f, 1.0f));
	_sprite->GetTransform()->SetParent(_collider->GetTransform());

	vector<Action::Clip> clips;
	for (int y = 0; y < 1; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			Action::Clip clip = Action::Clip(x * 16.0f, y * 16.0f, 16.0f, 16.0f, SRVManager::GetInstance()->AddSRV(file));
			clips.push_back(clip);
		}
	}

	string name(file.begin(), file.end());

	name = name.substr(name.find_last_of("/") + 1, name.size());
	name = name.substr(0, name.find_last_of("."));

	_action = make_shared<Action>(clips, name, type, speed);
	_action->Play();
}

void PlayerTank::Init()
{
}

void PlayerTank::Input()
{
	if (KEY_PRESS('A'))
	{
		if (_collider->GetTransform()->GetPos().x < 48.0f)
			return;
		_collider->GetTransform()->GetAngle() = PI * 0.5f;
		_collider->GetTransform()->GetPos().x -= DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('D'))
	{
		if (_collider->GetTransform()->GetPos().x > 432.0f)
			return;
		_collider->GetTransform()->GetAngle() = PI * 1.5f;
		_collider->GetTransform()->GetPos().x += DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('W'))
	{
		if (_collider->GetTransform()->GetPos().y > 432.0f)
			return;
		_collider->GetTransform()->GetAngle() = PI * 0.0f;
		_collider->GetTransform()->GetPos().y += DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('S'))
	{
		if (_collider->GetTransform()->GetPos().y < 48.0f)
			return;
		_collider->GetTransform()->GetAngle() = PI * 1.0f;
		_collider->GetTransform()->GetPos().y -= DELTA_TIME * _speed;
	}
	if (KEY_PRESS(VK_SPACE))
	{
		Shot();
	}
}

void PlayerTank::Update()
{
	if (isActive == false || _hp <= 0)
		return;

	Input();

	_sprite->Update();
	_action->Update();
	_firePos->Update();
	_collider->Update();
	_bullet->Update();
}

void PlayerTank::Render()
{
	if (isActive == false || _hp <= 0)
		return;

	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Render();
	_bullet->Render();
}

void PlayerTank::Shot()
{
	if (_bullet->isActive == true)
		return;
	else
	{
		_bullet->isActive = true;
		_bullet->SetDirection((_firePos->GetWorldPos() - _collider->GetTransform()->GetWorldPos()).Normal());
		_bullet->GetTransform()->GetPos() = _firePos->GetWorldPos();
		_bullet->GetTransform()->GetAngle() = _collider->GetTransform()->GetAngle();
		_bullet->GetTransform()->SetSRT();
	}
}

bool PlayerTank::CheckAlive()
{
	if (isActive == false || _hp <= 0)
		return false;
	return true;
}

bool PlayerTank::IsCollision_Bullet(shared_ptr<class Bullet> bullet)
{
	if (_collider->IsCollision(bullet->GetCollider()))
	{
		_hp--;
		return true;
	}
	return false;
}

shared_ptr<Bullet> PlayerTank::GetBullet()
{
	if (_bullet->isActive == false)
		return nullptr;

	return _bullet;
}
