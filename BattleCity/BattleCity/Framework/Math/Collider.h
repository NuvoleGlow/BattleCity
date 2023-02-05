#pragma once

class CircleCollider;

class Collider
{
public:
	enum class ColliderType
	{
		NONE,
		CIRCLE
	};

	Collider();
	~Collider();

	virtual void Update();
	virtual void Render();

	void SetRED();
	void SetGREEN();

	shared_ptr<Transform> GetTransform() { return _transform; }

	virtual bool IsCollision(shared_ptr<Collider> col);
	virtual bool Block(shared_ptr<Collider> other);

	virtual bool IsCollision(Vector2 pos) abstract;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) abstract;
	virtual bool Block(shared_ptr<CircleCollider> other) abstract;

	ColliderType GetType() { return _type; }

	bool isActive = true;
	static bool isDebug;

protected:
	virtual void CreateData();

	ColliderType _type = ColliderType::NONE;

	vector<Vertex_Basic> _vertices;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<Transform> _transform;
};
