// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

namespace SWBF2
{
    template <typename T>
    class Vector3 {
    public:
        T x, y, z;

        Vector3() : x(0), y(0), z(0) {}
        Vector3(T x, T y, T z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vector3 operator+(T right) {
            return Vector3(this->x + right, this->y + right, this->z + right);
        }

        Vector3 operator-(T right) {
            return Vector3(this->x - right, this->y - right, this->z - right);
        }

        Vector3 operator*(T right) {
            return Vector3(this->x * right, this->y * right, this->z * right);
        }

        Vector3 operator/(T right) {
            return Vector3(this->x / right, this->y / right, this->z / right);
        }

        Vector3 operator+(const Vector3 &right) {
            return Vector3(this->x + right.x, this->y + right.y, this->z + right.z);
        }

        Vector3 operator-(const Vector3 &right) {
            return Vector3(this->x - right.x, this->y - right.y, this->z - right.z);
        }

        Vector3 operator*(const Vector3 &right) {
            return Vector3(this->x * right.x, this->y * right.y, this->z * right.z);
        }

        Vector3 operator/(const Vector3 &right) {
            return Vector3(this->x / right.x, this->y / right.y, this->z / right.z);
        }
    };
}
