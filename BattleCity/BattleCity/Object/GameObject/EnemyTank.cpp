#include "framework.h"

#include "Bullet.h"
#include "PlayerTank.h"
#include "Concrete.h"
#include "Brick.h"
#include "HeadQuarter.h"

#include "EnemyTank.h"

EnemyTank::EnemyTank()
{
	srand((unsigned int)time(NULL));

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
	int direction = rand() % 4;
	if (direction == 0)
	{
		if (_collider->GetTransform()->GetPos().x < 47.0f)
			return;
		_collider->GetTransform()->GetAngle() = PI * 0.5f;
		_dir = { -1.0f, 0.0f };
	}
	if (direction == 1)
	{
		if (_collider->GetTransform()->GetPos().x > 433.0f)
			return;
		_collider->GetTransform()->GetAngle() = PI * 1.5f;
		_dir = { 1.0f, 0.0f };
	}
	if (direction == 2)
	{
		if (_collider->GetTransform()->GetPos().y > 433.0f)
			return;
		_collider->GetTransform()->GetAngle() = PI * 0.0f;
		_dir = { 0.0f, 1.0f };
	}
	if (direction == 3)
	{
		if (_collider->GetTransform()->GetPos().y < 47.0f)
			return;
		_collider->GetTransform()->GetAngle() = PI * 1.0f;
		_dir = { 0.0f, -1.0f };
	}
}

void EnemyTank::Init()
{
}

void EnemyTank::Update()
{
	if (CheckAlive() == false)
		return;

	_fireCheck += DELTA_TIME;
	_moveCheck += DELTA_TIME;

	_collider->GetTransform()->GetPos() += _dir * DELTA_TIME * _speed;
	if (_moveCheck > _moveDelay)
	{
		_moveCheck = 0.0f;
		Input();
	}
	Shot();
	_sprite->Update();
	_action->Update();
	_firePos->Update();
	_collider->Update();
	_bullet->Update();
}

void EnemyTank::Render()
{
	if (CheckAlive() == false)
		return;

	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Render();
	_bullet->Render();
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
		_bullet->GetCollider()->GetTransform()->GetPos() = _firePos->GetWorldPos();
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
		player->MinusHP();
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
		enemy->MinusHP();
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

bool EnemyTank::CheckAlive()
{
	if (isActive == false || _hp <= 0)
	{
		_collider->isActive = false;
		isActive = false;
		_hp = 0;
		return false;
	}
	return true;
}
