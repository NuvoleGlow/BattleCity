#include "framework.h"

#include "Object/GameObject/Frame.h"
#include "Object/GameObject/HeadQuarter.h"
#include "Object/GameObject/BrickWall.h"
#include "Object/GameObject/Tank.h"

#include "TestScene.h"

TestScene::TestScene()
{
	_backGround = make_shared<Frame>();
	_headQuarter = make_shared<HeadQuarter>();
	_player = make_shared<Tank>();
	
	vector<Vector2> position;
	position.push_back(Vector2(220.0f, 36.0f));
	position.push_back(Vector2(260.0f, 36.0f));
	position.push_back(Vector2(212.0f, 36.0f));
	position.push_back(Vector2(268.0f, 36.0f));

	position.push_back(Vector2(220.0f, 44.0f));
	position.push_back(Vector2(260.0f, 44.0f));
	position.push_back(Vector2(212.0f, 44.0f));
	position.push_back(Vector2(268.0f, 44.0f));

	position.push_back(Vector2(220.0f, 52.0f));
	position.push_back(Vector2(260.0f, 52.0f));
	position.push_back(Vector2(212.0f, 52.0f));
	position.push_back(Vector2(268.0f, 52.0f));

	position.push_back(Vector2(220.0f, 60.0f));
	position.push_back(Vector2(260.0f, 60.0f));
	position.push_back(Vector2(212.0f, 60.0f));
	position.push_back(Vector2(268.0f, 60.0f));

	position.push_back(Vector2(220.0f, 68.0f));
	position.push_back(Vector2(260.0f, 68.0f));
	position.push_back(Vector2(212.0f, 68.0f));
	position.push_back(Vector2(268.0f, 68.0f));
	position.push_back(Vector2(228.0f, 68.0f));
	position.push_back(Vector2(236.0f, 68.0f));
	position.push_back(Vector2(244.0f, 68.0f));
	position.push_back(Vector2(252.0f, 68.0f));

	position.push_back(Vector2(220.0f, 76.0f));
	position.push_back(Vector2(260.0f, 76.0f));
	position.push_back(Vector2(212.0f, 76.0f));
	position.push_back(Vector2(268.0f, 76.0f));
	position.push_back(Vector2(228.0f, 76.0f));
	position.push_back(Vector2(236.0f, 76.0f));
	position.push_back(Vector2(244.0f, 76.0f));
	position.push_back(Vector2(252.0f, 76.0f));

	for (int i = 0; i < 32; i++)
	{
		shared_ptr<BrickWall> brick = make_shared<BrickWall>();
		brick->GetQuad()->GetTransform()->SetPos(position[i]);
		_bricks.push_back(brick);
	}
}

TestScene::~TestScene()
{
}

void TestScene::Update()
{
	_headQuarter->Update();
	for (auto brick : _bricks)
		brick->Update();
	_player->Update();
}

void TestScene::PreRender()
{
	_backGround->Render();
}

void TestScene::Render()
{
	_headQuarter->Render();
	for (auto brick : _bricks)
		brick->Render();
	_player->Render();
}

void TestScene::Save()
{
}

void TestScene::Load()
{
}
