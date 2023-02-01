#pragma once

class Bullet;

class Tank
{
public:
	Tank();
	~Tank();

	void CreateAction(wstring file, float speed = 0.1f, Action::Type = Action::Type::LOOP);

	void Init();
	void Input();
	void Update();
	void Render();

	void Shot();

	bool isActive = true;

private:
	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _firePos;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;
	shared_ptr<Bullet> _bullet;

	float _speed = 64.0f;
};

