#pragma once
class UTiltleLevel3
{
public:
	// constrcuter destructer
	UTiltleLevel3();
	~UTiltleLevel3();

	// delete Function
	UTiltleLevel3(const UTiltleLevel3& _Other) = delete;
	UTiltleLevel3(UTiltleLevel3&& _Other) noexcept = delete;
	UTiltleLevel3& operator=(const UTiltleLevel3& _Other) = delete;
	UTiltleLevel3& operator=(UTiltleLevel3&& _Other) noexcept = delete;

protected:

private:

};

