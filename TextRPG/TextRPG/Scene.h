#pragma once

class Scene
{
public:
	//���� Ÿ��
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
		SCENE_NOCHANGE,
		SCENE_ERROR	//��ġ ���� ���� ���� ���(ex. 1~2�� ������, �Է�: 5)
	}; 

public:
	//�����ڿ� �Ҹ���
	Scene() = default;
	Scene(const Scene&) = default;
	Scene& operator=(const Scene&) = default;
	~Scene() = default;

	/// <summary>
	/// ȭ���� �����Ѵ�
	/// </summary>
	virtual void Render() const;

	/// <summary>
	/// �Է¿� ���� ���ϴ� ������ �����Ѵ�
	/// </summary>
	/// <param name="input">�Է°�</param>
	/// <returns>���� ���� �ѹ��� �ѱ��(SceneType �������̴�)</returns>
	virtual enum SceneType Update(int input);

protected:
	//�ɼ� ���
	virtual void printOptions() const;

	//setter
	void SetOptionCount(int optionCount);

private:
	//������
	int _optionCount = 0;		//������ ����
};