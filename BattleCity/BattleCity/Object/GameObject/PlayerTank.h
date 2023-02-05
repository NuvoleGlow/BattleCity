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

	shared_ptr<Sprite> GetSprite() { return _sprite; }
	shared_ptr<Bullet> GetBullet();
	shared_ptr<Collider> GetCollider() { return _collider; }

	bool CheckAlive();
	bool IsCollision_Bullet(shared_ptr<class Bullet> bullet);
	bool isActive = true;

private:
	shared_ptr<Transform> _firePos;
	shared_ptr<Collider> _collider;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Bullet> _bullet;

	float _speed = 64.0f;
	int _hp = 1;
};
