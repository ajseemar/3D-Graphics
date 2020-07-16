#pragma once
#include <array>
class colors
{
public:
	static std::array<float, 4>* get_colors();
	static std::array<float, 4>* get_colors(UINT count);
	static std::array<float, 4>* get_random_colors();
	static std::array<float, 4>* get_random_colors(UINT count);

	static const std::array<float, 4> red;
	static const std::array<float, 4> green;
	static const std::array<float, 4> blue;
	static const std::array<float, 4> yellow;
	static const std::array<float, 4> magenta;
	static const std::array<float, 4> orange;
	static const std::array<float, 4> pink;
	static const std::array<float, 4> purple;
	static const std::array<float, 4> sky_blue;
	static const std::array<float, 4> sea_green;
	static const std::array<float, 4> peach;
	static const std::array<float, 4> indigo;
};

