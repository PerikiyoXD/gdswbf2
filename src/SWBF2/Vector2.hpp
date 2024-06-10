// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

namespace SWBF2
{
    template <typename T>
    class Vector2 {
    public:
        T x, y;

        Vector2() : x(0), y(0) {}
        Vector2(T x, T y)
        {
            this->x = x;
            this->y = y;
        }

        Vector2 operator+(T right) {
            return Vector2(this->x + right, this->y + right);
        }

        Vector2 operator-(T right) {
            return Vector2(this->x - right, this->y - right);
        }

        Vector2 operator*(T right) {
            return Vector2(this->x * right, this->y * right);
        }

        Vector2 operator/(T right) {
            return Vector2(this->x / right, this->y / right);
        }
    };
}
