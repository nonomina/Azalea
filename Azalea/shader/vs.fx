//入力用
struct vertexIn
{
	float4 pos : POSITION0;
	float4 col : COLOR0;
	float2 tex : TEXCOORD0;//テクスチャ座標
};

//出力用
struct vertexOut
{
	float4 pos : SV_POSITION;
	float4 col : COLOR;
	float2 tex : TEXCOORD0;//テクスチャ座標
};

//変換用行列
cbuffer ConstantBuffer : register(b0)
{
	matrix World;		//ワールド変換行列
	matrix View;		//ビュー変換行列
	matrix Projection;	//透視射影変換行列
}

vertexOut vs_main(vertexIn IN)
{
	vertexOut OUT;

	//OUT.pos = IN.pos;
	OUT.pos = mul(IN.pos, World);		//ワールド変換
	OUT.pos = mul(OUT.pos, View);		//ビュー変換
	OUT.pos = mul(OUT.pos, Projection);	//透視射影変換

	OUT.col = IN.col;
	OUT.tex = IN.tex;//テクスチャ座標

	return OUT;
}