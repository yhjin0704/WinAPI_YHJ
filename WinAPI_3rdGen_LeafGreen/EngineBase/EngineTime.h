#pragma once
#include <Windows.h>

class EngineTime
{
public:
	// constrcuter destructer
	EngineTime();
	~EngineTime();

	// delete Function
	EngineTime(const EngineTime& _Other) = delete;
	EngineTime(EngineTime&& _Other) noexcept = delete;
	EngineTime& operator=(const EngineTime& _Other) = delete;
	EngineTime& operator=(EngineTime&& _Other) noexcept = delete;

	// 시간측정 시작.
	void TimeCheckStart();

	// 지난 시간 체크.
	float TimeCheck();

	double GetDeltaTime()
	{
		return DeltaTime;
	}

protected:

private:
	__int64 Count64;
	LARGE_INTEGER Count;
	LARGE_INTEGER PrevTime;
	LARGE_INTEGER CurTime;
	double dCount;
	double DeltaTime;
};

