#include "BattleHelper.h"
#include <cmath>
#include <EngineBase\EngineRandom.h>

bool BattleHelper::IsSwitch = false;

EUseBall BattleHelper::UseBall = EUseBall::None;

BattleHelper::BattleHelper()
{
}

BattleHelper::~BattleHelper()
{
}

int BattleHelper::CalDamage(EPSMove _Category, bool _AccCheck, int _CriCheck, int _ALevel, int _AAtk, int _ASAtk, EType _AType1, EType _AType2, int _DDef, int _DSDef, EType _DType1, EType _DType2, int _MPower, EType _MType)
{
	float ALevel = static_cast<float>(_ALevel);
	float AAtk = static_cast<float>(_AAtk);
	float ASAtk = static_cast<float>(_ASAtk);
	float DDef = static_cast<float>(_DDef);
	float DSDef = static_cast<float>(_DSDef);
	float MPower = static_cast<float>(_MPower);

	int FinalDmg = 1;
	if (true == _AccCheck)
	{
		float CriDmg = 1.0f;
		if (1 == _CriCheck)
		{
			CriDmg = 2.0f;
		}

		float ATypeDmg = 1.0f;
		if (_AType1 == _MType || _AType2 == _MType)
		{
			ATypeDmg = 1.5f;
		}

		float DTypeDmg1 = CalTypeRelationshipDmg(_MType, _DType1);

		float DTypeDmg2 = CalTypeRelationshipDmg(_MType, _DType2);

		if (EPSMove::물리 == _Category)
		{
			FinalDmg = std::lround(std::floor((((std::floor(std::floor((std::floor(ALevel * 2.0f / 5.0f) + 2.0f) * MPower * AAtk / 50.0f) / DDef) + 2.0f) * CriDmg) * ATypeDmg * DTypeDmg1 * DTypeDmg2 * std::floor(UEngineRandom::MainRandom.RandomFloat(217, 255) * 100 / 255)) / 100));
		}
		else if (EPSMove::특수 == _Category)
		{
			FinalDmg = std::lround(std::floor((((std::floor(std::floor((std::floor(ALevel * 2.0f / 5.0f) + 2.0f) * MPower * ASAtk / 50.0f) / DSDef) + 2.0f) * CriDmg) * ATypeDmg * DTypeDmg1 * DTypeDmg2 * std::floor(UEngineRandom::MainRandom.RandomFloat(217, 255) * 100 / 255)) / 100));
		}

		if (FinalDmg <= 0)
		{
			if (0.0f == DTypeDmg1 || 0.0f == DTypeDmg2)
			{
				FinalDmg = 0;
			}
			else
			{
				FinalDmg = 1;
			}
		}
	}
	else
	{
		FinalDmg = 0;
	}
	
	return FinalDmg;
}

float BattleHelper::CalTypeRelationshipDmg(EType _MType, EType _DType)
{
	switch (_MType)
	{
	case EType::노말:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 0.5f;
		case EType::고스트:
			return 0.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::불꽃:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 0.5f;
		case EType::물:
			return 0.5f;
		case EType::풀:
			return 2.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 2.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 2.f;
		case EType::바위:
			return 0.5f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 0.5f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 2.f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::물:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 2.f;
		case EType::물:
			return 0.5f;
		case EType::풀:
			return 0.5f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 2.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 2.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 0.5f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 1.f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::풀:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 0.5f;
		case EType::물:
			return 2.f;
		case EType::풀:
			return 0.5f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 0.5f;
		case EType::땅:
			return 2.f;
		case EType::비행:
			return 0.5f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 0.5f;
		case EType::바위:
			return 2.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 0.5f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::전기:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 2.f;
		case EType::풀:
			return 0.5f;
		case EType::전기:
			return 0.5f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 0.f;
		case EType::비행:
			return 2.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 0.5f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 1.f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::얼음:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 0.5f;
		case EType::물:
			return 0.5f;
		case EType::풀:
			return 2.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 0.5f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 2.f;
		case EType::비행:
			return 2.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 2.f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::격투:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 2.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 2.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 0.5f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 0.5f;
		case EType::에스퍼:
			return 0.5f;
		case EType::벌레:
			return 0.5f;
		case EType::바위:
			return 2.f;
		case EType::고스트:
			return 0.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 2.f;
		case EType::강철:
			return 2.f;
		case EType::페어리:
			return 0.5f;
		default:
			break;
		}
		break;
	case EType::독:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 2.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 0.5f;
		case EType::땅:
			return 0.5f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 0.5f;
		case EType::고스트:
			return 0.5f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 0.f;
		case EType::페어리:
			return 2.f;
		default:
			break;
		}
		break;
	case EType::땅:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 2.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 0.5f;
		case EType::전기:
			return 2.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 2.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 0.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 0.5f;
		case EType::바위:
			return 2.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 2.f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::비행:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 2.f;
		case EType::전기:
			return 0.5f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 2.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 2.f;
		case EType::바위:
			return 0.5f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::에스퍼:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 2.f;
		case EType::독:
			return 2.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 0.5f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 0.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::벌레:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 0.5f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 2.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 0.5f;
		case EType::독:
			return 0.5f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 0.5f;
		case EType::에스퍼:
			return 2.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 0.5f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 2.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 0.5f;
		default:
			break;
		}
		break;
	case EType::바위:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 2.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 2.f;
		case EType::격투:
			return 0.5f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 0.5f;
		case EType::비행:
			return 2.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 2.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::고스트:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 0.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 2.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 2.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 0.5f;
		case EType::강철:
			return 1.f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	case EType::드래곤:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 2.f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 0.f;
		default:
			break;
		}
		break;
	case EType::악:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 1.f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 0.5f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 2.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 2.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 0.5f;
		case EType::강철:
			return 1.f;
		case EType::페어리:
			return 0.5f;
		default:
			break;
		}
		break;
	case EType::강철:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 0.5f;
		case EType::물:
			return 0.5f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 0.5f;
		case EType::얼음:
			return 2.f;
		case EType::격투:
			return 1.f;
		case EType::독:
			return 1.f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 2.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 1.f;
		case EType::악:
			return 1.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 2.f;
		default:
			break;
		}
		break;
	case EType::페어리:
		switch (_DType)
		{
		case EType::None:
			return 1.f;
		case EType::노말:
			return 1.f;
		case EType::불꽃:
			return 0.5f;
		case EType::물:
			return 1.f;
		case EType::풀:
			return 1.f;
		case EType::전기:
			return 1.f;
		case EType::얼음:
			return 1.f;
		case EType::격투:
			return 2.f;
		case EType::독:
			return 0.5f;
		case EType::땅:
			return 1.f;
		case EType::비행:
			return 1.f;
		case EType::에스퍼:
			return 1.f;
		case EType::벌레:
			return 1.f;
		case EType::바위:
			return 1.f;
		case EType::고스트:
			return 1.f;
		case EType::드래곤:
			return 2.f;
		case EType::악:
			return 2.f;
		case EType::강철:
			return 0.5f;
		case EType::페어리:
			return 1.f;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

int BattleHelper::CalExp(int _EnemyLevel, EEnemyCategory _EnemyCategory)
{
	int Level2 = _EnemyLevel * _EnemyLevel;

	switch (_EnemyCategory)
	{
	case EEnemyCategory::Wild:
		return std::ceil(static_cast<float>(Level2) * 2.5f * 1.0f);
	case EEnemyCategory::Trainer:
		return std::ceil(static_cast<float>(Level2) * 2.5f * 1.5f);
	default:
		break;
	}
}