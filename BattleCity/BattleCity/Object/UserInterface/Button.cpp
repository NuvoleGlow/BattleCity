#include "framework.h"
#include "Button.h"

Button::Button(wstring path)
{
	_quad = make_shared<Quad>(path);
	_quad->SetPixelShader(ADD_PS(L"Shaders/PixelShaders/ButtonPixelShader.hlsl"));
	_collider = make_shared<CircleCollider>(10.0f);
	_collider->GetTransform()->SetParent(_quad->GetTransform());

	_buttonInfoBuffer = make_shared<ButtonInfoBuffer>();
	_buttonInfoBuffer->_data.hover = 0.2f;
	_buttonInfoBuffer->_data.click = 0.5f;
}

Button::~Button()
{
}

void Button::Update()
{
	_quad->Update();
	_collider->Update();

	if (_collider->IsCollision(mousePos))
	{
		_state = State::HOVER;
		_buttonInfoBuffer->_data.state = static_cast<int>(_state);

		if (KEY_PRESS(VK_LBUTTON))
		{
			_state = State::CLICK;
			_buttonInfoBuffer->_data.state = static_cast<int>(_state);
			_collider->SetRED();
		}

		if (KEY_UP(VK_LBUTTON))
		{
			if (_callBack != nullptr)
				_callBack();
			if (_callBack_string != nullptr)
				_callBack_string("");
		}
	}
	else
	{
		_state = State::NONE;
		_buttonInfoBuffer->_data.state = static_cast<int>(_state);
		_collider->SetGREEN();
	}

	_buttonInfoBuffer->Update();
}

void Button::PostRender()
{
	_buttonInfoBuffer->SetPSBuffer(1);
	_quad->Render();
	_collider->Render();
}

void Button::SetPostion(Vector2 pos)
{
	_quad->GetTransform()->SetPos(pos);
}

void Button::SetScale(Vector2 scale)
{
	_quad->GetTransform()->SetScale(scale);
}
