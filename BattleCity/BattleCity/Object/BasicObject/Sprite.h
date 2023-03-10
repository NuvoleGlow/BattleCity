#pragma once
class Sprite : public Quad
{
public:
	Sprite(wstring file, Vector2 size);
	Sprite(wstring file, Vector2 size, Vector2 maxFrame);

	virtual void Update() override;
	virtual void Render() override;

	void SetSpriteByFrame(Vector2 curFrame);
	void SetSpriteAction(const Action::Clip& clip);

private:
	shared_ptr<ActionBuffer> _actionBuffer;

	Vector2 _maxFrame = { 1.0f, 1.0f };
};
