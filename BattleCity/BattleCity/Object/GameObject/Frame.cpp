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
