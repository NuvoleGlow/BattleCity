#pragma once

class Frame;
class HeadQuarter;
class Brick;
class Concrete;
class Grass;
class PlayerTank;
class EnemyTank;

class Stage2 : public Scene
{
public:
	Stage2();
	virtual ~Stage2();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void CreateTank();

	void Load_E();
	void Load_B();
	void Load_C();
	void Load_G();
	void Load_HP();
	void Save_HP();
	void Save_Score();
	void Load_Score();

	virtual void Init() override;

	bool GameEnd();
	bool StageClear();

private:
	shared_ptr<HeadQuarter> _headQuarter;
	shared_ptr<Frame> _backGround;
	shared_ptr<PlayerTank> _player;
	vector<shared_ptr<Brick>> _bricks;
	vector<shared_ptr<Concrete>> _concretes;
	vector<shared_ptr<EnemyTank>> _tanks;
	vector<shared_ptr<Grass>> _grasses;

	int _max = 0;
	const float _createDelay = 5.0f;
	float _createCheck = 0.0f;
	int _count = 0;
};
