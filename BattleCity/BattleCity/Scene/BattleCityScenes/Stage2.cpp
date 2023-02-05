#include "framework.h"

#include "Object/GameObject/Frame.h"
#include "Object/GameObject/HeadQuarter.h"
#include "Object/GameObject/PlayerTank.h"
#include "Object/GameObject/EnemyTank.h"
#include "Object/GameObject/Bullet.h"
#include "Object/GameObject/Brick.h"
#include "Object/GameObject/Concrete.h"
#include "Object/GameObject/Grass.h"

#include "Stage2.h"

Stage2::Stage2()
{
	_backGround = make_shared<Frame>();
	_headQuarter = make_shared<HeadQuarter>();
	_player = make_shared<PlayerTank>();

	for (int i = 0; i < 20; i++)
	{
		shared_ptr<EnemyTank> enemy = make_shared<EnemyTank>();
		enemy->GetCollider()->GetTransform()->SetPos(_backGround->GetspawnPoint(rand() % 3));
		_tanks.push_back(enemy);
	}

	Load_C();
	Load_B();
	Load_G();
}

Stage2::~Stage2()
{
}

void Stage2::Update()
{
	_createCheck += DELTA_TIME;
	CreateTank();

	if (_player->GetBullet() != nullptr && _headQuarter->IsCollision_Bullet(_player->GetBullet()))
	{
		_headQuarter->isActive = false;
		_player->GetBullet()->isActive = false;
	}

	for (auto brick : _bricks)
	{
		if (_player->GetBullet() != nullptr && brick->IsCollision_Bullet(_player->GetBullet()))
		{
			brick->isActive = false;
			brick->GetCollider()->isActive = false;
			_player->GetBullet()->isActive = false;
		}
		brick->GetCollider()->Block(_player->GetCollider());
		brick->Update();
	}
	for (auto concrete : _concretes)
	{
		if (_player->GetBullet() != nullptr && concrete->IsCollision_Bullet(_player->GetBullet()))
		{
			_player->GetBullet()->isActive = false;
		}
		concrete->GetCollider()->Block(_player->GetCollider());
		concrete->Update();
	}
	for (auto enemy : _tanks)
	{
		if (_player->GetBullet() != nullptr && enemy->IsCollision_Bullet(_player->GetBullet()))
		{
			enemy->IsCollision_Bullet(_player->GetBullet());
			enemy->GetCollider()->isActive = false;
			_player->GetBullet()->isActive = false;
		}
		enemy->GetCollider()->Block(_player->GetCollider());
		enemy->Update();
	}
	for (auto grass : _grasses)
	{
		grass->Update();
	}

	_headQuarter->Update();
	_player->Update();

	if (GameEnd() == true)
	{
		SCENE->ChangeScene(0);
		return;
	}

	if (StageClear() == true)
	{
		SCENE->ChangeScene(3);
		return;
	}
}

void Stage2::PreRender()
{
	_backGround->Render();
}

void Stage2::Render()
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
	for (auto grass : _grasses)
	{
		grass->Render();
	}
}

void Stage2::CreateTank()
{
	if (_createCheck > _createDelay)
		_createCheck = 0.0f;
	else
		return;

	if (_count == 19)
		return;


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

void Stage2::Load_B()
{
	BinaryReader reader = BinaryReader(L"Save/Stage2_B.map");

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

void Stage2::Load_C()
{
	BinaryReader reader = BinaryReader(L"Save/Stage2_C.map");

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

void Stage2::Load_G()
{
	BinaryReader reader = BinaryReader(L"Save/Stage2_G.map");

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

bool Stage2::GameEnd()
{
	if (_headQuarter->isActive == false)
		return true;

	if (_player->CheckAlive() == false)
		return true;

	return false;
}

bool Stage2::StageClear()
{
	if (_count == 20)
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
