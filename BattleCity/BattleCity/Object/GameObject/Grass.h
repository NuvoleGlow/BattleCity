#pragma once
class Grass
{
public:
	Grass();
	~Grass();

	void Update();
	void Render();

	shared_ptr<Quad> GetQuad() { return _quad; }

private:
	shared_ptr<Quad> _quad;
};
