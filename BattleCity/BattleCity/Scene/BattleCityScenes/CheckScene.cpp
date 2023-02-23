#include "framework.h"

#include "Object/GameObject/Frame.h"
#include "Object/GameObject/PlayerTank.h"

#include "CheckScene.h"

CheckScene::CheckScene()
{
	Init();
}

CheckScene::~CheckScene()
{
}

void CheckScene::Update()
{
	for (auto collider : _backGround->GetColliders())
	{
		collider->Block(_player->GetCollider());
	}
	_player->Update();
	_backGround->Update();

	if (KEY_UP(VK_SPACE))
	{
		SCENE->ChangeScene((_stageCount % 3) + 1);
	}
}

void CheckScene::PreRender()
{
	_backGround->PreRender();
}

void CheckScene::Render()
{
}

void CheckScene::PostRender()
{
	_player->PostRender();
	_backGround->PostRender();
}

void CheckScene::Init()
{
	_backGround = make_shared<Frame>();
	_player = make_shared<PlayerTank>();
	Load_Score();
	Load_HP();

	_curScore = _backGround->GetScore();
	_stageCount = (_curScore - _preScore) / 25;
	Save_E();
	_preScore = _backGround->GetScore();
}

void CheckScene::Load_Score()
{
	BinaryReader reader = BinaryReader(L"Save/Score.sc");
	int sc = reader.Int();
	_backGround->AddScore(sc);
}

void CheckScene::Load_HP()
{
	BinaryReader reader = BinaryReader(L"Save/HP.hp");
	int hp = reader.Int();
	_player->SetHP(hp);
}

void CheckScene::Save_E()
{
	BinaryWriter writer = BinaryWriter(L"Save/E.max");

	int number = (_stageCount + 1) * 5;
	if (number >= 20)
		number = 20;

	writer.Int(number);
}
