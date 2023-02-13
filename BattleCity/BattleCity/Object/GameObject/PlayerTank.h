#pragma once

class Brick;
class Bullet;
class Concrete;
class EnemyTank;
class HeadQuarter;
class HPCount;

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
	void PostRender();

	void Shot();
	void CheckAlive();
	bool Attack_E(shared_ptr<EnemyTank> enemy);
	void Attack_B(shared_ptr<Brick> brick);
	void Attack_C(shared_ptr<Concrete> concrete);
	void Attack_H(shared_ptr<HeadQuarter> headQuarter);

	int& GetHP() { return _hp; }
	void SetHP(int hp) { _hp = hp; }
	shared_ptr<Sprite> GetSprite() { return _sprite; }
	shared_ptr<Collider> GetCollider() { return _collider; }

	bool isActive = true;

private:
	shared_ptr<Transform> _firePos;
	shared_ptr<Collider> _collider;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Bullet> _bullet;
	vector<shared_ptr<HPCount>> _lifeCount;

	float _speed = 64.0f;
	int _score = 0;
	int _hp = 3;
};
