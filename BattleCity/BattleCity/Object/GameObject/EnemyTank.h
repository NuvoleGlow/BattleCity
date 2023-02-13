#pragma once

class Brick;
class Concrete;
class PlayerTank;
class HeadQuarter;

class EnemyTank
{
public:
	EnemyTank();
	~EnemyTank();

	void CreateAction(wstring file, float speed = 0.1f, Action::Type = Action::Type::LOOP);

	void Input();
	void Init();
	void Update();
	void Render();

	void Shot();
	void CheckAlive();
	void Attack_P(shared_ptr<PlayerTank> player);
	void Attack_B(shared_ptr<Brick> brick);
	void Attack_C(shared_ptr<Concrete> concrete);
	void Attack_E(shared_ptr<EnemyTank> enemy);
	void Attack_H(shared_ptr<HeadQuarter> headQuarter);

	int& GetHP() { return _hp; }
	shared_ptr<Sprite> GetSprite() { return _sprite; }
	shared_ptr<Collider> GetCollider() { return _collider; }

	bool isActive = false;

private:
	shared_ptr<Transform> _firePos;
	shared_ptr<Collider> _collider;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Bullet> _bullet;

	vector<Vector2> _path;
	Vector2 _dir = { 0.0f, 0.0f };
	float _speed = 64.0f;
	int _hp = 1;

	const float _fireDelay = 2.0f;
	float _fireCheck = 0.0f;

	const float _moveDelay = 2.5f;
	float _moveCheck = 0.0f;

	const float _autoDelay = 6.0f;
	float _autoCheck = 0.0f;
};
