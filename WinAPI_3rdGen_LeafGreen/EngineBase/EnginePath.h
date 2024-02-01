#pragma once
#include <string>
#include <filesystem> 

// 설명 : 파일 경로의 편집과 이동 등등을 처리한다.
class UEnginePath
{
public:
	// constrcuter destructer
	UEnginePath();
	UEnginePath(std::filesystem::path _Path);
	~UEnginePath();

	//// delete Function
	//UEnginePath(const UEnginePath& _Other) = delete;
	//UEnginePath(UEnginePath&& _Other) noexcept = delete;
	//UEnginePath& operator=(const UEnginePath& _Other) = delete;
	//UEnginePath& operator=(UEnginePath&& _Other) noexcept = delete;

	// 파일 경로인지 확인
	bool IsFile();
	bool IsDirectory();

	bool IsExists();

	std::string GetFileName();
	std::string GetExtension();

	void MoveParent();
	void Move(std::string_view _Path);

	std::string GetFullPath()
	{ 
		return Path.string();
	}

protected:
	std::filesystem::path Path;

private:
};

