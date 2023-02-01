#pragma once
class HeadQuarter
{
public:
	HeadQuarter();
	~HeadQuarter();

	void Update();
	void Render();

	shared_ptr<Quad> GetQuad() { return _quad; }

	bool isActive = true;

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;
};

