#include "pch.h"
#include "colors.h"

const std::array<float, 4> red = { 1.f, 0.f, 0.f, 1.f };

const std::array<float, 4> colors::green = { 0.f, 1.f, 0.f, 1.f };

const std::array<float, 4> colors::blue = { 0.f, 0.f, 1.f, 1.f };

const std::array<float, 4> colors::yellow = { 0.f, 1.f, 1.f, 1.f };

const std::array<float, 4> colors::magenta = { 1.f, 0.f, 1.f, 1.f };

const std::array<float, 4> colors::orange = { 1.f, 0.5f, 0.f, 1.f };

const std::array<float, 4> colors::pink = { 1.f, 0.5f, 1.f, 1.f };

const std::array<float, 4> colors::purple = { 0.5f, 0.25f, 1.f, 1.f };

const std::array<float, 4> colors::sky_blue = { 0.f, 0.9f, 1.f, 1.f };

const std::array<float, 4> colors::sea_green = { 0.f, 0.9f, 0.6f, 1.f };

const std::array<float, 4> colors::peach = { 0.97f, 0.61f, 0.41f, 1.f };

const std::array<float, 4> colors::indigo = { 0.67f, 0.61f, 1.f, 1.f };

std::array<float, 4>* colors::get_colors()
{
	return nullptr;
}

std::array<float, 4>* colors::get_colors(UINT count)
{
	return nullptr;
}

std::array<float, 4>* colors::get_random_colors()
{
	return nullptr;
}

std::array<float, 4>* colors::get_random_colors(UINT count)
{
	return nullptr;
}
