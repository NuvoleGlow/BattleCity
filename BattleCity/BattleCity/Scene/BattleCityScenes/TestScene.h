#pragma once

class HeadQuarter;
class BrickWall;
class Frame;
class Tank;

class TestScene : public Scene
{
public:
	TestScene();
	virtual ~TestScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;

	void Save();
	void Load();
	
private:
	shared_ptr<HeadQuarter> _headQuarter;
	shared_ptr<Frame> _backGround;
	vector<shared_ptr<BrickWall>> _bricks;
	shared_ptr<Tank> _player;

	vector<vector<bool>> _apexs;
};
