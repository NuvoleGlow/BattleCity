#include "framework.h"

#include "Bullet.h"

#include "Tank.h"

Tank::Tank()
{
	_transform = make_shared<Transform>();
	_firePos = make_shared<Transform>();
	_firePos->SetParent(_transform);
	_firePos->GetPos().y += 16.0f;
	_collider = make_shared<CircleCollider>(16.0f);
	_collider->GetTransform()->SetParent(_transform);
	_bullet = make_shared<Bullet>();
	CreateAction(L"Resource/Texture/TestTank.png");

	_transform->SetPos(Vector2(192.0f, 48.0f));
}

Tank::~Tank()
{
}

void Tank::CreateAction(wstring file, float speed, Action::Type type)
{
	_sprite = make_shared<Sprite>(file, Vector2(32.0f, 32.0f), Vector2(2.0f, 1.0f));
	_sprite->GetTransform()->SetParent(_transform);

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

void Tank::Init()
{
}

void Tank::Input()
{
	if (KEY_PRESS('A'))
	{
		if (_transform->GetPos().x < 48.0f)
			return;
		_transform->GetAngle() = PI * 0.5f;
		_transform->GetPos().x -= DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('D'))
	{
		if (_transform->GetPos().x > 432.0f)
			return;
		_transform->GetAngle() = PI * 1.5f;
		_transform->GetPos().x += DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('W'))
	{
		if (_transform->GetPos().y > 432.0f)
			return;
		_transform->GetAngle() = PI * 0.0f;
		_transform->GetPos().y += DELTA_TIME * _speed;
	}
	else if (KEY_PRESS('S'))
	{
		if (_transform->GetPos().y < 48.0f)
			return;
		_transform->GetAngle() = PI * 1.0f;
		_transform->GetPos().y -= DELTA_TIME * _speed;
	}
	if (KEY_PRESS(VK_SPACE))
	{
		Shot();
	}
}

void Tank::Update()
{
	if (isActive == false)
		return;

	Input();

	_transform->Update();
	_firePos->Update();
	_collider->Update();
	_action->Update();
	_sprite->Update();
	_bullet->Update();
}

void Tank::Render()
{
	if (isActive == false)
		return;

	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Render();
	_collider->Render();
	_bullet->Render();
}

void Tank::Shot()
{
	if (_bullet->isActive == true)
		return;
	else
	{
		_bullet->isActive = true;
		_bullet->SetDirection((_firePos->GetWorldPos() - _transform->GetWorldPos()).Normal());
		_bullet->GetTransform()->GetPos() = _firePos->GetWorldPos();
		_bullet->GetTransform()->GetAngle() = _transform->GetAngle();
		_bullet->GetTransform()->SetSRT();
	}
}
