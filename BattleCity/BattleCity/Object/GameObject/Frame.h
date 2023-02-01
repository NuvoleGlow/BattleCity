#pragma once
class Frame
{
public:
	Frame();
	~Frame();

	void Update();
	void Render();

private:
	shared_ptr<Quad> _frame;
	shared_ptr<Quad> _field;

};

