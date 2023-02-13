cbuffer Frame : register(b0)
{
	float2 startPos;
	float2 imageSize;
	float2 size;
	float2 padding;
}

Texture2D map : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	float2 spriteUV;
	spriteUV.x = abs(input.uv.x) * (size.x / imageSize.x) + (startPos.x / imageSize.x);
	spriteUV.y = input.uv.y * (size.y / imageSize.y) + (startPos.y / imageSize.y);

	float4 result = map.Sample(samp, spriteUV);

	if (result.x + result.y + result.z < 0.1f)
		result.w = 0.0f;

	return result;
}
