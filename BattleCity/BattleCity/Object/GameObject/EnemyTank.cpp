#include "framework.h"

#include "Bullet.h"
#include "PlayerTank.h"
#include "Concrete.h"
#include "Brick.h"
#include "HeadQuarter.h"

#include "EnemyTank.h"

EnemyTank::EnemyTank()
{
	_collider = make_shared<CircleCollider>(16.0f);
	CreateAction(L"Resource/Texture/EnemyTank.png");
	_firePos = make_shared<Transform>();
	_firePos->SetParent(_collider->GetTransform());
	_firePos->GetPos().y += 16.0f;
	_bullet = make_shared<Bullet>();
}

EnemyTank::~EnemyTank()
{
}

void EnemyTank::CreateAction(wstring file, float speed, Action::Type type)
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

void EnemyTank::Input()
{
	if (_collider->GetTransform()->GetPos().x < 48.0f)
	{
		_collider->GetTransform()->GetPos().x = 48.0f;
	}
	if (_collider->GetTransform()->GetPos().x > 432.0f)
	{
		_collider->GetTransform()->GetPos().x = 432.0f;
	}
	if (_collider->GetTransform()->GetPos().y > 432.0f)
	{
		_collider->GetTransform()->GetPos().y = 432.0f;
	}
	if (_collider->GetTransform()->GetPos().y < 48.0f)
	{
		_collider->GetTransform()->GetPos().y = 48.0f;
	}
	if (_moveCheck > _moveDelay)
	{
		_moveCheck = 0.0f;

		int direction = rand() % 4;
		if (direction == 0)
		{
			_collider->GetTransform()->GetAngle() = PI * 0.5f;
			_dir = { -1.0f, 0.0f };
			return;
		}
		if (direction == 1)
		{
			_collider->GetTransform()->GetAngle() = PI * 1.5f;
			_dir = { 1.0f, 0.0f };
			return;
		}
		if (direction == 2)
		{
			_collider->GetTransform()->GetAngle() = PI * 0.0f;
			_dir = { 0.0f, 1.0f };
			return;
		}
		if (direction == 3)
		{
			_collider->GetTransform()->GetAngle() = PI * 1.0f;
			_dir = { 0.0f, -1.0f };
			return;
		}
	}

	if (_autoCheck > _autoDelay)
	{
		_autoCheck = 0.0f;
		_dir = (Vector2(0.0f, 0.0f) - _collider->GetTransform()->GetWorldPos() + Vector2(240.0f, 36.0f));
		if (_dir.Angle() >= -0.25f * PI && _dir.Angle() < 0.25f * PI)
		{
			_collider->GetTransform()->GetAngle() = PI * 1.5f;
			_dir = { 1.0f, 0.0f };
			return;
		}
		if (_dir.Angle() >= 0.25f * PI && _dir.Angle() < 0.75f * PI)
		{
			_collider->GetTransform()->GetAngle() = PI * 0.0f;
			_dir = { 0.0f, 1.0f };
			return;
		}
		if (_dir.Angle() >= 0.75f * PI || _dir.Angle() < -0.75f * PI)
		{
			_collider->GetTransform()->GetAngle() = PI * 0.5f;
			_dir = { -1.0f, 0.0f };
			return;
		}
		if (_dir.Angle() >= -0.75f * PI && _dir.Angle() < -0.25f * PI)
		{
			_collider->GetTransform()->GetAngle() = PI * 1.0f;
			_dir = { 0.0f, -1.0f };
			return;
		}
	}
}

void EnemyTank::Init()
{
}

void EnemyTank::Update()
{
	_fireCheck += DELTA_TIME;
	_moveCheck += DELTA_TIME;
	_autoCheck += DELTA_TIME;

	_bullet->Update();

	if (isActive == false)
		return;

	Input();

	if (_collider->GetTransform()->GetPos().x >= 48.0f && _collider->GetTransform()->GetPos().x <= 432.0f)
	{
		if (_collider->GetTransform()->GetPos().y >= 48.0f && _collider->GetTransform()->GetPos().y <= 432.0f)
		{
			_collider->GetTransform()->GetPos() += _dir * DELTA_TIME * _speed;
		}
	}
	Shot();
	_sprite->Update();
	_action->Update();
	_firePos->Update();
	_collider->Update();
	CheckAlive();
}

void EnemyTank::Render()
{
	_bullet->Render();

	if (isActive == false)
		return;

	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Render();
}

void EnemyTank::Shot()
{
	if (_bullet->isActive == true)
		return;
	else if (_fireCheck > _fireDelay)
	{
		_fireCheck = 0.0f;
		_bullet->isActive = true;
		_bullet->SetDirection(_dir);
		_bullet->GetCollider()->GetTransform()->GetPos() = _collider->GetTransform()->GetWorldPos();
		_bullet->GetCollider()->GetTransform()->GetAngle() = _collider->GetTransform()->GetAngle();
		_bullet->GetCollider()->GetTransform()->SetSRT();
	}
	else
		return;
}

void EnemyTank::Attack_P(shared_ptr<PlayerTank> player)
{
	if (player == nullptr || player->isActive == false)
		return;
	if (_bullet->IsCollision(player->GetCollider()))
	{
		_bullet->isActive = false;
		--player->GetHP();
	}
}

void EnemyTank::Attack_B(shared_ptr<Brick> brick)
{
	if (brick == nullptr || brick->isActive == false)
		return;
	if (_bullet->IsCollision(brick->GetCollider()))
	{
		_bullet->isActive = false;
		brick->GetCollider()->isActive = false;
		brick->isActive = false;
	}
}

void EnemyTank::Attack_C(shared_ptr<Concrete> concrete)
{
	if (concrete == nullptr)
		return;
	if (_bullet->IsCollision(concrete->GetCollider()))
	{
		_bullet->isActive = false;
	}
}

void EnemyTank::Attack_E(shared_ptr<EnemyTank> enemy)
{
	if (enemy == nullptr || enemy->isActive == false)
		return;
	if (_bullet->IsCollision(enemy->GetCollider()))
	{
		_bullet->isActive = false;
		--enemy->GetHP();
	}
}

void EnemyTank::Attack_H(shared_ptr<HeadQuarter> headQuarter)
{
	if (headQuarter == nullptr || headQuarter->isActive == false)
		return;
	if (_bullet->IsCollision(headQuarter->GetCollider()))
	{
		_bullet->isActive = false;
		headQuarter->GetCollider()->isActive = false;
		headQuarter->isActive = false;
	}
}

void EnemyTank::CheckAlive()
{
	if (_hp <= 0)
	{
		_collider->isActive = false;
		isActive = false;
		_hp = 0;
	}
}
