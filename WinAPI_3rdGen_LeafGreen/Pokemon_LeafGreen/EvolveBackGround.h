#pragma once
class AEvolveBackGround
{
public:
	// constrcuter destructer
	AEvolveBackGround();
	~AEvolveBackGround();

	// delete Function
	AEvolveBackGround(const AEvolveBackGround& _Other) = delete;
	AEvolveBackGround(AEvolveBackGround&& _Other) noexcept = delete;
	AEvolveBackGround& operator=(const AEvolveBackGround& _Other) = delete;
	AEvolveBackGround& operator=(AEvolveBackGround&& _Other) noexcept = delete;

protected:

private:

};

