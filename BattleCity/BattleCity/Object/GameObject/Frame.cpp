#include "framework.h"

#include "Object/UserInterface/Numbers.h"

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

	vector<Vector2> post;
	post.push_back(Vector2(24.0f, 24.0f));
	post.push_back(Vector2(24.0f, 456.0f));
	post.push_back(Vector2(456.0f, 24.0f));
	post.push_back(Vector2(456.0f, 456.0f));


	post.push_back(Vector2(24.0f, 40.0f));
	post.push_back(Vector2(24.0f, 56.0f));
	post.push_back(Vector2(24.0f, 72.0f));
	post.push_back(Vector2(24.0f, 88.0f));
	post.push_back(Vector2(24.0f, 104.0f));
	post.push_back(Vector2(24.0f, 120.0f));
	post.push_back(Vector2(24.0f, 136.0f));
	post.push_back(Vector2(24.0f, 152.0f));
	post.push_back(Vector2(24.0f, 168.0f));
	post.push_back(Vector2(24.0f, 184.0f));
	post.push_back(Vector2(24.0f, 200.0f));
	post.push_back(Vector2(24.0f, 216.0f));
	post.push_back(Vector2(24.0f, 232.0f));
	post.push_back(Vector2(24.0f, 248.0f));
	post.push_back(Vector2(24.0f, 264.0f));
	post.push_back(Vector2(24.0f, 280.0f));
	post.push_back(Vector2(24.0f, 296.0f));
	post.push_back(Vector2(24.0f, 312.0f));
	post.push_back(Vector2(24.0f, 328.0f));
	post.push_back(Vector2(24.0f, 344.0f));
	post.push_back(Vector2(24.0f, 360.0f));
	post.push_back(Vector2(24.0f, 376.0f));
	post.push_back(Vector2(24.0f, 392.0f));
	post.push_back(Vector2(24.0f, 408.0f));
	post.push_back(Vector2(24.0f, 424.0f));
	post.push_back(Vector2(24.0f, 440.0f));


	post.push_back(Vector2(40.0f, 24.0f));
	post.push_back(Vector2(56.0f, 24.0f));
	post.push_back(Vector2(72.0f, 24.0f));
	post.push_back(Vector2(88.0f, 24.0f));
	post.push_back(Vector2(104.0f, 24.0f));
	post.push_back(Vector2(120.0f, 24.0f));
	post.push_back(Vector2(136.0f, 24.0f));
	post.push_back(Vector2(152.0f, 24.0f));
	post.push_back(Vector2(168.0f, 24.0f));
	post.push_back(Vector2(184.0f, 24.0f));
	post.push_back(Vector2(200.0f, 24.0f));
	post.push_back(Vector2(216.0f, 24.0f));
	post.push_back(Vector2(232.0f, 24.0f));
	post.push_back(Vector2(248.0f, 24.0f));
	post.push_back(Vector2(264.0f, 24.0f));
	post.push_back(Vector2(280.0f, 24.0f));
	post.push_back(Vector2(296.0f, 24.0f));
	post.push_back(Vector2(312.0f, 24.0f));
	post.push_back(Vector2(328.0f, 24.0f));
	post.push_back(Vector2(344.0f, 24.0f));
	post.push_back(Vector2(360.0f, 24.0f));
	post.push_back(Vector2(376.0f, 24.0f));
	post.push_back(Vector2(392.0f, 24.0f));
	post.push_back(Vector2(408.0f, 24.0f));
	post.push_back(Vector2(424.0f, 24.0f));
	post.push_back(Vector2(440.0f, 24.0f));


	post.push_back(Vector2(456.0f, 40.0f));
	post.push_back(Vector2(456.0f, 56.0f));
	post.push_back(Vector2(456.0f, 72.0f));
	post.push_back(Vector2(456.0f, 88.0f));
	post.push_back(Vector2(456.0f, 104.0f));
	post.push_back(Vector2(456.0f, 120.0f));
	post.push_back(Vector2(456.0f, 136.0f));
	post.push_back(Vector2(456.0f, 152.0f));
	post.push_back(Vector2(456.0f, 168.0f));
	post.push_back(Vector2(456.0f, 184.0f));
	post.push_back(Vector2(456.0f, 200.0f));
	post.push_back(Vector2(456.0f, 216.0f));
	post.push_back(Vector2(456.0f, 232.0f));
	post.push_back(Vector2(456.0f, 248.0f));
	post.push_back(Vector2(456.0f, 264.0f));
	post.push_back(Vector2(456.0f, 280.0f));
	post.push_back(Vector2(456.0f, 296.0f));
	post.push_back(Vector2(456.0f, 312.0f));
	post.push_back(Vector2(456.0f, 328.0f));
	post.push_back(Vector2(456.0f, 344.0f));
	post.push_back(Vector2(456.0f, 360.0f));
	post.push_back(Vector2(456.0f, 376.0f));
	post.push_back(Vector2(456.0f, 392.0f));
	post.push_back(Vector2(456.0f, 408.0f));
	post.push_back(Vector2(456.0f, 424.0f));
	post.push_back(Vector2(456.0f, 440.0f));


	post.push_back(Vector2(40.0f, 456.0f));
	post.push_back(Vector2(56.0f, 456.0f));
	post.push_back(Vector2(72.0f, 456.0f));
	post.push_back(Vector2(88.0f, 456.0f));
	post.push_back(Vector2(104.0f, 456.0f));
	post.push_back(Vector2(120.0f, 456.0f));
	post.push_back(Vector2(136.0f, 456.0f));
	post.push_back(Vector2(152.0f, 456.0f));
	post.push_back(Vector2(168.0f, 456.0f));
	post.push_back(Vector2(184.0f, 456.0f));
	post.push_back(Vector2(200.0f, 456.0f));
	post.push_back(Vector2(216.0f, 456.0f));
	post.push_back(Vector2(232.0f, 456.0f));
	post.push_back(Vector2(248.0f, 456.0f));
	post.push_back(Vector2(264.0f, 456.0f));
	post.push_back(Vector2(280.0f, 456.0f));
	post.push_back(Vector2(296.0f, 456.0f));
	post.push_back(Vector2(312.0f, 456.0f));
	post.push_back(Vector2(328.0f, 456.0f));
	post.push_back(Vector2(344.0f, 456.0f));
	post.push_back(Vector2(360.0f, 456.0f));
	post.push_back(Vector2(376.0f, 456.0f));
	post.push_back(Vector2(392.0f, 456.0f));
	post.push_back(Vector2(408.0f, 456.0f));
	post.push_back(Vector2(424.0f, 456.0f));
	post.push_back(Vector2(440.0f, 456.0f));

	for (int i = 0; i < post.size(); i++)
	{
		shared_ptr<Collider> collider = make_shared<CircleCollider>(8.0f);
		collider->GetTransform()->SetPos(post[i]);
		_colliders.push_back(collider);
	}

	int score = _score;
	for (int i = 0; i < 3; i++)
	{
		int ten = pow(10, i + 1);
		float num = score % ten;
		shared_ptr<Numbers> number = make_shared<Numbers>(num);
		score /= 10;
		Vector2 pos = { 496.0f - i * 16.0f, 48.0f };
		number->GetSprite()->GetTransform()->SetPos(pos);
		_scoreNumbers.push_back(number);
	}
}

Frame::~Frame()
{
}

void Frame::Update()
{
	for (auto collider : _colliders)
	{
		collider->Update();
	}
	CountScore();
}

void Frame::PreRender()
{
	_frame->Render();
	_field->Render();
}

void Frame::PostRender()
{
	for (int i = 0; i < 3; i++)
	{
		_scoreNumbers[i]->Render();
	}
}

void Frame::CountScore()
{
	int score = _score;
	for (int i = 0; i < 3; i++)
	{
		int ten = pow(10, i + 1);
		float num = score % ten;
		_scoreNumbers[i]->SetNumber(num);
		score /= 10;
		_scoreNumbers[i]->Update();
	}
}
