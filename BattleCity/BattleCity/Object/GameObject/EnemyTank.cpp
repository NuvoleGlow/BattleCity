#include "framework.h"

#include "Bullet.h"

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
}

void EnemyTank::Init()
{
}

void EnemyTank::Update()
{
	if (isActive == false || _hp <= 0)
		return;
	
	Input();

	_fireCheck += DELTA_TIME;

	_sprite->Update();
	_action->Update();
	_firePos->Update();
	_collider->Update();
	_bullet->Update();
}

void EnemyTank::Render()
{
	if (isActive == false || _hp <= 0)
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
		_bullet->SetDirection((_firePos->GetWorldPos() - _sprite->GetTransform()->GetWorldPos()).Normal());
		_bullet->GetTransform()->GetPos() = _firePos->GetWorldPos();
		_bullet->GetTransform()->GetAngle() = _sprite->GetTransform()->GetAngle();
		_bullet->GetTransform()->SetSRT();
	}
	else
		return;
}

shared_ptr<Bullet> EnemyTank::GetBullet()
{
	if (_bullet->isActive == false)
		return nullptr;

	return _bullet;
}

bool EnemyTank::IsCollision_Bullet(shared_ptr<class Bullet> bullet)
{
	if (_collider->IsCollision(bullet->GetCollider()))
	{
		_hp--;
		return true;
	}
	return false;
}
