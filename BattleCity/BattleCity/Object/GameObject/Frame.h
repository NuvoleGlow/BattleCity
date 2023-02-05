#pragma once
class Frame
{
public:
	Frame();
	~Frame();

	void Update();
	void Render();

	Vector2 GetspawnPoint(int number) { return _spawnPoint[number % 3]->GetWorldPos(); }

private:
	shared_ptr<Quad> _frame;
	shared_ptr<Quad> _field;
	vector<shared_ptr<Transform>> _spawnPoint;

};

