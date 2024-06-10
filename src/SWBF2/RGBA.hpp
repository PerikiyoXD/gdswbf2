// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <cstdint>

namespace SWBF2
{
    class RGBA {
    public:
        struct rgba { uint8_t r, g, b, a; };

        union
        {
            rgba color;
            uint32_t color32;
        };

        RGBA() : color{ 0 } {}
        RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
            : color{ r, g, b, a }
        {}

        bool operator==(const RGBA &right)
        {
            return this->color.r == right.color.r && this->color.g == right.color.g && this->color.b == right.color.b && this->color.a == right.color.a;
        }

        bool operator!=(const RGBA &right)
        {
            return !(*this == right);
        }

        RGBA &operator=(const RGBA &right)
        {
            this->color.r = right.color.r;
            this->color.g = right.color.g;
            this->color.b = right.color.b;
            this->color.a = right.color.a;
            return *this;
        }
    };
}
