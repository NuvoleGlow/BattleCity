#pragma once
class Numbers
{
public:
	Numbers(float curNumber);
	~Numbers();

	void Update();
	void Render();

	void SetNumber(float curNumber);

	shared_ptr<Sprite> GetSprite() { return _sprite; }

private:
	shared_ptr<Sprite> _sprite;
	Vector2 _curframe;
};

