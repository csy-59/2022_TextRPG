#pragma once
#include <string>

class Scene
{
public:
	//씬의 타입
	enum SceneType
	{
		SCENE_MAIN,
		SCENE_HOWTOPLAY,
		SCENE_TOWN,
		SCENE_STAT,
		SCENE_STORE,
		SCENE_BATTLE,
		SCENE_HEALING,
		SCENE_MAX,
		SCENE_EXIT,
		SCENE_ERROR
	}; 

public:
	//생성자와 소멸자
	Scene() = default;
	Scene(const Scene&) = default;
	Scene& operator=(const Scene&) = default;
	~Scene() = default;

	//getter
	int GetOptionCount();

	/// <summary>
	/// 화면을 구성한다
	/// </summary>
	virtual void Render() const;

	/// <summary>
	/// 입력에 따라 원하는 연산을 진행한다
	/// </summary>
	/// <param name="input">입력값</param>
	/// <returns>다음 씬의 넘버를 넘긴다(SceneType 열거형이다)</returns>
	virtual enum SceneType Update(int input);

protected:
	//옵션 출력
	virtual void printOptions() const;

	//setter
	void SetOptionCount(int optionCount);

private:
	//선택지
	int _optionCount;		//선택지 개수
};