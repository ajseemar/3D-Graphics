struct color {
	float r, g, b, a;
};

cbuffer ConstantBuffer {
	color c;
};

float4 main() : SV_TARGET
{
	return float4(c.r, c.g, c.b, c.a);
}