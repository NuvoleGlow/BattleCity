#pragma once

class Concrete
{
public:
	Concrete();
	~Concrete();

	void Update();
	void Render();

	shared_ptr<Quad> GetQuad() { return _quad; }
	shared_ptr<Collider> GetCollider() { return _collider; }

	bool isActive = true;

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;

};
