#include "framework.h"
#include "Camera.h"

Camera* Camera::_instance = nullptr;

Camera::Camera()
{
	_transform = make_shared<Transform>();
	_moveTransform = make_shared<Transform>();
	_projectionBuffer = make_shared<MatrixBuffer>();
	_uiCameraBuffer = make_shared<MatrixBuffer>();

	SetProjectionBuffer();
}

Camera::~Camera()
{
}

void Camera::Update()
{
	_transform->Update();
}

void Camera::PostRender()
{
}

void Camera::SetViewPort(UINT width, UINT height)
{
	D3D11_VIEWPORT vp;
	vp.Width = width;
	vp.Height = height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	DC->RSSetViewports(1, &vp);
}

void Camera::SetProjectionBuffer(UINT width, UINT height)
{
	XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0.0f, width, 0, height, -1.0f, 1.0f);

	_projectionBuffer->SetData(projectionM);

	_projectionBuffer->SetVSBuffer(2);
}

Vector2 Camera::GetWorldMousePos()
{
	XMMATRIX inverseView = DirectX::XMMatrixInverse(nullptr, *_transform->GetMatrix());

	return Vector2::TransformCoord(mousePos, inverseView);
}
