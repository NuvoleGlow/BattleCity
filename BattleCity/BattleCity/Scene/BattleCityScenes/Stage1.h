#pragma once

class HeadQuarter;
class Brick;
class Frame;
class PlayerTank;
class Concrete;

class Stage1 : public Scene
{
public:
	Stage1();
	virtual ~Stage1();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;

	virtual void NextScene() override;

	void Load_B();
	void Load_C();
	void Load_G();


private:
	shared_ptr<HeadQuarter> _headQuarter;
	shared_ptr<Frame> _backGround;
	shared_ptr<PlayerTank> _player;
	vector<shared_ptr<Brick>> _bricks;
	vector<shared_ptr<Concrete>> _concretes;

	bool debug = false;
};

