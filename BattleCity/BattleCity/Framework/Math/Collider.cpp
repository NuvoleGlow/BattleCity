#include "framework.h"
#include "Collider.h"

bool Collider::isDebug = true;

Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::Update()
{
    if (isActive == false)
        return;

    _transform->Update();
    _colorBuffer->Update();
}

void Collider::Render()
{
    if (isActive == false || isDebug == false)
        return;

    _transform->SetWorldBuffer();
    _colorBuffer->SetPSBuffer(0);

    _vertexBuffer->IASet(0);

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->Set();
    _ps->Set();

    DC->Draw(_vertices.size(), 0);
}

void Collider::SetRED()
{
    _colorBuffer->_data.color = { 255,0,0,1.0f };
}

void Collider::SetGREEN()
{
    _colorBuffer->_data.color = { 0,255,0,1.0f };
}

bool Collider::IsCollision(shared_ptr<Collider> col)
{
    if (isActive == false || col->isActive == false)
        return false;

    switch (col->GetType())
    {
    case ColliderType::NONE:
    {
        break;
    }

    case ColliderType::CIRCLE:
    {
        return IsCollision(dynamic_pointer_cast<CircleCollider>(col));
        break;
    }

    default:
        break;
    }

    return false;
}

bool Collider::Block(shared_ptr<Collider> other)
{
    if (isActive == false)
        return false;

    switch (other->GetType())
    {
    case ColliderType::NONE:
    {
        break;
    }

    case ColliderType::CIRCLE:
    {
        return Block(dynamic_pointer_cast<CircleCollider>(other));
        break;
    }

    default:
        break;
    }

    return false;
}

void Collider::CreateData()
{
    _vs = make_shared<VertexShader>(L"Shaders/Collider/ColliderVertexShader.hlsl");
    _ps = make_shared<PixelShader>(L"Shaders/Collider/ColliderPixelShader.hlsl");

    UINT stride = static_cast<UINT>(sizeof(Vertex_Basic));
    _vertexBuffer = make_shared<VertexBuffer>(&_vertices[0], stride, _vertices.size());
    _colorBuffer = make_shared<ColorBuffer>();

    _transform = make_shared<Transform>();
}
