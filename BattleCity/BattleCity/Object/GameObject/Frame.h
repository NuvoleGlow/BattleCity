#pragma once

class Numbers;

class Frame
{
public:
	Frame();
	~Frame();

	void Update();
	void PreRender();
	void PostRender();

	void CountScore();

	int& GetScore() { return _score; }
	void AddScore(int score) { _score += score; }
	Vector2 GetspawnPoint(int number) { return _spawnPoint[number % 3]->GetWorldPos(); }
	vector<shared_ptr<Collider>> GetColliders() { return _colliders; }

private:
	shared_ptr<Quad> _frame;
	shared_ptr<Quad> _field;
	vector<shared_ptr<Transform>> _spawnPoint;
	vector<shared_ptr<Collider>> _colliders;
	vector<shared_ptr<Numbers>> _scoreNumbers;

	int _score = 0;
};

