#include "framework.h"

#include "Object/GameObject/Frame.h"
#include "Object/GameObject/HeadQuarter.h"
#include "Object/GameObject/Brick.h"
#include "Object/GameObject/PlayerTank.h"
#include "Object/GameObject/Bullet.h"
#include "Object/GameObject/Concrete.h"

#include "TestScene.h"

TestScene::TestScene()
{
	debug = true;

	_backGround = make_shared<Frame>();
	_headQuarter = make_shared<HeadQuarter>();
	_player = make_shared<PlayerTank>();

	vector<Vector2> position;
	// 
	// position.push_back(Vector2(216.0f, 40.0f));
	// position.push_back(Vector2(216.0f, 56.0f));
	// position.push_back(Vector2(216.0f, 72.0f));
	// 
	// position.push_back(Vector2(264.0f, 40.0f));
	// position.push_back(Vector2(264.0f, 56.0f));
	// position.push_back(Vector2(264.0f, 72.0f));
	// 
	// position.push_back(Vector2(232.0f, 72.0f));
	// position.push_back(Vector2(248.0f, 72.0f));
	// 
	// -------------------------------------------------

	for (int i = 0; i < position.size(); i++)
	{
		shared_ptr<Concrete> concrete = make_shared<Concrete>();
		concrete->GetQuad()->GetTransform()->SetPos(position[i]);
		_concretes.push_back(concrete);
	}
}

TestScene::~TestScene()
{
}

void TestScene::Update()
{
	if (KEY_PRESS('B'))
	{
		Save_B();
	}
	if (KEY_PRESS('C'))
	{
		Save_C();
	}
	if (KEY_PRESS('G'))
	{
		Save_B();
	}
	if (KEY_PRESS('N'))
	{
		NextScene();
	}

	if (_player->GetBullet() != nullptr && _headQuarter->IsCollision_Bullet(_player->GetBullet()))
	{
		_headQuarter->isActive = false;
		_player->GetBullet()->isActive = false;
	}
	_headQuarter->Update();

	for (auto concrete : _concretes)
	{
		if (_player->GetBullet() != nullptr && concrete->IsCollision_Bullet(_player->GetBullet()))
		{
			_player->GetBullet()->isActive = false;
		}
		concrete->Update();
	}
	_player->Update();
}

void TestScene::PreRender()
{
	_backGround->Render();
}

void TestScene::Render()
{
	_headQuarter->Render();
	_player->Render();
	for (auto concrete : _concretes)
	{
		concrete->Render();
	}
}

void TestScene::NextScene()
{
	SCENE->ChangeScene(1);
}

void TestScene::Save_B()
{
	if (debug == false)
		return;

	BinaryWriter writer = BinaryWriter(L"Save/Stage1_B.map");

	vector<Vector2> temp;
	for (int i = 0; i < _bricks.size(); i++)
	{
		temp.push_back(_bricks[i]->GetQuad()->GetTransform()->GetWorldPos());
	}

	writer.UInt(temp.size());
	writer.Byte(temp.data(), sizeof(Vector2) * temp.size());
}

void TestScene::Save_C()
{
	if (debug == false)
		return;

	BinaryWriter writer = BinaryWriter(L"Save/Stage1_C.map");

	vector<Vector2> temp;
	for (int i = 0; i < _concretes.size(); i++)
	{
		temp.push_back(_concretes[i]->GetQuad()->GetTransform()->GetWorldPos());
	}

	writer.UInt(temp.size());
	writer.Byte(temp.data(), sizeof(Vector2) * temp.size());
}

void TestScene::Save_G()
{
}
