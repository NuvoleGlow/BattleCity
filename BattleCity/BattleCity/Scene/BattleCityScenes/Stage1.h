#pragma once

class HeadQuarter;
class Brick;
class Frame;
class PlayerTank;
class Concrete;
class EnemyTank;

class Stage1 : public Scene
{
public:
	Stage1();
	virtual ~Stage1();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

	virtual void Init() override;

	void CreateTank();

	void Save_Score();
	void Save_HP();
	void Load_B();
	void Load_C();
	void Load_E();

	bool GameEnd();
	bool StageClear();

private:
	shared_ptr<HeadQuarter> _headQuarter;
	shared_ptr<Frame> _backGround;
	shared_ptr<PlayerTank> _player;
	vector<shared_ptr<Brick>> _bricks;
	vector<shared_ptr<Concrete>> _concretes;
	vector<shared_ptr<EnemyTank>> _tanks;

	int _max = 0;
	const float _createDelay = 5.0f;
	float _createCheck = 0.0f;
	int _count = 0;
};
