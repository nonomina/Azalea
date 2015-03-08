//���͗p
struct vertexIn
{
	float4 pos : POSITION0;
	float4 col : COLOR0;
	float2 tex : TEXCOORD0;//�e�N�X�`�����W
};

//�o�͗p
struct vertexOut
{
	float4 pos : SV_POSITION;
	float4 col : COLOR;
	float2 tex : TEXCOORD0;//�e�N�X�`�����W
};

//�ϊ��p�s��
cbuffer ConstantBuffer : register(b0)
{
	matrix World;		//���[���h�ϊ��s��
	matrix View;		//�r���[�ϊ��s��
	matrix Projection;	//�����ˉe�ϊ��s��
}

vertexOut vs_main(vertexIn IN)
{
	vertexOut OUT;

	//OUT.pos = IN.pos;
	OUT.pos = mul(IN.pos, World);		//���[���h�ϊ�
	OUT.pos = mul(OUT.pos, View);		//�r���[�ϊ�
	OUT.pos = mul(OUT.pos, Projection);	//�����ˉe�ϊ�

	OUT.col = IN.col;
	OUT.tex = IN.tex;//�e�N�X�`�����W

	return OUT;
}