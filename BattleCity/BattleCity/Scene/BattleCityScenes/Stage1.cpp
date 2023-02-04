#include "framework.h"

#include "Object/GameObject/Frame.h"
#include "Object/GameObject/HeadQuarter.h"
#include "Object/GameObject/Brick.h"
#include "Object/GameObject/PlayerTank.h"
#include "Object/GameObject/Bullet.h"
#include "Object/GameObject/Concrete.h"

#include "Stage1.h"

Stage1::Stage1()
{
	_backGround = make_shared<Frame>();
	_headQuarter = make_shared<HeadQuarter>();
	_player = make_shared<PlayerTank>();

	Load_C();
	Load_B();
}

Stage1::~Stage1()
{
}

void Stage1::Update()
{
	if (_player->GetBullet() != nullptr && _headQuarter->IsCollision_Bullet(_player->GetBullet()))
	{
		_headQuarter->isActive = false;
		_player->GetBullet()->isActive = false;
	}
	_headQuarter->Update();

	_player->Update();

	for (auto brick : _bricks)
	{
		if (_player->GetBullet() != nullptr && brick->IsCollision_Bullet(_player->GetBullet()))
		{
			brick->isActive = false;
			_player->GetBullet()->isActive = false;
			brick->GetCollider()->isActive = false;
		}
		brick->Update();
	}
	for (auto concrete : _concretes)
	{
		if (_player->GetBullet() != nullptr && concrete->IsCollision_Bullet(_player->GetBullet()))
		{
			_player->GetBullet()->isActive = false;
		}
		concrete->Update();
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
}

void Stage1::NextScene()
{
	SCENE->ChangeScene(2);
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

void Stage1::Load_G()
{
}
