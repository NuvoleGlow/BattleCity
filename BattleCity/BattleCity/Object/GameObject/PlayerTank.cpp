#include "framework.h"

#include "Bullet.h"
#include "Brick.h"

#include "PlayerTank.h"

PlayerTank::PlayerTank()
{
	CreateAction(L"Resource/Texture/PlayerTank.png");
	_firePos = make_shared<Transform>();
	_firePos->SetParent(_sprite->GetTransform());
	_firePos->GetPos().y += 16.0f;
	_collider = make_shared<CircleCollider>(16.0f);
	_collider->GetTransform()->SetParent(_sprite->GetTransform());
	_bullet = make_shared<Bullet>();

	_sprite->GetTransform()->SetPos(Vector2(192.0f, 48.0f));

}

PlayerTank::~PlayerTank()
{
}

void PlayerTank::CreateAction(wstring file, float speed, Action::Type type)
{
	_sprite = make_shared<Sprite>(file, Vector2(32.0f, 32.0f), Vector2(2.0f, 1.0f));

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
		if (_sprite->GetTransform()->GetPos().x < 48.0f)
			return;
		_sprite->GetTransform()->GetAngle() = PI * 0.5f;
		_sprite->GetTransform()->GetPos().x -= DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('D'))
	{
		if (_sprite->GetTransform()->GetPos().x > 432.0f)
			return;
		_sprite->GetTransform()->GetAngle() = PI * 1.5f;
		_sprite->GetTransform()->GetPos().x += DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('W'))
	{
		if (_sprite->GetTransform()->GetPos().y > 432.0f)
			return;
		_sprite->GetTransform()->GetAngle() = PI * 0.0f;
		_sprite->GetTransform()->GetPos().y += DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('S'))
	{
		if (_sprite->GetTransform()->GetPos().y < 48.0f)
			return;
		_sprite->GetTransform()->GetAngle() = PI * 1.0f;
		_sprite->GetTransform()->GetPos().y -= DELTA_TIME * _speed;
	}
	if (KEY_PRESS(VK_SPACE))
	{
		Shot();
	}
}

void PlayerTank::Update()
{
	if (isActive == false)
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
	if (isActive == false)
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
		_bullet->SetDirection((_firePos->GetWorldPos() - _sprite->GetTransform()->GetWorldPos()).Normal());
		_bullet->GetTransform()->GetPos() = _firePos->GetWorldPos();
		_bullet->GetTransform()->GetAngle() = _sprite->GetTransform()->GetAngle();
		_bullet->GetTransform()->SetSRT();
	}
}

bool PlayerTank::IsCollision_Brick(shared_ptr<class Brick> brick)
{
	return _collider->IsCollision(brick->GetCollider());
}

bool PlayerTank::IsCollision_Bullet(shared_ptr<class Bullet> bullet)
{
	return false;
}

shared_ptr<Bullet> PlayerTank::GetBullet()
{
	if (_bullet->isActive == false)
		return nullptr;

	return _bullet;
}
