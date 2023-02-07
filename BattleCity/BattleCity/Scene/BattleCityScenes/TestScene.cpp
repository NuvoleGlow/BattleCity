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
	debug = true;

	_backGround = make_shared<Frame>();
	_headQuarter = make_shared<HeadQuarter>();

	vector<Vector2> position_b;
	vector<Vector2> position_c;
	vector<Vector2> position_g;
	
	position_b.push_back(Vector2(216.0f, 40.0f));
	position_b.push_back(Vector2(216.0f, 56.0f));
	position_b.push_back(Vector2(216.0f, 72.0f));
	
	position_b.push_back(Vector2(264.0f, 40.0f));
	position_b.push_back(Vector2(264.0f, 56.0f));
	position_b.push_back(Vector2(264.0f, 72.0f));
	
	position_b.push_back(Vector2(232.0f, 72.0f));
	position_b.push_back(Vector2(248.0f, 72.0f));

	// ------------------------------

	position_c.push_back(Vector2(40.0f, 40.0f));
	position_c.push_back(Vector2(56.0f, 40.0f));
	position_b.push_back(Vector2(72.0f, 40.0f));
	position_b.push_back(Vector2(88.0f, 40.0f));
	position_b.push_back(Vector2(104.0f, 40.0f));
	position_b.push_back(Vector2(120.0f, 40.0f));
	position_b.push_back(Vector2(328.0f, 40.0f));
	position_b.push_back(Vector2(344.0f, 40.0f));


	position_c.push_back(Vector2(40.0f, 56.0f));
	position_c.push_back(Vector2(56.0f, 56.0f));
	position_b.push_back(Vector2(72.0f, 56.0f));
	position_b.push_back(Vector2(88.0f, 56.0f));
	position_b.push_back(Vector2(104.0f, 56.0f));
	position_b.push_back(Vector2(120.0f, 56.0f));
	position_b.push_back(Vector2(328.0f, 56.0f));
	position_b.push_back(Vector2(344.0f, 56.0f));


	position_b.push_back(Vector2(40.0f, 72.0f));
	position_b.push_back(Vector2(56.0f, 72.0f));
	position_b.push_back(Vector2(72.0f, 72.0f));
	position_b.push_back(Vector2(88.0f, 72.0f));
	position_c.push_back(Vector2(136.0f, 72.0f));
	position_g.push_back(Vector2(328.0f, 72.0f));
	position_g.push_back(Vector2(344.0f, 72.0f));
	position_g.push_back(Vector2(360.0f, 72.0f));
	position_g.push_back(Vector2(376.0f, 72.0f));
	position_g.push_back(Vector2(392.0f, 72.0f));
	position_g.push_back(Vector2(408.0f, 72.0f));


	position_b.push_back(Vector2(40.0f, 88.0f));
	position_b.push_back(Vector2(56.0f, 88.0f));
	position_b.push_back(Vector2(72.0f, 88.0f));
	position_b.push_back(Vector2(88.0f, 88.0f));
	position_c.push_back(Vector2(136.0f, 88.0f));
	position_g.push_back(Vector2(328.0f, 88.0f));
	position_g.push_back(Vector2(344.0f, 88.0f));
	position_g.push_back(Vector2(360.0f, 88.0f));
	position_g.push_back(Vector2(376.0f, 88.0f));
	position_g.push_back(Vector2(392.0f, 88.0f));
	position_g.push_back(Vector2(408.0f, 88.0f));


	position_b.push_back(Vector2(40.0f, 104.0f));
	position_b.push_back(Vector2(56.0f, 104.0f));
	position_c.push_back(Vector2(136.0f, 104.0f));
	position_g.push_back(Vector2(328.0f, 104.0f));
	position_g.push_back(Vector2(344.0f, 104.0f));
	position_g.push_back(Vector2(360.0f, 104.0f));
	position_g.push_back(Vector2(376.0f, 104.0f));
	position_g.push_back(Vector2(392.0f, 104.0f));
	position_g.push_back(Vector2(408.0f, 104.0f));


	position_b.push_back(Vector2(40.0f, 120.0f));
	position_b.push_back(Vector2(56.0f, 120.0f));
	position_c.push_back(Vector2(136.0f, 120.0f));
	position_b.push_back(Vector2(264.0f, 120.0f));
	position_b.push_back(Vector2(280.0f, 120.0f));
	position_b.push_back(Vector2(296.0f, 120.0f));
	position_b.push_back(Vector2(312.0f, 120.0f));
	position_g.push_back(Vector2(328.0f, 120.0f));
	position_g.push_back(Vector2(344.0f, 120.0f));
	position_g.push_back(Vector2(360.0f, 120.0f));
	position_g.push_back(Vector2(376.0f, 120.0f));
	position_g.push_back(Vector2(392.0f, 120.0f));
	position_g.push_back(Vector2(408.0f, 120.0f));


	position_b.push_back(Vector2(200.0f, 136.0f));
	position_b.push_back(Vector2(216.0f, 136.0f));
	position_b.push_back(Vector2(264.0f, 136.0f));
	position_b.push_back(Vector2(280.0f, 136.0f));
	position_b.push_back(Vector2(296.0f, 136.0f));
	position_b.push_back(Vector2(312.0f, 136.0f));
	position_g.push_back(Vector2(328.0f, 136.0f));
	position_g.push_back(Vector2(344.0f, 136.0f));
	position_g.push_back(Vector2(360.0f, 136.0f));
	position_g.push_back(Vector2(376.0f, 136.0f));
	position_g.push_back(Vector2(392.0f, 136.0f));
	position_g.push_back(Vector2(408.0f, 136.0f));
	position_g.push_back(Vector2(424.0f, 136.0f));
	position_g.push_back(Vector2(440.0f, 136.0f));


	position_b.push_back(Vector2(200.0f, 152.0f));
	position_b.push_back(Vector2(216.0f, 152.0f));
	position_g.push_back(Vector2(328.0f, 152.0f));
	position_g.push_back(Vector2(344.0f, 152.0f));
	position_g.push_back(Vector2(360.0f, 152.0f));
	position_g.push_back(Vector2(376.0f, 152.0f));
	position_g.push_back(Vector2(392.0f, 152.0f));
	position_g.push_back(Vector2(408.0f, 152.0f));
	position_g.push_back(Vector2(424.0f, 152.0f));
	position_g.push_back(Vector2(440.0f, 152.0f));


	position_b.push_back(Vector2(40.0f, 168.0f));
	position_b.push_back(Vector2(56.0f, 168.0f));
	position_b.push_back(Vector2(72.0f, 168.0f));
	position_b.push_back(Vector2(120.0f, 168.0f));
	position_b.push_back(Vector2(136.0f, 168.0f));
	position_b.push_back(Vector2(152.0f, 168.0f));
	position_b.push_back(Vector2(168.0f, 168.0f));
	position_b.push_back(Vector2(216.0f, 168.0f));
	position_g.push_back(Vector2(328.0f, 168.0f));
	position_g.push_back(Vector2(344.0f, 168.0f));
	position_g.push_back(Vector2(360.0f, 168.0f));
	position_g.push_back(Vector2(376.0f, 168.0f));
	position_g.push_back(Vector2(392.0f, 168.0f));
	position_g.push_back(Vector2(408.0f, 168.0f));
	position_g.push_back(Vector2(424.0f, 168.0f));
	position_g.push_back(Vector2(440.0f, 168.0f));


	position_b.push_back(Vector2(40.0f, 184.0f));
	position_b.push_back(Vector2(56.0f, 184.0f));
	position_b.push_back(Vector2(72.0f, 184.0f));
	position_b.push_back(Vector2(120.0f, 184.0f));
	position_b.push_back(Vector2(136.0f, 184.0f));
	position_b.push_back(Vector2(152.0f, 184.0f));
	position_b.push_back(Vector2(168.0f, 184.0f));
	position_b.push_back(Vector2(216.0f, 184.0f));
	position_b.push_back(Vector2(232.0f, 184.0f));
	position_b.push_back(Vector2(248.0f, 184.0f));
	position_b.push_back(Vector2(264.0f, 184.0f));
	position_b.push_back(Vector2(280.0f, 184.0f));
	position_b.push_back(Vector2(296.0f, 184.0f));
	position_b.push_back(Vector2(312.0f, 184.0f));
	position_g.push_back(Vector2(328.0f, 184.0f));
	position_g.push_back(Vector2(344.0f, 184.0f));
	position_g.push_back(Vector2(360.0f, 184.0f));
	position_g.push_back(Vector2(376.0f, 184.0f));
	position_g.push_back(Vector2(392.0f, 184.0f));
	position_g.push_back(Vector2(408.0f, 184.0f));
	position_g.push_back(Vector2(424.0f, 184.0f));
	position_g.push_back(Vector2(440.0f, 184.0f));


	position_b.push_back(Vector2(72.0f, 200.0f));
	position_b.push_back(Vector2(88.0f, 200.0f));
	position_b.push_back(Vector2(136.0f, 200.0f));
	position_b.push_back(Vector2(152.0f, 200.0f));
	position_g.push_back(Vector2(328.0f, 200.0f));
	position_g.push_back(Vector2(344.0f, 200.0f));
	position_g.push_back(Vector2(360.0f, 200.0f));
	position_g.push_back(Vector2(376.0f, 200.0f));
	position_g.push_back(Vector2(392.0f, 200.0f));
	position_g.push_back(Vector2(408.0f, 200.0f));
	position_g.push_back(Vector2(424.0f, 200.0f));
	position_g.push_back(Vector2(440.0f, 200.0f));


	position_g.push_back(Vector2(328.0f, 216.0f));
	position_g.push_back(Vector2(344.0f, 216.0f));
	position_g.push_back(Vector2(360.0f, 216.0f));
	position_g.push_back(Vector2(376.0f, 216.0f));
	position_g.push_back(Vector2(392.0f, 216.0f));
	position_g.push_back(Vector2(408.0f, 216.0f));
	position_g.push_back(Vector2(424.0f, 216.0f));
	position_g.push_back(Vector2(440.0f, 216.0f));


	position_g.push_back(Vector2(72.0f, 232.0f));
	position_g.push_back(Vector2(88.0f, 232.0f));
	position_c.push_back(Vector2(232.0f, 232.0f));
	position_c.push_back(Vector2(248.0f, 232.0f));
	position_c.push_back(Vector2(264.0f, 232.0f));
	position_c.push_back(Vector2(280.0f, 232.0f));
	position_c.push_back(Vector2(296.0f, 232.0f));
	position_c.push_back(Vector2(312.0f, 232.0f));
	position_g.push_back(Vector2(392.0f, 232.0f));
	position_g.push_back(Vector2(408.0f, 232.0f));


	position_g.push_back(Vector2(72.0f, 248.0f));
	position_g.push_back(Vector2(88.0f, 248.0f));
	position_c.push_back(Vector2(232.0f, 248.0f));
	position_c.push_back(Vector2(248.0f, 248.0f));
	position_c.push_back(Vector2(264.0f, 248.0f));
	position_c.push_back(Vector2(280.0f, 248.0f));
	position_c.push_back(Vector2(296.0f, 248.0f));
	position_c.push_back(Vector2(312.0f, 248.0f));
	position_g.push_back(Vector2(392.0f, 248.0f));
	position_g.push_back(Vector2(408.0f, 248.0f));


	position_g.push_back(Vector2(40.0f, 264.0f));
	position_g.push_back(Vector2(56.0f, 264.0f));
	position_g.push_back(Vector2(72.0f, 264.0f));
	position_g.push_back(Vector2(88.0f, 264.0f));
	position_g.push_back(Vector2(104.0f, 264.0f));
	position_g.push_back(Vector2(120.0f, 264.0f));
	position_g.push_back(Vector2(136.0f, 264.0f));
	position_g.push_back(Vector2(152.0f, 264.0f));
	position_b.push_back(Vector2(232.0f, 264.0f));
	position_b.push_back(Vector2(248.0f, 264.0f));
	position_b.push_back(Vector2(408.0f, 264.0f));


	position_g.push_back(Vector2(40.0f, 280.0f));
	position_g.push_back(Vector2(56.0f, 280.0f));
	position_g.push_back(Vector2(72.0f, 280.0f));
	position_g.push_back(Vector2(88.0f, 280.0f));
	position_g.push_back(Vector2(104.0f, 280.0f));
	position_g.push_back(Vector2(120.0f, 280.0f));
	position_g.push_back(Vector2(136.0f, 280.0f));
	position_g.push_back(Vector2(152.0f, 280.0f));
	position_b.push_back(Vector2(232.0f, 280.0f));
	position_b.push_back(Vector2(248.0f, 280.0f));
	position_b.push_back(Vector2(408.0f, 280.0f));


	position_g.push_back(Vector2(40.0f, 296.0f));
	position_g.push_back(Vector2(56.0f, 296.0f));
	position_g.push_back(Vector2(72.0f, 296.0f));
	position_g.push_back(Vector2(88.0f, 296.0f));
	position_g.push_back(Vector2(104.0f, 296.0f));
	position_g.push_back(Vector2(120.0f, 296.0f));
	position_g.push_back(Vector2(136.0f, 296.0f));
	position_g.push_back(Vector2(152.0f, 296.0f));
	position_b.push_back(Vector2(168.0f, 296.0f));
	position_b.push_back(Vector2(184.0f, 296.0f));
	position_b.push_back(Vector2(200.0f, 296.0f));
	position_b.push_back(Vector2(216.0f, 296.0f));
	position_b.push_back(Vector2(232.0f, 296.0f));
	position_b.push_back(Vector2(248.0f, 296.0f));
	position_b.push_back(Vector2(328.0f, 296.0f));
	position_b.push_back(Vector2(344.0f, 296.0f));
	position_b.push_back(Vector2(408.0f, 296.0f));



	// ------------------------------

	for (int i = 0; i < position_b.size(); i++)
	{
		shared_ptr<Brick> brick = make_shared<Brick>();
		brick->GetQuad()->GetTransform()->SetPos(position_b[i]);
		_bricks.push_back(brick);
	}
	for (int i = 0; i < position_c.size(); i++)
	{
		shared_ptr<Concrete> concrete = make_shared<Concrete>();
		concrete->GetQuad()->GetTransform()->SetPos(position_c[i]);
		_concretes.push_back(concrete);
	}
	for (int i = 0; i < position_g.size(); i++)
	{
		shared_ptr<Grass> grass = make_shared<Grass>();
		grass->GetQuad()->GetTransform()->SetPos(position_g[i]);
		_grasses.push_back(grass);
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
		Save_G();
	}
	if (KEY_PRESS('N'))
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
	_backGround->Render();
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
	if (debug == false)
		return;

	SCENE->ChangeScene(1);
}

void TestScene::Save_B()
{
	if (debug == false)
		return;
	
	BinaryWriter writer = BinaryWriter(L"Save/Stage3_B.map");
	
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
	
	BinaryWriter writer = BinaryWriter(L"Save/Stage3_C.map");
	
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

	BinaryWriter writer = BinaryWriter(L"Save/Stage3_G.map");

	vector<Vector2> temp;
	for (int i = 0; i < _grasses.size(); i++)
	{
		temp.push_back(_grasses[i]->GetQuad()->GetTransform()->GetWorldPos());
	}

	writer.UInt(temp.size());
	writer.Byte(temp.data(), sizeof(Vector2) * temp.size());
}
