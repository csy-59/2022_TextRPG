#pragma once

class Scene
{
public:
	//씬의 타입
	enum SceneType
	{
		SCENE_MAIN,			//메인 화면
		SCENE_HOWTOPLAY,	//How to Play 화면

		SCENE_TOWN,			//마을 화면
		SCENE_STORE,		//상점 화면
		SCENE_FOREST,		//숲 화면
		SCENE_BATTLE,		//전투 화면
		SCENE_STAT,			//상태 표시 화면

		SCENE_ENDING,		//엔딩 화면
		SCENE_MAX,			//씬의 끝	

		SCENE_EXIT,			//게임 끝내기
		SCENE_NOCHANGE,		//씬이 전환 없음
		SCENE_ERROR			//원치 않은 값이 들어온 경우(ex. 1~2의 선택지, 입력: 5)
	}; 

public:
	//생성자와 소멸자
	Scene() = default;
	Scene(const Scene&) = default;
	Scene& operator=(const Scene&) = default;
	~Scene() = default;

	/// <summary>
	/// 씬 전처리
	/// </summary>
	virtual void Init();

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
	int _optionCount = 0;		//선택지 개수
};