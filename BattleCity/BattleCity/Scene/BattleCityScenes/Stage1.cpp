#include "framework.h"

#include "Object/GameObject/Frame.h"
#include "Object/GameObject/HeadQuarter.h"
#include "Object/GameObject/Brick.h"
#include "Object/GameObject/PlayerTank.h"
#include "Object/GameObject/Bullet.h"
#include "Object/GameObject/Concrete.h"
#include "Object/GameObject/EnemyTank.h"

#include "Stage1.h"

Stage1::Stage1()
{
	_backGround = make_shared<Frame>();
	_headQuarter = make_shared<HeadQuarter>();
	_player = make_shared<PlayerTank>();

	for (int i = 0; i < 1; i++)
	{
		shared_ptr<EnemyTank> enemy = make_shared<EnemyTank>();
		enemy->GetCollider()->GetTransform()->SetPos(Vector2(464.0f, 240.0f));
		_tanks.push_back(enemy);
	}

	Load_B();
	Load_C();
}

Stage1::~Stage1()
{
}

void Stage1::Update()
{
	_createCheck += DELTA_TIME;

	for (auto enemy : _tanks)
	{
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
			_player->Attack_E(enemy);
			_player->Attack_H(_headQuarter);
			enemy->Attack_P(_player);
			enemy->Attack_H(_headQuarter);
			enemy->Update();
			_player->Update();
			_headQuarter->Update();
		}
	}

	CreateTank();

	if (GameEnd() == true)
	{
		SCENE->ChangeScene(0);
	}

	if (StageClear() == true)
	{
		SCENE->ChangeScene(2);
	}
}

void Stage1::PreRender()
{
	_backGround->Render();
}

void Stage1::Render()
{
	_headQuarter->Render();
	_player->Render();
	for (auto brick : _bricks)
	{
		brick->Render();
	}
	for (auto concrete : _concretes)
	{
		concrete->Render();
	}
	for (auto enemy : _tanks)
	{
		enemy->Render();
	}
}

void Stage1::CreateTank()
{
	if (_createCheck < _createDelay || _count >= 1)
		return;
	else
		_createCheck = 0.0f;

	for (auto enemy : _tanks)
	{
		if (enemy->isActive == false)
		{
			enemy->isActive = true;
			enemy->GetCollider()->GetTransform()->SetPos(_backGround->GetspawnPoint(_count));
			_count++;
			break;
		}
	}
}

void Stage1::Load_B()
{
	BinaryReader reader = BinaryReader(L"Save/Stage1_B.map");

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

void Stage1::Load_C()
{
	BinaryReader reader = BinaryReader(L"Save/Stage1_C.map");

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

bool Stage1::GameEnd()
{
	if (_headQuarter->isActive == false)
		return true;

	if (_player->CheckAlive() == false)
		return true;

	return false;
}

bool Stage1::StageClear()
{
	if (_count >= 1)
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
