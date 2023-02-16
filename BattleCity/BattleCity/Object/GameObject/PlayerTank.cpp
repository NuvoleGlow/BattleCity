#include "framework.h"

#include "Bullet.h"
#include "Brick.h"
#include "Concrete.h"
#include "EnemyTank.h"
#include "HeadQuarter.h"
#include "HPCount.h"

#include "PlayerTank.h"

PlayerTank::PlayerTank()
{
	_collider = make_shared<CircleCollider>(16.0f);
	CreateAction(L"Resource/Texture/PlayerTank.png");
	_firePos = make_shared<Transform>();
	_firePos->SetParent(_collider->GetTransform());
	_firePos->GetPos().y += 16.0f;

	for (int i = 0; i < 5; i++)
	{
		shared_ptr<HPCount> lifeCount = make_shared<HPCount>();
		Vector2 pos = { 480.0f, 416.0f - i * 32.0f };
		lifeCount->GetQuad()->GetTransform()->SetPos(pos);
		_lifeCount.push_back(lifeCount);
	}

	_collider->GetTransform()->SetPos(Vector2(176.0f, 48.0f));

	_bullet = make_shared<Bullet>();
	EFFECT->AddEffect(L"Resource/Texture/Effect/Explosion.png", Vector2(5, 3), Vector2(16.0f, 16.0f), 0.01f);

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
		{
			_collider->GetTransform()->GetPos().x = 48.0f;
			return;
		}
		_collider->GetTransform()->GetAngle() = PI * 0.5f;
		_collider->GetTransform()->GetPos().x -= DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('D'))
	{
		if (_collider->GetTransform()->GetPos().x > 432.0f)
		{
			_collider->GetTransform()->GetPos().x = 432.0f;
			return;
		}
		_collider->GetTransform()->GetAngle() = PI * 1.5f;
		_collider->GetTransform()->GetPos().x += DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('W'))
	{
		if (_collider->GetTransform()->GetPos().y > 432.0f)
		{
			_collider->GetTransform()->GetPos().y = 432.0f;
			return;
		}
		_collider->GetTransform()->GetAngle() = PI * 0.0f;
		_collider->GetTransform()->GetPos().y += DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('S'))
	{
		if (_collider->GetTransform()->GetPos().y < 48.0f)
		{
			_collider->GetTransform()->GetPos().y = 48.0f;
			return;
		}
		_collider->GetTransform()->GetAngle() = PI * 1.0f;
		_collider->GetTransform()->GetPos().y -= DELTA_TIME * _speed;
	}
	if (KEY_UP(VK_SPACE))
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

	for (int i = 0; i < 5; i++)
	{
		if (_hp < i + 1)
			break;
		_lifeCount[i]->Update();
	}

	CheckAlive();
}

void PlayerTank::Render()
{
	if (isActive == false)
		return;

	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Render();
	_bullet->Render();
}

void PlayerTank::PostRender()
{
	for (int i = 0; i < 5; i++)
	{
		if (_hp < i + 1)
			break;
		_lifeCount[i]->Render();
	}
}

void PlayerTank::Shot()
{
	if (_bullet->isActive == true)
		return;
	else
	{
		_bullet->isActive = true;
		_bullet->SetDirection((_firePos->GetWorldPos() - _collider->GetTransform()->GetWorldPos()).Normal());
		_bullet->GetCollider()->GetTransform()->SetPos(_firePos->GetWorldPos());
		_bullet->GetCollider()->GetTransform()->GetAngle() = _collider->GetTransform()->GetAngle();
		_bullet->GetCollider()->GetTransform()->SetSRT();
	}
}

bool PlayerTank::Attack_E(shared_ptr<EnemyTank> enemy)
{
	if (enemy == nullptr || enemy->isActive == false)
		return false;
	if (_bullet->IsCollision(enemy->GetCollider()))
	{
		EFFECT->Play("Explosion", _bullet->GetCollider()->GetTransform()->GetWorldPos());
		_bullet->isActive = false;
		--enemy->GetHP();
		return true;
	}
	return false;
}

void PlayerTank::Attack_B(shared_ptr<Brick> brick)
{
	if (brick == nullptr || brick->isActive == false)
		return;
	if (_bullet->IsCollision(brick->GetCollider()))
	{
		EFFECT->Play("Explosion", _bullet->GetCollider()->GetTransform()->GetWorldPos());
		_bullet->isActive = false;
		brick->GetCollider()->isActive = false;
		brick->isActive = false;
	}
}

void PlayerTank::Attack_C(shared_ptr<Concrete> concrete)
{
	if (concrete == nullptr)
		return;
	if (_bullet->IsCollision(concrete->GetCollider()))
	{
		EFFECT->Play("Explosion", _bullet->GetCollider()->GetTransform()->GetWorldPos());
		_bullet->isActive = false;
	}
}

void PlayerTank::Attack_H(shared_ptr<HeadQuarter> headQuarter)
{
	if (headQuarter == nullptr || headQuarter->isActive == false)
		return;
	if (_bullet->IsCollision(headQuarter->GetCollider()))
	{
		EFFECT->Play("Explosion", _bullet->GetCollider()->GetTransform()->GetWorldPos());
		_bullet->isActive = false;
		headQuarter->GetCollider()->isActive = false;
		headQuarter->isActive = false;
	}
}

void PlayerTank::CheckAlive()
{
	if (_hp <= 0)
	{
		_collider->isActive = false;
		isActive = false;
		_hp = 0;
	}
}
