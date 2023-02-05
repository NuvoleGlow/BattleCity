#include "framework.h"
#include "Frame.h"

Frame::Frame()
{
	_frame = make_shared<Quad>(L"Resource/Texture/Frame.png", Vector2(512.0f, 480.0f));
	_field = make_shared<Quad>(L"Resource/Texture/Field.png", Vector2(416.0f, 416.0f));

	_frame->GetTransform()->GetPos() = Vector2(256.0f, 240.0f);
	_field->GetTransform()->GetPos() = Vector2(240.0f, 240.0f);

	_frame->Update();
	_field->Update();

	shared_ptr<Transform> point1 = make_shared<Transform>();
	shared_ptr<Transform> point2 = make_shared<Transform>();
	shared_ptr<Transform> point3 = make_shared<Transform>();

	point1->SetPos(Vector2(48.0f, 432.0f));
	_spawnPoint.push_back(point1);
	point2->SetPos(Vector2(240.0f, 432.0f));
	_spawnPoint.push_back(point2);
	point3->SetPos(Vector2(432.0f, 432.0f));
	_spawnPoint.push_back(point3);
}

Frame::~Frame()
{
}

void Frame::Update()
{
}

void Frame::Render()
{
	_frame->Render();
	_field->Render();
}
