#pragma once
class Camera
{
private:
	Camera();
	~Camera();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Camera();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Camera* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void Update();
	void PostRender();

	void SetViewPort(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
	void SetProjectionBuffer(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
	void SetCameraWorldBuffer() { _transform->SetWorldBuffer(1); }
	void SetUICameraBuffer() { _uiCameraBuffer->SetVSBuffer(1); }

	Vector2 GetWorldMousePos();

private:

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _moveTransform;

	shared_ptr<MatrixBuffer> _projectionBuffer;
	shared_ptr<MatrixBuffer> _uiCameraBuffer;

	static Camera* _instance;
};
