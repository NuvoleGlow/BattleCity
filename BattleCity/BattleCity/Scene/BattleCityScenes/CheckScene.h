#pragma once

class Frame;
class PlayerTank;

class CheckScene : public Scene
{
public:
	CheckScene();
	virtual ~CheckScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

	virtual void Init() override;

	void Load_Score();
	void Load_HP();
	void Save_E();

private:
	shared_ptr<Frame> _backGround;
	shared_ptr<PlayerTank> _player;
	int _preScore = 0;
	int _curScore = 0;
	int _stageCount = 0;
};

