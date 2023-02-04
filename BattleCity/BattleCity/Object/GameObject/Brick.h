#pragma once

class Bullet;

class Brick
{
public:
	Brick();
	~Brick();

	void Update();
	void Render();

	shared_ptr<Quad> GetQuad() { return _quad; }
	shared_ptr<Collider> GetCollider() { return _collider; }

	bool IsCollision_Bullet(shared_ptr<Bullet> bullet);

	bool isActive = true;

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;

};
