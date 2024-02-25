#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

class Player
{
public:
    Player() {}
    Player(int id) : _id(id) { }

public:
    int _id = 0;
};

int main()
{
    vector<Player*> v;
    v.push_back(new Player(100));
    v.push_back(new Player(200));
    v.push_back(new Player(500));
    v.push_back(new Player(300));
    v.push_back(new Player(400));

    ///////////////////////////////////////////////////
    // map
    
    //(key, value) 형태로 값을 저장함
    // R-B tree 구조로 정렬이 되어 저장된다.
    map<int, Player*> m;

    // 추가
    for (Player* player : v)
    {
        m.insert(make_pair(player->_id, player));
    }

    // 찾기
    //map<int, Player*>::iterator it = m.find(300);
    auto it = m.find(300);      // O(logN)
    if (it != m.end())
    {
        //auto whoami = *it;
        //whoami.first;
        //whoami.second;
    
        //int key = (*it).first;
        //Player* value = (*it).second;

        int key = it->first;
        Player* value = it->second;
        cout << "찾음" << endl;
    }
    else
    {
        cout << "없음" << endl;
    }

    // 맵에서 이런식으로 하면 100이라는 키값을 가진 값을 가져와 주세요 라는 뜻
    m[100];
    // 조심해야하는 것은 없는 키 값을 넣을 경우
    // C++ STL 에서는 새로운 키 값이 생성되어 들어간다. 
    // UE TMap 에서는 해당 키 값이 없다고 크래시가 난다.
    Player* p = m[1000];
   
    // 삭제
    // m.erase(it);
    m.erase(200);

    // 순회  
    // 맵은 순회시에는 큰 장점이 없다.
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int key = it->first;
        Player* p = it->second;
    }


    ///////////////////////////////////////////////////
    // hash_map
    
    // 메모리를 팔아서 (CPU) 성능을 얻겠다.
    // 예) 아파트 우편함
    // [201][202][203][204][205]
    // [101][102][103][104][105]
    // O(1)

    // 만약 유저가 1~999 까지 있다고 가정
    // [1][2][3]...[999]

    // 즉 키를 알면 상수시간만에 찾을 수 있다.

    // 메모리를 무제한으로 할당할 수 없기 때문에, 특별한 방법을 사용한다.
    // hash 기법

    // 찾기
    // O(1) : 최악의 경우가 아닌 경우(매번 겹쳐서 데이터가 다 한곳에 몰리는 경우가 아닌경우)

    unordered_map<int, int> um;

    // 추가
    um.insert(make_pair(10, 100));
    // um[20] = 200;        // 해당 키 값이 없으면 추가되는 로직

    // 찾기
    auto findIt = um.find(10);
    if (findIt != um.end())
    {
        cout << "찾음" << endl;
    }
    else 
    {
        cout << "없음" << endl;
    }

    // 삭제
    um.erase(10);
    // um.erase(findIt);
    
    // 순회
    for (auto it = um.begin(); it != um.end(); it++)
    {
        int key = it->first;
        int value = it->second;
    }

}
