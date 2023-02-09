#include "framework.h"

#include "Object/GameObject/Frame.h"
#include "Object/GameObject/HeadQuarter.h"
#include "Object/GameObject/PlayerTank.h"
#include "Object/GameObject/EnemyTank.h"
#include "Object/GameObject/Bullet.h"
#include "Object/GameObject/Brick.h"
#include "Object/GameObject/Concrete.h"
#include "Object/GameObject/Grass.h"

#include "Stage3.h"

Stage3::Stage3()
{
	_backGround = make_shared<Frame>();
	_headQuarter = make_shared<HeadQuarter>();
	_player = make_shared<PlayerTank>();

	for (int i = 0; i < 15; i++)
	{
		shared_ptr<EnemyTank> enemy = make_shared<EnemyTank>();
		enemy->GetCollider()->GetTransform()->SetPos(Vector2(-16.0f, 16.0f));
		_tanks.push_back(enemy);
	}

	Load_B();
	Load_C();
	Load_G();
}

Stage3::~Stage3()
{
}

void Stage3::Update()
{
	_createCheck += DELTA_TIME;

	CreateTank();

	for (auto enemy : _tanks)
	{
		for (auto collider : _backGround->GetColliders())
		{
			collider->Block(enemy->GetCollider());
			collider->Block(_player->GetCollider());
		}
		for (auto brick : _bricks)
		{
			brick->GetCollider()->Block(enemy->GetCollider());
			brick->GetCollider()->Block(_player->GetCollider());
			_player->Attack_B(brick);
			enemy->Attack_B(brick);
			brick->Update();
		}
		for (auto concrete : _concretes)
		{
			concrete->GetCollider()->Block(enemy->GetCollider());
			concrete->GetCollider()->Block(_player->GetCollider());
			_player->Attack_C(concrete);
			enemy->Attack_C(concrete);
			concrete->Update();
		}

		{
			enemy->GetCollider()->Block(_player->GetCollider());
			_player->GetCollider()->Block(enemy->GetCollider());
			_player->Attack_E(enemy);
			_player->Attack_H(_headQuarter);
			enemy->Attack_P(_player);
			enemy->Attack_H(_headQuarter);
			enemy->Update();
		}
	}

	_player->Update();
	_headQuarter->Update();
	for (auto grass : _grasses)
	{
		grass->Update();
	}

	if (GameEnd() == true)
	{
		SCENE->ChangeScene(0);
	}

	if (StageClear() == true)
	{
		SCENE->ChangeScene(4);
	}
}

void Stage3::PreRender()
{
	_backGround->Render();
}

void Stage3::Render()
{
	_headQuarter->Render();
	_player->Render();
	for (auto enemy : _tanks)
	{
		enemy->Render();
	}
	for (auto brick : _bricks)
	{
		brick->Render();
	}
	for (auto concrete : _concretes)
	{
		concrete->Render();
	}
	for (auto grass : _grasses)
	{
		grass->Render();
	}
}

void Stage3::CreateTank()
{
	if (_createCheck < _createDelay || _count >= _tanks.size())
		return;
	else
		_createCheck = 0.0f;

	_tanks[_count]->GetCollider()->GetTransform()->SetPos(_backGround->GetspawnPoint(rand()));
	_tanks[_count]->isActive = true;
	_count += 1;
}

void Stage3::Load_B()
{
	BinaryReader reader = BinaryReader(L"Save/Stage3_B.map");

	vector<Vector2> temp;
	UINT size = reader.UInt();
	temp.resize(size);

	void* ptr = temp.data();
	reader.Byte(&ptr, sizeof(Vector2) * size);

	for (int i = 0; i < temp.size(); i++)
	{
		shared_ptr<Brick> brick = make_shared<Brick>();
		brick->GetQuad()->GetTransform()->SetPos(temp[i]);
		_bricks.push_back(brick);
	}
}

void Stage3::Load_C()
{
	BinaryReader reader = BinaryReader(L"Save/Stage3_C.map");

	vector<Vector2> temp;
	UINT size = reader.UInt();
	temp.resize(size);

	void* ptr = temp.data();
	reader.Byte(&ptr, sizeof(Vector2) * size);

	for (int i = 0; i < temp.size(); i++)
	{
		shared_ptr<Concrete> concrete = make_shared<Concrete>();
		concrete->GetQuad()->GetTransform()->SetPos(temp[i]);
		_concretes.push_back(concrete);
	}
}

void Stage3::Load_G()
{
	BinaryReader reader = BinaryReader(L"Save/Stage3_G.map");

	vector<Vector2> temp;
	UINT size = reader.UInt();
	temp.resize(size);

	void* ptr = temp.data();
	reader.Byte(&ptr, sizeof(Vector2) * size);

	for (int i = 0; i < temp.size(); i++)
	{
		shared_ptr<Grass> grass = make_shared<Grass>();
		grass->GetQuad()->GetTransform()->SetPos(temp[i]);
		_grasses.push_back(grass);
	}
}

bool Stage3::GameEnd()
{
	if (_headQuarter->isActive == false)
		return true;

	if (_player->isActive == false)
		return true;

	return false;
}

bool Stage3::StageClear()
{
	if (_count >= _tanks.size())
	{
		for (auto enemy : _tanks)
		{
			if (enemy->isActive == true)
				return false;
		}
		return true;
	}
	return false;
}
