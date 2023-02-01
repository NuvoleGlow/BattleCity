#pragma once
class Button
{
public:
	enum State
	{
		NONE,
		HOVER,
		CLICK
	};

	Button(wstring path);
	~Button();

	void Update();
	void PostRender();

	void SetPostion(Vector2 pos);
	void SetScale(Vector2 scale);

	void SetEvent(CallBack callBack) { _callBack = callBack; }
	void SetEvent_String(std::function<void(string)> callBack) { _callBack_string = callBack; }

private:
	State _state;

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;
	shared_ptr<ButtonInfoBuffer> _buttonInfoBuffer;

	CallBack _callBack;
	std::function<void(string)> _callBack_string;
};
