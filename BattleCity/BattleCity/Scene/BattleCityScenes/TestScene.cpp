#include "framework.h"

#include "Object/GameObject/Frame.h"
#include "Object/GameObject/HeadQuarter.h"
#include "Object/GameObject/Brick.h"
#include "Object/GameObject/PlayerTank.h"
#include "Object/GameObject/Bullet.h"
#include "Object/GameObject/Concrete.h"
#include "Object/GameObject/Grass.h"

#include "TestScene.h"

TestScene::TestScene()
{
	Timer::GetInstance()->SetLockFPS(60.0);
	Init();
}

TestScene::~TestScene()
{
}

void TestScene::Update()
{
	if (KEY_UP(VK_SPACE))
	{
		NextScene();
	}

	for (auto brick : _bricks)
	{
		brick->Update();
	}
	for (auto concrete : _concretes)
	{
		concrete->Update();
	}
	for (auto grass : _grasses)
	{
		grass->Update();
	}
	
	_headQuarter->Update();
}

void TestScene::PreRender()
{
	_backGround->PreRender();
}

void TestScene::Render()
{
	_headQuarter->Render();
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

void TestScene::NextScene()
{
	SCENE->ChangeScene(404);
}

void TestScene::Init()
{
	_backGround = make_shared<Frame>();
	_headQuarter = make_shared<HeadQuarter>();

	Load_B();
	Load_C();
	Load_G();

	Save_Score();
	Save_HP();
}

void TestScene::Save_Score()
{
	BinaryWriter writer = BinaryWriter(L"Save/Score.sc");

	writer.Int(0);
}

void TestScene::Save_HP()
{
	BinaryWriter writer = BinaryWriter(L"Save/HP.hp");

	writer.Int(3);
}

void TestScene::Save_B()
{
	if (debug == false)
		return;
	
	BinaryWriter writer = BinaryWriter(L"Save/Stage0_B.map");
	
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
	
	BinaryWriter writer = BinaryWriter(L"Save/Stage0_C.map");
	
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
	if (debug == false)
		return;

	BinaryWriter writer = BinaryWriter(L"Save/Stage0_G.map");

	vector<Vector2> temp;
	for (int i = 0; i < _grasses.size(); i++)
	{
		temp.push_back(_grasses[i]->GetQuad()->GetTransform()->GetWorldPos());
	}

	writer.UInt(temp.size());
	writer.Byte(temp.data(), sizeof(Vector2) * temp.size());
}

void TestScene::Load_B()
{
	BinaryReader reader = BinaryReader(L"Save/Stage0_B.map");

	vector<Vector2> temp;
	UINT size = reader.UInt();
	temp.resize(size);

	void* ptr = temp.data();
	reader.Byte(&ptr, sizeof(Vector2) * size);
	_bricks.clear();
	for (int i = 0; i < temp.size(); i++)
	{
		shared_ptr<Brick> brick = make_shared<Brick>();
		brick->GetQuad()->GetTransform()->SetPos(temp[i]);
		_bricks.push_back(brick);
	}
}

void TestScene::Load_C()
{
	BinaryReader reader = BinaryReader(L"Save/Stage0_C.map");

	vector<Vector2> temp;
	UINT size = reader.UInt();
	temp.resize(size);

	void* ptr = temp.data();
	reader.Byte(&ptr, sizeof(Vector2) * size);
	_concretes.clear();
	for (int i = 0; i < temp.size(); i++)
	{
		shared_ptr<Concrete> concrete = make_shared<Concrete>();
		concrete->GetQuad()->GetTransform()->SetPos(temp[i]);
		_concretes.push_back(concrete);
	}
}

void TestScene::Load_G()
{
	BinaryReader reader = BinaryReader(L"Save/Stage0_G.map");

	vector<Vector2> temp;
	UINT size = reader.UInt();
	temp.resize(size);

	void* ptr = temp.data();
	reader.Byte(&ptr, sizeof(Vector2) * size);
	_grasses.clear();
	for (int i = 0; i < temp.size(); i++)
	{
		shared_ptr<Grass> grass = make_shared<Grass>();
		grass->GetQuad()->GetTransform()->SetPos(temp[i]);
		_grasses.push_back(grass);
	}
}
