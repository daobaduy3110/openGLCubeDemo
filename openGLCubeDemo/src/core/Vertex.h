#pragma once
#include <vector>

class Vertex
{
public:
	std::vector<float> pos;
	std::vector<float> uv;
	std::vector<float> normal;
	std::vector<float> bitangent;
	std::vector<float> tangent;
};