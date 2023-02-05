#pragma once
class CircleCollider : public Collider
{
public:
	CircleCollider();
	CircleCollider(float radius);
	~CircleCollider();

	const float& GetRadius() { return _radius; }
	void SetRadius(const float& value) { _radius = value; }

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;

	virtual bool Block(shared_ptr<CircleCollider> other) override;

	float GetWorldRadius();

private:
	void CreateVertices();
	float _radius = 0.0f;
};
