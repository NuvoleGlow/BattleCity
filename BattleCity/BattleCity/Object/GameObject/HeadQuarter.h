#pragma once

class Bullet;

class HeadQuarter
{
public:
	HeadQuarter();
	~HeadQuarter();

	void Update();
	void Render();

	shared_ptr<Quad> GetQuad() { return _quad; }

	bool IsCollision_Bullet(shared_ptr<Bullet> bullet);

	bool isActive = true;

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;
};

