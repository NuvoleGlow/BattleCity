#pragma once

class HeadQuarter;
class Brick;
class Frame;
class PlayerTank;
class Bullet;
class Concrete;
class Grass;

class TestScene : public Scene
{
public:
	TestScene();
	virtual ~TestScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;

	virtual void NextScene() override;

	void Save_B();
	void Save_C();
	void Save_G();
	
	bool debug = false;

private:
	shared_ptr<HeadQuarter> _headQuarter;
	shared_ptr<Frame> _backGround;

	vector<shared_ptr<Brick>> _bricks;
	vector<shared_ptr<Concrete>> _concretes;
	vector<shared_ptr<Grass>> _grasses;
};
