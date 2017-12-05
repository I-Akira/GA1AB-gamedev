//CPU����擾���钸�_���\����
struct vertexIn
{
	float4 pos	:	POSITION;
	float4 col	:	COLOR;
	float2 uv	:	UV;
};

//VS����PS�ɑ�����
struct vertexOut
{
	//���_���̓��X�^���C�Y�Ŏg�p
	float4 pos	:	SV_POSITION;
	//�ȉ�PS�Ŏg�p����
	float4 col	:	COLOR;
	float2 uv	:	UV;

};

//�O���[�o��
cbuffer global
{
	float4 color;
	float4 pos;
	float4 scale;
	float4 rotation;
	float4 texsize;
};

//�e�N�X�`�����
Texture2D		txDiffuse	:	register(t0);//�e�N�X�`���O���t�B�b�N
SamplerState	samLinear	:	register(s0);//�e�N�X�`���T���v��

											 //���_�V�F�[�_
											 //�����@�@vertexIn�@:�@CPU����󂯎�钸�_���
											 //�߂�l�@vertexOut :�@PS�ɑ�����
											 //���_�������W�ϊ������邪����͕ϊ������ĂȂ��B
vertexOut vs(vertexIn IN)
{
	vertexOut OUT;
	float2 p;

	//���_�Ƀ|���S���̒��S���ړ�������
	p.x = IN.pos.x - 0.5f;
	p.y = IN.pos.y - 0.5f;

	//�|���S�����g�傳����
	p.x = p.x * scale.x * texsize.x / 400.0f;
	p.y = p.y * scale.y * texsize.y / 300.0f;

	//�|���S�������_�𒆐S�ɉ�]
	float r = 3.14f / 180.0f*rotation.x;
	OUT.pos.x = p.x*cos(r) - p.y*sin(r)*3.0f / 4.0f;
	OUT.pos.y = p.y*cos(r) + p.x*sin(r)*4.0f / 3.0f;

	//�|���S�������̈ʒu�Ɉړ�������
	OUT.pos.x += 0.5f * scale.x*texsize.x / 400.0f;
	OUT.pos.y += 0.5f * scale.y*texsize.y / 300.0f;

	//2D���W�ւ̕ϊ�
	OUT.pos.x = +(OUT.pos.x) - 1.0f;
	OUT.pos.y = -(OUT.pos.y) + 1.0f;

	//���s�ړ�
	OUT.pos.x += (pos.x / 400.0f);
	OUT.pos.y += (-pos.y / 300.0f);

	//�c���IN����OUT�ւ��̂܂�
	OUT.pos.zw = IN.pos.zw;	//���_
	OUT.col = IN.col;	//�F
	OUT.uv = IN.uv;	//�t�u

	return OUT;
}

//�s�N�Z���V�F�[�_
//����		vertexOut�@�FVS���瑗���Ă������
//�߂�l	float4�@�@ �FColor�l
//���������񌳂ɐF�����߂�B����͒��_�����F�ƃO���[�o��
//���玝���Ă����F����Z�B
float4 ps(vertexOut IN) :SV_Target
{
	float4 col = IN.col*color;
	//UV����e�N�X�`���̐F�̒l���擾
	float4 tex = txDiffuse.Sample(samLinear, IN.uv);

	//col�Ƀe�N�X�`���̐F����
	col *= tex;


	return col;
}