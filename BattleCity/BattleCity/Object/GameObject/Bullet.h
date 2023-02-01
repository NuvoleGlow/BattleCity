#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	void SetDirection(Vector2 dir);

	bool IsCollision(shared_ptr<Collider> _collider);

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }

	bool isActive = false;

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;

	Vector2 _direction = { 0,0 };
	float _speed = 128.0f;

};

