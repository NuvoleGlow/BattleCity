Texture2D map :register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	input.uv.x = abs(input.uv.x);
	float4 result = map.Sample(samp, input.uv);

	return result;
}
