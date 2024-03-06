#pragma once
class AOaksLabDoor
{
public:
	// constrcuter destructer
	AOaksLabDoor();
	~AOaksLabDoor();

	// delete Function
	AOaksLabDoor(const AOaksLabDoor& _Other) = delete;
	AOaksLabDoor(AOaksLabDoor&& _Other) noexcept = delete;
	AOaksLabDoor& operator=(const AOaksLabDoor& _Other) = delete;
	AOaksLabDoor& operator=(AOaksLabDoor&& _Other) noexcept = delete;

protected:

private:

};

