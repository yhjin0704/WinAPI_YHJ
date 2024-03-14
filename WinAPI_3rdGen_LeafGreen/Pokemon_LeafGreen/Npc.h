#pragma once
#include "Character.h"
#include "PokemonInfo.h"

class ANpc : public ACharacter
{
public:
	// constrcuter destructer
	ANpc();
	~ANpc();

	// delete Function
	ANpc(const ANpc& _Other) = delete;
	ANpc(ANpc&& _Other) noexcept = delete;
	ANpc& operator=(const ANpc& _Other) = delete;
	ANpc& operator=(ANpc&& _Other) noexcept = delete;

	void SetIsTrainer(bool _OnOff)
	{
		IsTrainer = _OnOff;
	}

	void PushBackEntry(int _DexNo, int _Level, float _Hp, float _Atk, float _Def, float _SAtk, float _SDef, float _Spd);
	PokemonInfo SetIV(PokemonInfo _Pokemon, float _Hp, float _Atk, float _Def, float _SAtk, float _SDef, float _Spd);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	bool IsTrainer = false;
	std::list<PokemonInfo> Entry;

	UImageRenderer* CharacterIfDownRenderer;

	UCollision* BattlecheckDownCollision = nullptr;
	UCollision* BattlecheckUpCollision = nullptr;
	UCollision* BattlecheckLeftCollision = nullptr;
	UCollision* BattlecheckRightCollision = nullptr;
};

