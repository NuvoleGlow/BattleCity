#pragma once

class Brick;
class Bullet;
class Concrete;
class EnemyTank;
class HeadQuarter;

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
	void Attack_E(shared_ptr<EnemyTank> enemy);
	void Attack_B(shared_ptr<Brick> brick);
	void Attack_C(shared_ptr<Concrete> concrete);
	void Attack_H(shared_ptr<HeadQuarter> headQuarter);

	int& MinusHP() { return _hp -= 1; }
	shared_ptr<Sprite> GetSprite() { return _sprite; }
	shared_ptr<Collider> GetCollider() { return _collider; }

	bool CheckAlive();
	bool isActive = true;

private:
	shared_ptr<Transform> _firePos;
	shared_ptr<Collider> _collider;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Bullet> _bullet;

	float _speed = 64.0f;
	int _hp = 3;
};
