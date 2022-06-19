#pragma once

class Scene
{
public:
	//���� Ÿ��
	enum SceneType
	{
		SCENE_MAIN,			//���� ȭ��
		SCENE_HOWTOPLAY,	//How to Play ȭ��

		SCENE_TOWN,			//���� ȭ��
		SCENE_STORE,		//���� ȭ��
		SCENE_FOREST,		//�� ȭ��
		SCENE_BATTLE,		//���� ȭ��
		SCENE_STAT,			//���� ǥ�� ȭ��

		SCENE_ENDING,		//���� ȭ��
		SCENE_MAX,			//���� ��	

		SCENE_EXIT,			//���� ������
		SCENE_NOCHANGE,		//���� ��ȯ ����
		SCENE_ERROR			//��ġ ���� ���� ���� ���(ex. 1~2�� ������, �Է�: 5)
	}; 

public:
	//�����ڿ� �Ҹ���
	Scene() = default;
	Scene(const Scene&) = default;
	Scene& operator=(const Scene&) = default;
	~Scene() = default;

	/// <summary>
	/// �� ��ó��
	/// </summary>
	virtual void Init();

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