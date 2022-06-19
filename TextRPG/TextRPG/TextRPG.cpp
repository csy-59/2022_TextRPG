﻿/*
* #####TEXT RPG: 가자, 집에#####
* >> 주인공은 다양한 능력치가 있다.
*	> 체력: 다 떨어지면 죽는다. (15)
*	> 공격력: 공격력 (3)
*	> 방어력: 방어력(주인공이 받는 데이지 : 공격력 - 데미지 * (1 + 스트레스 / 100)의 반올림) (0)
*	> 스트레스: 적에게 공격을 받거나, 전투를 진행하면 기본으로 얻는다. (0)
*		> 스트레스를 70 이상 받으면 사망한다.
*		> 기본으로 얻는 스트레스는 스테이지에 따라 다르다.
*			> 1 스테이지: 1
*			> 2 스테이지: 2
*			> 3 스테이지: 3
*		> 받은 공격력과 기존 체력에 비례하여 스트레스를 얻는다.
*			> 기존 체력 / 받은 공격력 >= 0.5f 스트레스 3 얻음
*									  >= 0.3f 스트레스 2 얻음
*									  이 외 스트레스를 1 얻음
* 
*	> 레벨: 레벨은 1~30까지 있으며, 레벨 30를 달성하면 게임 승리
*		> 경험치를 일정 개수 이상 쌓으면 레벨업을 한다.
* 
*		> 레벨업을 하면 능력치 포인트르 2씩 얻으며, 사용자의 마음에 따라 공격력, 방어력, 체력을 올릴 수 있다.
* 
*		> 레벨 10 단위로 스킬이 개방된다. 3가지 스킬 중 하나를 선택하여 얻을 수 있다.
*			> lev. 10: 쏠 수 있어!			(기본 공격력 * 2 의 공격을 한다. 스트레스가 2 오른다.)			(3)
*					   죽겠어요..			(스트레스가 10 줄어든다.)										(2)
*					   프로그래밍이란 무엇인가..(체력을 5 회복한다.)										(5)
* 
*			> lev. 20: 삼중나선문			(기본 공격력 * 3.5 의 공격을 한다. 스트레스가 3 오른다.)		(3/3)
*					   잘잤어, 실베스터?	(체력을 20 회복한다. 스트레스가 3 오른다.)						(3/3)
*					   음주 코딩 가즈아~	(기본 공격력 * (1 + 스트레스/100) 의 공격을 한다. 스트레스가 5 줄어든다)
*		> 레벨 증가에 필요한 양
*			> lev 1 ~ 10 : 10 + 다음 레벨 * 2
*			> lev 11 ~ 20 : 20 + 다음 레벨
*			> lev 21 ~ 30 : 30 + 다음 레벨 / 2
* 
* >> 스테이지는 3개가 있으며, 레벨을 10, 20을 달성하면 다음 스테이지로 이동할 수 있다.
*	> 각 스테이지에서 전투 후 레벨을 달성하면 자동으로 다음 스테이지로 이동한다.
*		> 레벨 30을 달성하면 주인공은 집에 도착하고 게임을 승리한다.
* 
*	> 스테이지 별로 마을과 숲이 있다.
*		> 마을: 스테이지 들어선 처음에만 들어간다. 물약을 살 수 있다.
*			> 몬스터: 스트레스를 1 오르게 한다. 체력을 1.7배로 회복한다. (15G)
*			> 한솥: 체력을 1.3배로 회복한다. 스트레스를 2 줄인다. (5G)
*			> NBB: 체력을 1.5배로 회복한다. 스트레스를 5 줄인다. (10G)
*		
*		> 숲: 전투를 진행한다. (후설)
*			> 전투를 3회 진행하면 회복의 연못에 도착한다. (무조건)
*				> 회복의 연못에 도착하면 스트레스가 10 줄어들고 체력을 1.5배로 회복한다.
* 
* >> 스테이지마다 다른 적이 나타나며, 적이 나타나면 배틀이 시작된다.
*	> Stage 1
*		> 이론몬: (플레이어 체력 * 0.4~0.5) (0.3 ~ 0.5 * 플레이어 기본 공격력, 최소 1) 사이의 공격. 10% 확률로 1G 드랍 
*			> 교수님의 기습 질문!
*			> 공격: 객체 지향적 프로그래밍은 뭐죠?
* 
*		> 졸음몬: (플레이어 체력 * 0.5~0.6) (0.2 ~ 0.4 * 플레이어 기본 공격력, 최소 1) 사이의 공격. 방어력 1. 10% 확률로 1G 드랍
*			> 포근한 침대 생각~
*			> 공격: 눕고 싶다...
* 
*		> Boss Git발몬: (플레이어 체력 * 1.2) (0.6 ~ 0.7 * 플레이어 기본 공격력, 최소 1) 사이의 공격.100% 확률로 30G 드랍
*			> 내가 사라져 볼께~
*			> 공격: 얍! 머지 컴플릭스~!
* 
*	> Stage 2
*		> 실습몬: (0.4 ~ 0.7 * 플레이어 기본 공격력, 최소 10) 사이의 공격. 8% 확률로 2G 드랍 
*			> 나는 바보다 히히
*			> 공격: ??: 라이브쉐어 들어오세요
* 
*		> 과식몬: (0.3 ~ 0.6 * 플레이어 기본 공격력, 최소 10) 사이의 공격. 플레이어 방어력의 반의 방어력. 8% 확률로 2G 드랍
*			> 식...곤...증....Zz...
*			> 공격: Zzz...
* 
*		> Boss 모듈몬:
*			> 응애 나 애기 함수
*			> 공격: 클라스로 진화...!! 하고 싶다.
* 
*	> Stage 3
*		> 테크톡몬: (0.5 ~ 0.8 * 플레이어 기본 공격력, 최소 20) 사이의 공격. 3% 확률로 한솥 드랍 
*			> 분명 어디서 봤는데....
*			> 공격: 포기하면 편한데 히히
* 
*		> 스터디몬: (0.5 ~ 0.8 * 플레이어 기본 공격력, 최소 20) 사이의 공격. 3% 확률로 한솥 드랍
*			> 아무래도 나는 비전공자는 아닌듯하다.
*			> 공격: 플립플롭! 플립플롭!
* 
*		> Boss 최선몬: (1~1.1 * 플레이어 기본 공격력, 최소 20) 사이의 공격. 플레이어와 동일한 방어력. 100% 확률로 집감
*			> 룰렛 돌리겠습니다.
*			> 공격: 테크톡 매일매일 하는 걸로 바꾸겠습니다.
* 
*   > 턴 마다 플레이어와 몬스터가 번갈아가며 공격한다.
*		> 몬스터는 기본 공격만 한다.
* 
* 
* >> 화면 구성
* [타이틀]
* #############
* ##  가자,  ##
* ##   집에  ##
* #############
* 1. Start ([마을]로)
* 2. How to Play([How to Play]로)
* 3. 나가기
* >> 
* ---------------------------------------------
* [How to Play]* 
* 
* ♥: 체력. 0이 되면 사망합니다.
* S: 스트레스. 스트레스가 높으면 더 높은 공격을 받습니다.
*	 스트레스가 70에 도달하면 사망합니다.
* 
* 게임 클리어 조건: 레벨이 30이 되면 게임 클리어!
* 
* 1.타이틀로
* >>
* ---------------------------------------------
* [마을]
* Stage 1             			
* Lev. 1		          10G
* ♥: 15/15		          S: 0/50
* 
*    시작의 마을이다...
*    무엇을 할까?
* 
* 1. 숲으로 향한다. ([숲]으로)
* 2. 상점으로 간다. ([상점]으로)
* 3. 상세 스탯을 확인한다.([스탯]으로)
* >> 
* ---------------------------------------------
* [상점]
* | 인밴토리: 한솥 X 0   NBB X 0   몬스터 X 0
* ※ 현재 소지금: 10G
* 
*   상점이다.
*   어떤 것을 살까?
* 
* 1. 한솥		(5G)
* 2. NBB		(10G)
* 3. 몬스터		(15G)
* 4. 돌아가기 ([마을]로)
* >>
* ---------------------------------------------
* [상점-선택시]
* | 인밴토리: 한솥 X 0   NBB X 0   몬스터 X 0
* 10G
*
*   몬스터를 선택했다.
*   정말로 구매할까?(구매 불가)
*
* | 몬스터: 체력 X 1.3, 스트레스 -2
* 1. 구매한다. (구매 불가 시 나오지 않는다.)
* 2. 구매 취소
* >>
* ----------------------------------------------
* [상세 스텟]
* | 스탯 확인
* 레벨: 1 (다음 레벨업까지... 12)
* 체력: 15/15
* 공격력: 3
* 방어력: 1
* 스트레스: 0/50
* 
* | 인밴토리
* 한솥 X 0
* NBB X 0
* 몬스터 X 0
* 
* 1. 돌아가기
* >>
* ----------------------------------------------
* [숲]
* Stage 1               Battle: 0
* Lev. 1				10G
* ♥: 15/15				S: 0/50
* 
*    숲에 들어왔다...
*    무엇을 할까?
* 
* 1. 몬스터와 싸운다. ([숲-전투]로)
* 2. 회복의 연못으로 향한다. (숲-회복의 우물로. 전투 3회시만 등장)
* 3. 상세 스탯을 확인한다.([스탯]으로)
* >>
* ----------------------------------------------
* [숲-회복의 우물]
* Lev. 1		          10G
* ♥: 15/15		          S: 0/50
* 
*   회복의 연못이다...
*	연못에 동전을 던졌다.
* 
* 1. 다음
* >>
* ----------------------------------------------
* [숲-회복의 우물]
* Lev. 1		          10G
* ♥: 15/15		          S: 0/50
* 
*   주변이 고요해진다...
*	집에 가고싶은 마음이 충만해졌다!
*	[ $ -10G		S -5]
* 
* 1. 다시 숲으로 걸어간다. ([숲]으로)
* >>
* ----------------------------------------------
* [숲-배틀]
* <(몬스터 이름)>			♥: 15/15
* 
*		(몬스터 이름)이 나타났다!
*		(몬스터 등장음)
* 
* | ♥: 15/15				S: 0/50
* 1. 공격한다.
* 2. 아이템을 사용한다.
* >>
* ----------------------------------------------
* [숲-배틀-공격한다.]
* <(몬스터 이름)>			♥: 15/15
* 
*		(몬스터 이름)이 나타났다!
*		(몬스터 등장음)
* 
* | ♥: 15/15				S: 0/50
* 1. 기본 공격
* 2. (1차 스킬 이름)	(n/n)
* 3. (2차 스킬 이름)	(n/n)
* >> 
* ----------------------------------------------
* [숲-배틀-공격한다-기본공격]
* <(몬스터 이름)>			♥: 15/15
* 
*		(몬스터 이름)을 공격했다!
*		[♥ -(몬스터가 받은 데미지)]
* 
* | ♥: 15/15				S: 0/50
* 1. 다음
* >>
* ----------------------------------------------
* [숲-배틀-공격한다-스킬(공격)]
* <(몬스터 이름)>			♥: 15/15
* 
*		(몬스터 이름)에게 적중했다!!
*		[♥ -(몬스터가 받은 데미지)]
* 
* | ♥: 15/15				S: 0/50
* 1. 몬스터가 공격해온다.
* >>
* ----------------------------------------------
* [숲-배틀-공격한다-스킬(유틸)]
* <(몬스터 이름)>			♥: 15/15
* 
*		가슴이 웅장해졌다.
*		[S -(감소량)]
* 
* | ♥: 15/15				S: 0/50
* 1. 다음
* >>
* ----------------------------------------------
* [숲-배틀-아이템 사용1]
* <(몬스터 이름)>			♥: 15/15
* 
*		(몬스터 이름)이 나타났다!
*		(몬스터 등장음)
* 
* | ♥: 15/15				S: 0/50
* 1. 한솥 X 0
* 2. NBB X 0
* 3. 몬스터 X 0
* 4. 돌아간다
* >>
* ----------------------------------------------
* [숲-배틀-아이템 사용2]
* <(몬스터 이름)>			♥: 15/15
* 
*		(아이템 이름)을/를 먹었다.
*		[ ♥ +(증가량)	S -(증감량)]
* 
* | ♥: 15/15				S: 0/50
* 1. 몬스터가 공격해온다.
* >>
* ----------------------------------------------
* [숲-배틀-몬스터 공격]
* <(몬스터 이름)>			♥: 15/15
* 
*		(몬스터 이름)이 공격했다!
*		(몬스터 공격 소음)
*		[ ♥ -(감소량)	S +(증가량)]
* 
* | ♥: 15/15				S: 0/50
* 1. 다음
* >>
* ----------------------------------------------
* [숲-배틀-배틀 승리]
* <(몬스터 이름)>			♥: 0/15
* 
*		(몬스터 이름)의 라이프가 0이 되었다!
*		승리했다!
*		[ +(얻은 골드량)]
* 
* | ♥: 15/15				S: 0/50
* 1. 숲으로 돌아간다.
* >>
* ----------------------------------------------
* [숲-배틀-배틀 패배-체력 감소]
* 
*		나의 라이프가 0이 되었다...
*		집에 가지 못했다...
* 
* | ♥: 0/15				S: 0/50
* 1. Game Over
* >>
* ----------------------------------------------
* [숲-배틀-배틀 패배-스트레스 만땅]
* 
*		과도한 스트레스로 요절했다...
*		집에도 가지 못했다...
* 
* | ♥: 15/15				S: 50/50
* 1. Game Over
* >>
* ----------------------------------------------
* [레벨업]
* Lev. 1		          10G
* ♥: 15/15		          S: 0/50
* 
*		지식이 늘었다!!
*		집과 가까워진다!!
*		[ 스탯 포인트 +2 ]
* 
* | ♥: 15/15				S: 50/50
* 1. 다음
* >>
* ----------------------------------------------
* [레벨업-스탯 포인트 사용]
* Lev. 1		          10G
* ♥: 15/15		          S: 0/50
* 
* 
*		어디에 스탯 포인트를 사용할까
*		[ 사용 후 남은 포인트: 1 ]
* 
* | ♥: 15/15				S: 50/50
* | A: 2					D: 1
* 1. 체력
* 2. 공격력
* 3. 방어력
* >>
* ----------------------------------------------
* [레벨업-다음 스테이지]
* Lev. 1		          10G
* ♥: 15/15		          S: 0/50
* 
*		레벨 (레벨)에 도달했다!
*		어떤 스킬을 얻을까?
* 
* 1. 쏠 수 있어!
* 2. 죽겠어요...
* 3. 몰?루
* >> 
* ----------------------------------------------
* [레벨업-다음 스테이지]
* Lev. 1		          10G
* ♥: 15/15		          S: 0/50
* 
*		쏠 수 있어! 스킬을 얻을까?
* 
* | S +2		A x2
* 1. 이 스킬을 얻는다.
* 2. 다시 생각해본다.
* >> 
* ----------------------------------------------
* [레벨업-게임 승리]
* Lev. 1		          10G
* ♥: 15/15		          S: 0/50
* 
*		레벨 30에 도달했다!
*		드디어 집에 도착했다!
* 
* | ♥: 15/15				S: 50/50
* 1. 다음
* >>
* ----------------------------------------------
* [게임 엔딩]
* ##############################
* 
*		Game Clear!!
*		Home, Sweat Home...
* 
* ##############################
* ----------------------------------------------
*/