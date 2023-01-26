#pragma once

struct Vertex_Basic
{
    Vertex_Basic()
    {
    }

    Vertex_Basic(float x, float y)
    {
        this->pos.x = x;
        this->pos.y = y;
    }

    XMFLOAT3 pos = { 0.0f,0.0f,0.0f };
};

struct Vertex_Color
{
    XMFLOAT3 pos;
    XMFLOAT4 color;
};

struct Vertex_UV
{
    XMFLOAT3 pos;
    XMFLOAT2 uv;
};
