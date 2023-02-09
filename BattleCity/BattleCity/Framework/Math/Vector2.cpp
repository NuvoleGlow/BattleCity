#include "framework.h"
#include "Vector2.h"

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

Vector2 Vector2::operator*(const float& value) const
{
    return Vector2(x * value, y * value);
}

Vector2& Vector2::operator*=(const float& value)
{
    x *= value;
    y *= value;
    
    return *this;
}

Vector2 Vector2::operator/(const float& value) const
{
    return Vector2(x / value, y / value);
}

bool Vector2::operator==(const Vector2& other) const
{
    if (x != other.x)
        return false;
    if (y != other.y)
        return false;

    return true;
}

bool Vector2::operator!=(const Vector2& other) const
{
    if (x != other.x)
        return true;
    if (y != other.y)
        return true;

    return false;
}

bool Vector2::operator>(const Vector2& other) const
{
    if (y != other.y)
        return y > other.y;

    return x > other.x;
}

bool Vector2::operator<(const Vector2& other) const
{
    if (y != other.y)
        return y < other.y;

    return x < other.x;
}

float Vector2::Dot(const Vector2& other)
{
    return x * other.x + y * other.y;
}

float Vector2::Cross(const Vector2& other)
{
    return x * other.y - y * other.x;
}

bool Vector2::IsBetween(const Vector2& vector1, const Vector2& vector2)
{
    Vector2 endLine = vector1 - *(this);
    Vector2 startLine = vector2 - *(this);

    float between = endLine.Cross(*this) * startLine.Cross(*this);

    return between < 0.0f;
}

float Vector2::Length() const
{
    return sqrt(powf(x, 2) + powf(y, 2));
}

float Vector2::Length(const Vector2& other) const
{
    Vector2 temp = (*this) - other;
    return temp.Length();
}

void Vector2::Normallize()
{
    float length = this->Length();
    x /= length;
    y /= length;
}

Vector2 Vector2::Normal() const
{
    float length = this->Length();

    return Vector2(x / length, y / length);
}

float Vector2::Angle() const
{
    return atan2(y, x);
}

void Vector2::Angle(const float& angle)
{
    x = x * cos(angle);
    y = y * sin(angle);
}

int Vector2::Manhattan(const Vector2& other)
{
    return (int)(other.x - x) + (int)(other.y - y);
}

Vector2 Vector2::TransformCoord(const Vector2& vector, const XMMATRIX& matrix)
{
    XMVECTOR temp = XMLoadFloat2(&vector);
    
    temp = XMVector2TransformCoord(temp, matrix);

    Vector2 result;
    XMStoreFloat2(&result, temp);

    return result;
}
