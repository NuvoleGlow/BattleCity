#pragma once
class PlayerTank
{
public:
	PlayerTank();
	~PlayerTank();

	void CreateAction(wstring file, float speed = 0.1f, Action::Type = Action::Type::LOOP);

	void Input();
	void Init();
	void Update();
	void Render();

	void Shot();
	bool IsCollision_Brick(shared_ptr<class Brick> brick);
	bool IsCollision_Bullet(shared_ptr<class Bullet> bullet);

	shared_ptr<Sprite> GetSprite() { return _sprite; }
	shared_ptr<Bullet> GetBullet();

	bool isActive = true;

private:
	shared_ptr<Transform> _firePos;
	shared_ptr<Collider> _collider;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Bullet> _bullet;

	float _speed = 64.0f;
};
